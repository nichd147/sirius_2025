const int switchPin = 2;
const int motorPin = 9;
int swithState = 0;
int pwm = 0;
bool up = true;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  swithState = digitalRead(switchPin);
  if (swithState == HIGH) {
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
    // digitalWrite(motorPin, HIGH);

  } else {
    // digitalWrite(motorPin, LOW);
    pwm = 0;
  }
  Serial.print("pwm=");
  Serial.println(pwm);
  analogWrite(motorPin, pwm);
}
