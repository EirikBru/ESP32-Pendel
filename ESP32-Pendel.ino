#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// LQR Gain
float k1 = -379.2424;
float k2 = -84.3578;
float k3 = -0.6778;
float k4 = 0.5731;
float ki = 0.001;

float pO = -0.02; //pitch Offset
float rO = -0.01; //roll Offset 


/*
 * Variabler har ofte navn _1 og _2, dette representerer akse 1 og 2.
 * Altså motor 1 og motor 2, hjul 1 og hjul 2, etc.
 */


float integralSpeedError_1 = 0.0;
float integralSpeedError_2 = 0.0;
float desiredSpeed = 2;
bool variableSet = false;

float dt = 0;
float roll = 0, pitch = 0, gyroRoll = 0, gyroPitch = 0;
float gX = 0, gY = 0, gZ = 0;
float wheelSpeed_1 = 0;
float wheelSpeed_2 = 0;
static double filteredSpeed_1 = 0;
static double filteredSpeed_2 = 0;
int deadBand = 20;

unsigned long previousTime = 0;
unsigned long prevCurrentTime = 0;
bool vertical = false;

unsigned long sistTid = 0;

// Setter opp sensorer, serial, BT, etc:
void setup(void) {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Pendel_Home"); // Bluetooth navn
  setupMPU();
  setupEncoder();
  setupMotor();
  prevCurrentTime = micros();
}

// Dette er main loop som kjører på repeat:
void loop() {
  unsigned long current_dt_time = millis();

  // Oppdaterer sensorer og funksjoner:
  deltaTime_calc();
  imuCalc();
  encoderCalc();
  currentUpdate();
  integratorUpdate();
  bluetoothUpdate();
  verticalCheck();

  

  // LQR and motor oppdatering:
  variableSetpoint();
  lqrControl();
  motorControl_1();  
  motorControl_2();


  // mulighet for Debug Print hvert sekund:
  unsigned long tid = millis();
  if(tid - sistTid > 1000){
//    printStuff();
    sistTid = millis();
  }
}
