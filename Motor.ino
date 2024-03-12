const int forewardPin_1 = 19;
const int backwardPin_1 = 18; 
const int forewardPin_2 = 27;
const int backwardPin_2 = 25;

const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int ledChannel3 = 2;
const int ledChannel4 = 3;
const int freq = 490;
const int resolution = 8;

int pwmMotor_1 = 0;
int pwmMotor_2 = 0;

void setupMotor(){
  pinMode(forewardPin_1, OUTPUT);
  pinMode(backwardPin_1, OUTPUT);
  pinMode(forewardPin_2, OUTPUT);
  pinMode(backwardPin_2, OUTPUT);

  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(forewardPin_1, ledChannel1);
  ledcSetup(ledChannel2, freq, resolution);
  ledcAttachPin(backwardPin_1, ledChannel2);
  ledcSetup(ledChannel3, freq, resolution);
  ledcAttachPin(forewardPin_2, ledChannel3);
  ledcSetup(ledChannel4, freq, resolution);
  ledcAttachPin(backwardPin_2, ledChannel4);
}

void motorControl_1() {
  u_1 = constrain(u_1, -255 + deadBand, 255 - deadBand);
  int pwmValue_1;
  if (u_1 < 0) {
    pwmValue_1 = -u_1 - deadBand;
    ledcWrite(ledChannel1, pwmValue_1);
    ledcWrite(ledChannel2, 0);
  }
  else if (u_1 > 0) {
    pwmValue_1 = u_1 + deadBand;
    ledcWrite(ledChannel1, 0);
    ledcWrite(ledChannel2, pwmValue_1);
  }
  else {
    ledcWrite(ledChannel1, 0);
    ledcWrite(ledChannel2, 0);
  }
}

void motorControl_2() {
  u_2 = constrain(u_2, -255 + deadBand, 255 - deadBand);
  int pwmValue_2;
  if (u_2 < 0) {
    pwmValue_2 = -u_2 - deadBand;
    ledcWrite(ledChannel3, pwmValue_2);
    ledcWrite(ledChannel4, 0);
  }
  else if (u_2 > 0) {
    pwmValue_2 = u_2 + deadBand;
    ledcWrite(ledChannel3, 0);
    ledcWrite(ledChannel4, pwmValue_2);
  }
  else {
    ledcWrite(ledChannel3, 0);
    ledcWrite(ledChannel4, 0);
  }
}
