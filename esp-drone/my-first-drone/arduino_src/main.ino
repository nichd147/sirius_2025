// #include "esp32-hal-ledc.h"

const int frequency = 5000;
const int pwmChannel = 0;
const int resolution = 8;

const int motor1Pin = 15;
const int motor2Pin = 7;
const int motor3Pin = 40;
const int motor4Pin = 41;

uint32_t pwm = 0;
bool up = true;

void setup() {
  Serial.begin(115200);
  while(!Serial) delay(10);
  Serial.println("Hello World");

  ledcAttach(motor1Pin, frequency, resolution);



}

void ledcAnalogWrite(uint8_t pin, uint32_t value, uint32_t valueMax = 255) {
  // calculate duty, 4095 from 2 ^ 12 - 1
  // calculate duty, 256 from 2 ^ 8 - 1
  uint32_t duty = (255 / valueMax) * min(value, valueMax);

  // write duty to LEDC
  ledcWrite(pin, duty);
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
  
  ledcAnalogWrite(motor1Pin, pwm);
  // analogWrite(motor1Pin, pwm);
  // analogWrite(motor2Pin, pwm);
  // analogWrite(motor3Pin, pwm);
  // analogWrite(motor4Pin, pwm);
}
