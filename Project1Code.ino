#include <Servo.h> 

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
  myservo.attach(9, 600, 2300); // pin, min, max
  Serial.begin(9600);
}

void loop()
{
  design1();
  //design2();
  //temperatureSensor();
  //ventControl();
  //servoControl();
}

void design1() // first requirement
{
  // open the vent completely by server motor
  servoControlOpen();
  
  float temperature = temperatureSensor();
  fanControl(temperature);
}

float temperatureSensor()
{
  int a = analogRead(pinTempSensor);

  float R = 1023.0/a-1.0;
  R = R0*R;

  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

  /*Serial.print("temperature = ");
  Serial.println(temperature);

   delay(1000);*/
   return temperature;
}

void servoControlOpen()
{
  myservo.write(0);// open the vent
}

void servoControlClose()
{
  myservo.write(90);//close the vent
}

void fanControl(int temperature)
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  //set IN3 and IN4 to HIGH and LOW for one direction 
  if(temperature >= 25 && temperature < 37){
    Serial.print("LED on!");
    digitalWrite(LED,HIGH);
    if(temperature <27){
      analogWrite(motor2_enable,80); // speed should be in range 0-255
    }
    else if(temperature < 29 && temperature >=27){
      analogWrite(motor2_enable,100);
    }
    else if(temperature < 31 && temperature >= 29){
      analogWrite(motor2_enable,120);
    }
    else if(temperature < 33 && temperature >= 31){
      analogWrite(motor2_enable,140);
    }
    else if(temperature <35 && temperature >=33){
      analogWrite(motor2_enable,160);
    }
    else if(temperature <37 && temperature >=35){
      analogWrite(motor2_enable,180);
    } 
    // different temperature range correspond to different fan speed
  }

  else{
    Serial.print("LED off!");
    digitalWrite(LED,LOW);
    analogWrite(motor2_enable,0); // turn off the fan
  }
}
