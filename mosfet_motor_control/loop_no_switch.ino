const int motor1Pin = 11;
const int motor2Pin = 10;
const int motor3Pin = 9;
const int motor4Pin = 6;
int pwm = 0;
bool up = true;

void setup() {
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (pwm > 250) {
    up = false;
  } else if (pwm < 10) {
    up = true;
  }

  if (up) {
    pwm = pwm + 1;
  } else {
    pwm = pwm - 1;
  }

  Serial.print("pwm=");
  Serial.println(pwm);
  
  analogWrite(motor1Pin, pwm);
  analogWrite(motor2Pin, pwm);
  analogWrite(motor3Pin, pwm);
  analogWrite(motor4Pin, pwm);
}
