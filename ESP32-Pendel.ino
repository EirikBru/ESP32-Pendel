#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

float dt = 0;
float roll = 0, pitch = 0, gyroRoll = 0, gyroPitch = 0;
float gX = 0, gY = 0, gZ = 0;
float wheelSpeed_2 = 0;
int deadBand = 40;
unsigned long previousTime = 0;
unsigned long prevCurrentTime = 0;

void setup(void) {
  Serial.begin(115200);
  setupMPU();
  setupEncoder();
  setupMotor();
  prevCurrentTime = micros();
}

void loop() {

  deltaTime_calc();
  imuCalc();
  encoderCalc();
  updateCurrent();
 
  lqrControl();
  motorControl_2();
  Tuning();

//  printStuff();
}
