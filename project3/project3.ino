int chairState;

int button = 6;
int buttonState;

int pressSensor = A8;

int smDirectionPin1 = 24; //Direction pin
int smStepPin1 = 26; //Stepper pin
int smEnablePin1 = 22; //Motor enable pin

int smDirectionPin2 = 32; //Direction pin
int smStepPin2 = 30; //Stepper pin
int smEnablePin2 = 28; //Motor enable pin

int smDirectionPin3 = 34; //Direction pin
int smStepPin3 = 36; //Stepper pin
int smEnablePin3 = 38; //Motor enable pin

int smDirectionPin4 = 40; //Direction pin
int smStepPin4 = 42; //Stepper pin
int smEnablePin4 = 44; //Motor enable pin
 
void setup(){
  pinMode(pressSensor, INPUT);

  pinMode(button, INPUT);
  buttonState = 0;
  /*Sets all pin to output; the microcontroller will send them(the pins) bits, it will not expect to receive any bits from thiese pins.*/
  pinMode(smDirectionPin1, OUTPUT);
  pinMode(smStepPin1, OUTPUT);
  pinMode(smEnablePin1, OUTPUT);
  digitalWrite(smEnablePin1, HIGH); //Disbales the motor, so it can rest untill it is called uppond

  pinMode(smDirectionPin2, OUTPUT);
  pinMode(smStepPin2, OUTPUT);
  pinMode(smEnablePin2, OUTPUT);
  digitalWrite(smEnablePin2, HIGH); //Disbales the motor, so it can rest untill it is called uppond

  pinMode(smDirectionPin3, OUTPUT);
  pinMode(smStepPin3, OUTPUT);
  pinMode(smEnablePin3, OUTPUT);
  digitalWrite(smEnablePin3, HIGH); //Disbales the motor, so it can rest untill it is called uppond

  pinMode(smDirectionPin4, OUTPUT);
  pinMode(smStepPin4, OUTPUT);
  pinMode(smEnablePin4, OUTPUT);
  digitalWrite(smEnablePin4, HIGH); //Disbales the motor, so it can rest untill it is called uppond
  Serial.begin(9600);

  initialResetChair();// anyway transform to sit case
}
 
void loop(){
  //moveUpAndDown1(-3000, 0.5); 
  //moveUpAndDown2(3000, 0.5); 
  buttonLiftChair();
  pressDownChair();
}

void pressDownChair()
{
  //press sensor only work in stand case
  if(chairState == 1){
    if(analogRead(pressSensor) > 10){
      resetChair();
    }
  }
}

void buttonLiftChair()
{
  //lift the chair up
  buttonState = digitalRead(button);
  if(buttonState == 1){
    chairState = 1;// stand case
    for(int i = 0; i < 27; ++i){
      moveUpAndDown1(1000,0.5);
      moveUpAndDown2(1000,0.5);
      moveUpAndDown3(1000,0.5);
      moveUpAndDown4(1000,0.5);
    }
  }
  buttonState = 0;
}

void initialResetChair()
{
  chairState = 0; //back to sit case
  for(int i = 0; i < 27; ++i){
      moveUpAndDown1(-1000,0.5);
      moveUpAndDown2(-1000,0.5);
      moveUpAndDown3(-1000,0.5);
      moveUpAndDown4(-1000,0.5);
  }
}

void resetChair()
{
  if(chairState == 1){
    chairState = 0;// back to sit case
    //reset chair to the original position
    for(int i = 0; i < 27; ++i){
      moveUpAndDown1(-1000,0.5);
      moveUpAndDown2(-1000,0.5);
      moveUpAndDown3(-1000,0.5);
      moveUpAndDown4(-1000,0.5);
    }
  }
}
 
/*The rotate function turns the stepper motor. Tt accepts two arguments: 'steps' and 'speed'*/
void moveUpAndDown1(int steps, float speed){
  digitalWrite(smEnablePin1, LOW); //Enabling the motor, so it will move when asked to
  int direction;
 
  if (steps > 0){
    direction = HIGH;
  }else{
    direction = LOW;
  }
 
  speed = 1/speed * 70; //Calculating speed
  steps = abs(steps); //Stores the absolute value of the content in 'steps' back into the 'steps' variable
 
  digitalWrite(smDirectionPin1, direction); //Writes the direction (from our if statement above), to the EasyDriver DIR pin
 
  /*Steppin'*/
  for (int i = 0; i < steps; i++){
    digitalWrite(smStepPin1, HIGH);
    delayMicroseconds(speed);
    digitalWrite(smStepPin1, LOW);
    delayMicroseconds(speed);
  }
 
  digitalWrite(smEnablePin1, HIGH); //Disbales the motor, so it can rest untill the next time it is called uppond
}

void moveUpAndDown2(int steps, float speed){
  digitalWrite(smEnablePin2, LOW); //Enabling the motor, so it will move when asked to
  int direction;
 
  if (steps > 0){
    direction = HIGH;
  }else{
    direction = LOW;
  }
 
  speed = 1/speed * 70; //Calculating speed
  steps = abs(steps); //Stores the absolute value of the content in 'steps' back into the 'steps' variable
 
  digitalWrite(smDirectionPin2, direction); //Writes the direction (from our if statement above), to the EasyDriver DIR pin
 
  /*Steppin'*/
  for (int i = 0; i < steps; i++){
    digitalWrite(smStepPin2, HIGH);
    delayMicroseconds(speed);
    digitalWrite(smStepPin2, LOW);
    delayMicroseconds(speed);
  }
 
  digitalWrite(smEnablePin2, HIGH); //Disbales the motor, so it can rest untill the next time it is called uppond
}

void moveUpAndDown3(int steps, float speed){
  digitalWrite(smEnablePin3, LOW); //Enabling the motor, so it will move when asked to
  int direction;
 
  if (steps > 0){
    direction = HIGH;
  }else{
    direction = LOW;
  }
 
  speed = 1/speed * 70; //Calculating speed
  steps = abs(steps); //Stores the absolute value of the content in 'steps' back into the 'steps' variable
 
  digitalWrite(smDirectionPin3, direction); //Writes the direction (from our if statement above), to the EasyDriver DIR pin
 
  /*Steppin'*/
  for (int i = 0; i < steps; i++){
    digitalWrite(smStepPin3, HIGH);
    delayMicroseconds(speed);
    digitalWrite(smStepPin3, LOW);
    delayMicroseconds(speed);
  }
 
  digitalWrite(smEnablePin3, HIGH); //Disbales the motor, so it can rest untill the next time it is called uppond
}

void moveUpAndDown4(int steps, float speed){
  digitalWrite(smEnablePin4, LOW); //Enabling the motor, so it will move when asked to
  int direction;
 
  if (steps > 0){
    direction = HIGH;
  }else{
    direction = LOW;
  }
 
  speed = 1/speed * 70; //Calculating speed
  steps = abs(steps); //Stores the absolute value of the content in 'steps' back into the 'steps' variable
 
  digitalWrite(smDirectionPin4, direction); //Writes the direction (from our if statement above), to the EasyDriver DIR pin
 
  /*Steppin'*/
  for (int i = 0; i < steps; i++){
    digitalWrite(smStepPin4, HIGH);
    delayMicroseconds(speed);
    digitalWrite(smStepPin4, LOW);
    delayMicroseconds(speed);
  }
 
  digitalWrite(smEnablePin4, HIGH); //Disbales the motor, so it can rest untill the next time it is called uppond
}
