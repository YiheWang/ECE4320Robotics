int button1 = 8;
int button2 = 9;
int solenoid1 = 12;
int solenoid2 = 11;
int buttonState1;
int buttonState2;


void setup() {
  // put your setup code here, to run once:
  pinMode(solenoid1, OUTPUT);
  pinMode(button1, INPUT);
  buttonState1 = 0;

  pinMode(solenoid2, OUTPUT);
  pinMode(button2, INPUT);
  buttonState2 = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(button1);
  if(buttonState1 == HIGH){
     digitalWrite(solenoid1, HIGH);      //Switch Solenoid ON                      
  }
  else if(buttonState1 == LOW){
    digitalWrite(solenoid1, LOW);  //Switch Solenoid OFF
  }
  buttonState1 = 0;

  buttonState2 = digitalRead(button2);
  if(buttonState2 == HIGH){
     digitalWrite(solenoid2, HIGH);      //Switch Solenoid ON                      
  }
  else if(buttonState2 == LOW){
    digitalWrite(solenoid2, LOW);  //Switch Solenoid OFF
  }
  buttonState2 = 0;
}
