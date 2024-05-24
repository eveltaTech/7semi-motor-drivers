// Basic sketch for trying out the DRV8871 Breakout with Arduino Uno/ Nano
// Motor 1 (PWM + direction)
#define MOTOR_IN1 3
#define MOTOR_IN2 5
// Motor 2 (PWM + direction)
#define MOTOR_IN3 6
#define MOTOR_IN4 9

void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  //TCCR1B = TCCR1B & 0b11111000 | 0x01;
  delay(100);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);

}

void loop() {
  // Motor number 1
  // ramp up forward
  digitalWrite(MOTOR_IN1, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN2, i);
    delay(50);
  }

  // forward full speed for five seconds
  delay(5000);
  
  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN2, i);
    delay(50);
  }

  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(50);
  }

  // backward full speed for five seconds
  delay(5000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(50);
  }
  //-------------------------------------------
  // Motor number 2
  // ramp up forward
  digitalWrite(MOTOR_IN3, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN4, i);
    delay(50);
  }

  // forward full speed for five seconds
  delay(5000);
  
  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN4, i);
    delay(50);
  }

  // ramp up backward
  digitalWrite(MOTOR_IN4, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN3, i);
    delay(50);
  }

  // backward full speed for five seconds
  delay(5000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN3, i);
    delay(50);
  }
  
  //---------------------------------------------
  // Motor number 1 + 2 
  // ramp up forward
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN3, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN2, i);
    analogWrite(MOTOR_IN4, i);
    delay(50);
  }

  // forward full speed for five seconds
  delay(5000);
  
  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN2, i);
    analogWrite(MOTOR_IN4, i);
    delay(50);
  }

  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  digitalWrite(MOTOR_IN4, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    analogWrite(MOTOR_IN3, i);
    delay(50);
  }

  // backward full speed for five seconds
  delay(5000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    analogWrite(MOTOR_IN3, i);
    delay(50);
  }
  
}

