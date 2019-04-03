#include <Servo.h>
//#include "SCoop.h"

int IN3 = 8;
int IN4 = 7;
int motor2_enable = 3;
Servo myservo;
int LED = 2;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0



void setup()
{
  // set all the motor control pins to outputs
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(motor2_enable, OUTPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);//initialize
  myservo.attach(9); // pin, min, max
  Serial.begin(9600);
}

void loop()
{
  //design1();  // vent completely open
  design2(); // fan at a constant speed
}

void design1() // first requirement
{
  // open the vent completely by server motor
  myservo.write(35);
  
  float temperature = temperatureSensor();
  fanControl(temperature);
}

void design2()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(motor2_enable,100); // fan at a constant speed

  float temperature = temperatureSensor();
  servoControl(temperature);
}

float temperatureSensor()
{
  int a = analogRead(pinTempSensor);

  float R = 1023.0/a-1.0;
  R = R0*R;

  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  return temperature;
}

void servoControlOpen()
{
  //myservo.write(80);
  //delay(500);
  myservo.write(35);// open the vent
  //delay(500);
}

void servoControlClose()
{
  //myservo.write(80);
  //delay(500);
  myservo.write(130);//close the vent
  //delay(500);
}

void servoControl(float temperature)
{
  if(temperature >= 29){
    Serial.print("LED on!\n");
    digitalWrite(LED,HIGH);
    Serial.print("temperature = ");
    Serial.println(temperature);
    servoControlOpen(); //open vent when temperature higher than 27
  }
  else{
    Serial.print("LED off!\n");
    digitalWrite(LED,LOW);
    servoControlClose();
  }
}

void fanControl(float temperature)
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  //set IN3 and IN4 to HIGH and LOW for one direction 
  
  if(temperature >= 27 && temperature < 37){
    Serial.print("LED on!\n");
    digitalWrite(LED,HIGH);
    Serial.print("temperature = ");
    Serial.println(temperature);
    /*if(temperature <27){
      analogWrite(motor2_enable,80); // speed should be in range 0-255
    }*/
    if(temperature < 29 && temperature >=27){
      analogWrite(motor2_enable,70);
    }
    else if(temperature < 31 && temperature >= 29){
      analogWrite(motor2_enable,110);
    }
    else if(temperature < 33 && temperature >= 31){
      analogWrite(motor2_enable,150);
    }
    else if(temperature <35 && temperature >=33){
      analogWrite(motor2_enable,170);
    }
    else if(temperature <37 && temperature >=35){
      analogWrite(motor2_enable,190);
    } 
    // different temperature range correspond to different fan speed
  }

  else{
    Serial.print("LED off!\n");
    digitalWrite(LED,LOW);
    analogWrite(motor2_enable,0); // turn off the fan
  }
}
