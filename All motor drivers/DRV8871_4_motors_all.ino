// Basic sketch for trying out the DRV8871 Motor driver
// Motor 3 & 4 only rotates in one direction, does not have two PWM pins
int motor_IN1[4] = {3, 6, 2, 4};
int motor_IN2[4] = {5, 9, 10, 11};
int j = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("DRV8871 test");
  //TCCR1B = TCCR1B & 0b11111000 | 0x01;
  for(j = 0; j <= 3; j++)
  {
    pinMode(motor_IN1[j], OUTPUT);
    pinMode(motor_IN2[j], OUTPUT);
  }
  delay(100);
}

void loop() {

  // Motor number 1 + 2 + 3 + 4
  // ramp up forward
 for(j = 0; j <= 3; j++)
  { 
    digitalWrite(motor_IN1[j], LOW);  // Pins 3, 6, 2, 4 setting to LOW
  }
  for (int i=0; i<255; i++) {
    analogWrite(motor_IN2[0], i); //5
    analogWrite(motor_IN2[1], i); //9
    analogWrite(motor_IN2[2], i); //10
    analogWrite(motor_IN2[3], i); //11
    delay(50);
  }

  // forward full speed for 5 seconds
  delay(5000);
  
  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(motor_IN2[0], i); //5
    analogWrite(motor_IN2[1], i); //9
    analogWrite(motor_IN2[2], i); //10
    analogWrite(motor_IN2[3], i); //11
    delay(50);
  }

  // ramp up backward
  // 2 & 4 already set to LOW upwards
  digitalWrite(motor_IN2[0], LOW);  //5
  digitalWrite(motor_IN2[1], LOW);  //9
  for (int i=0; i<255; i++) {
    analogWrite(motor_IN1[0], i); //3
    analogWrite(motor_IN1[1], i); //6
    analogWrite(motor_IN2[2], i); //10
    analogWrite(motor_IN2[3], i); //11
    delay(50);
  }

  // backward full speed for 5 seconds
  delay(5000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(motor_IN1[0], i); //3
    analogWrite(motor_IN1[1], i); //6
    analogWrite(motor_IN2[2], i); //10
    analogWrite(motor_IN2[3], i); //11
    delay(50);
  }
}