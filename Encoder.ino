float alphaSpeed = 0.95; // (nærmere 0 = mindre filtrering)
unsigned long prevTime = 0;

// Encoder 1:
volatile long encoderTicks_1 = 0;
long prevEncoderTicks_1 = 0;
const int hallSensorPinA_1 = 35;
const int hallSensorPinB_1 = 34;
double wheelPos_1 = 0;

// Encoder 2:
volatile long encoderTicks_2 = 0;
long prevEncoderTicks_2 = 0;
const int hallSensorPinA_2 = 12;
const int hallSensorPinB_2 = 14;
float wheelPos_2 = 0;

void IRAM_ATTR encoderInterruptA_1() {
    if (digitalRead(hallSensorPinB_1) != digitalRead(hallSensorPinA_1)) {
        encoderTicks_1++;
    } else {
        encoderTicks_1--;
    }
}

void IRAM_ATTR encoderInterruptB_1() {
    if (digitalRead(hallSensorPinA_1) == digitalRead(hallSensorPinB_1)) {
        encoderTicks_1++;
    } else {
        encoderTicks_1--;
    }
}

void IRAM_ATTR encoderInterruptA_2() {
    if (digitalRead(hallSensorPinB_2) != digitalRead(hallSensorPinA_2)) {
        encoderTicks_2++;
    } else {
        encoderTicks_2--;
    }
}

void IRAM_ATTR encoderInterruptB_2() {
    if (digitalRead(hallSensorPinA_2) == digitalRead(hallSensorPinB_2)) {
        encoderTicks_2++;
    } else {
        encoderTicks_2--;
    }
}

void setupEncoder(){
  pinMode(hallSensorPinA_1, INPUT_PULLUP);
  pinMode(hallSensorPinB_1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hallSensorPinA_1), encoderInterruptA_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(hallSensorPinB_1), encoderInterruptB_1, CHANGE);
  pinMode(hallSensorPinA_2, INPUT_PULLUP);
  pinMode(hallSensorPinB_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hallSensorPinA_2), encoderInterruptA_2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(hallSensorPinB_2), encoderInterruptB_2, CHANGE);
}

void encoderCalc() {
    noInterrupts();
    long currentTicks_1 = encoderTicks_1;
    long currentTicks_2 = encoderTicks_2;
    unsigned long currTime = micros();
    interrupts();

    if(currTime - prevTime > 50){
    wheelPos_1 = currentTicks_1*(360/(n*12));
    long deltaTicks_1 = currentTicks_1 - prevEncoderTicks_1;

    wheelPos_2 = currentTicks_2*(360/(n*12));
    long deltaTicks_2 = currentTicks_2 - prevEncoderTicks_2;
    
    unsigned long deltaTime = currTime - prevTime;

    prevEncoderTicks_1 = currentTicks_1;
    prevEncoderTicks_2 = currentTicks_2;
    prevTime = currTime;

    double deltaRadians_1 = deltaTicks_1 * (2 * PI) / (n * 12);
    wheelSpeed_1 = deltaRadians_1 / (deltaTime / 1000000.0);
    
    double deltaRadians_2 = deltaTicks_2 * (2 * PI) / (n * 12);
    wheelSpeed_2 = deltaRadians_2 / (deltaTime / 1000000.0);
    
    // Exponential Moving Average, (EMA) Filter
    filteredSpeed_1 = alphaSpeed * filteredSpeed_1 + (1 - alphaSpeed) * wheelSpeed_1;
    filteredSpeed_2 = alphaSpeed * filteredSpeed_2 + (1 - alphaSpeed) * wheelSpeed_2;
    }
}
