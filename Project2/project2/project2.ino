#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"
//#include "SCoop.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 0;
int number = 2000;
int count;

Servo servo1;
Servo servo2;
Servo servo3;
int greenLED = 13;
int collisionSensorState1 = 0;
int collisionSensorState2 = 0;
int collisionSensorState3 = 0;
int collisionSensorState4 = 0;
int collisionSensorState5 = 0;
int collisionSensor1 = 31;
int collisionSensor2 = 32;
int collisionSensor3 = 33;
int collisionSensor4 = 34;
int collisionSensor5 = 35;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  pinMode(greenLED, OUTPUT);
  digitalWrite(greenLED, LOW);

  count = 0; // initialzie the points
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.setCursor(0, 0);
  lcd.print("Welcome !");
}

void loop() {
  if(count <= 5){
    level_one();
  }// points less than 500
  else if(count > 5 && count <= 10){
    level_two();
  }// point bigger than 500 and less than 1000
  else if(count > 10){
    level_three();
  }
}


void level_one()
{
  level_One_ServoMotor();
  testCollisionSensor();
  testLCD();
}

void level_two()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LEVEL 2 !");
  testCollisionSensor();
  testLCD();
  level_Two_ServoMotor();
}

void level_three()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LEVEL 3 !");
  testCollisionSensor();
  testLCD();
  level_Three_ServoMotor();
}

void testLCD()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(count * 100);
  delay(100);
}

void testCollisionSensor()
{
  collisionSensorState1 = digitalRead(collisionSensor1);
  collisionSensorState2 = digitalRead(collisionSensor2);
  collisionSensorState3 = digitalRead(collisionSensor3);
  collisionSensorState4 = digitalRead(collisionSensor4);
  collisionSensorState5 = digitalRead(collisionSensor5);
  if ((collisionSensorState1 == 1) || (collisionSensorState2 == 1) || (collisionSensorState3 == 1) || (collisionSensorState4 == 1) || (collisionSensorState5 == 1)) {
    digitalWrite(greenLED, HIGH);
    count++;
  }
  else {
    digitalWrite(greenLED, LOW);
  }
  collisionSensorState1 = 0;
  collisionSensorState2 = 0;
  collisionSensorState3 = 0;
  collisionSensorState4 = 0;
  collisionSensorState5 = 0;
}

void level_One_ServoMotor()
{
  servo1.write(0);
  servo2.write(35);
  servo3.write(35); // structure stay at the orginal location
}

void level_Two_ServoMotor()
{
  servo1.write(0);
  servo2.write(35);
  servo3.write(35);
  testCollisionSensor();
  testLCD();
  delay(700);
  servo1.write(15);
  servo2.write(50);
  servo3.write(50);
  testCollisionSensor();
  testLCD();
  delay(700); 
  /*servo1.write(30);
  servo2.write(65);
  servo3.write(65);
  delay(1000); 
  servo1.write(45);
  servo2.write(80);
  servo3.write(80);
  delay(1000); 
  //switch back
  servo1.write(30);
  servo2.write(65);
  servo3.write(65);
  delay(1000); 
  servo1.write(15);
  servo2.write(50);
  servo3.write(50);
  delay(1000); 
  servo1.write(0);
  servo2.write(35);
  servo3.write(35);
  delay(1000);*/
  // structure start to move
}

void level_Three_ServoMotor()
{
  servo1.write(0);
  servo2.write(35);
  servo3.write(35);
  testCollisionSensor();
  testLCD();
  delay(500);
  servo1.write(15);
  servo2.write(50);
  servo3.write(50);
  testCollisionSensor();
  testLCD();
  delay(500); 
  /*servo1.write(30);
  servo2.write(65);
  servo3.write(65);
  /*delay(500); 
  servo1.write(45);
  servo2.write(80);
  servo3.write(80);
  delay(500); 
  //switch back
  servo1.write(30);
  servo2.write(65);
  servo3.write(65);
  delay(500); 
  servo1.write(15);
  servo2.write(50);
  servo3.write(50);
  delay(500); 
  servo1.write(0);
  servo2.write(35);
  servo3.write(35);
  delay(500);*/
  // structure move faster
}
