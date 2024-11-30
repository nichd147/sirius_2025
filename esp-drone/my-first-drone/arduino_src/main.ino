const int frequency = 5000;
const int pwmChannel = 0;
const int resolution = 8;

const int motor1Pin = 15;
const int motor2Pin = 7;
const int motor3Pin = 40;
const int motor4Pin = 41;

const int START_VALUE = 0;
const int MAX_VALUE = 255;

uint32_t pwm = 0;
bool up = true;
int incomingByte = 0;  // for incoming serial data

void ledcAnalogWrite(uint8_t pin, uint32_t value, uint32_t valueMax = MAX_VALUE) {
  // calculate duty, 4095 from 2 ^ 12 - 1
  // calculate duty, 256 from 2 ^ 8 - 1
  uint32_t duty = (256 / valueMax) * min(value, valueMax);
  ledcWrite(pin, duty);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  Serial.println("Hello World");

  ledcAttach(motor1Pin, frequency, resolution);  // setting up pin to work with pwm
  ledcAttach(motor2Pin, frequency, resolution);
  ledcAttach(motor3Pin, frequency, resolution);
  ledcAttach(motor4Pin, frequency, resolution);

  ledcAnalogWrite(motor1Pin, START_VALUE); // setting start value for motor. stop
  ledcAnalogWrite(motor2Pin, START_VALUE);
  ledcAnalogWrite(motor3Pin, START_VALUE);
  ledcAnalogWrite(motor4Pin, START_VALUE);
}


void loop() {
  if (Serial.available() > 0) { // manual control via entered integer
    // read the incoming byte:
    String str = Serial.readStringUntil('\n');
    pwm = str.toInt();
    // say what you got:
    Serial.print("\n");
    Serial.print("I received: ");
    Serial.println(pwm);
    if (pwm > MAX_VALUE) {
      pwm = MAX_VALUE;
    }

    ledcAnalogWrite(motor1Pin, pwm);
    ledcAnalogWrite(motor2Pin, pwm);
    ledcAnalogWrite(motor3Pin, pwm);
    ledcAnalogWrite(motor4Pin, pwm);
  }

  delay(100);
}
