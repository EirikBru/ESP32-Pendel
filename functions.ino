
// Debug:
void printStuff(){
//  Serial.print(roll, 3);
//  Serial.print(";");
//  Serial.print(filteredSpeed_1);
//  Serial.print(";");
//  Serial.print(pitch, 3);
//  Serial.print(";");
//  Serial.print(filteredSpeed_2);
//  Serial.println();

  SerialBT.print("po: ");
  SerialBT.print(pitch, 5);
  SerialBT.print("   rO: ");
  SerialBT.println(roll, 5);
  
  
  // Theta_Pendel:
//  Serial.print("Roll: ");
//  Serial.print(roll, 3);
//  Serial.print(" Pitch: ");
//  Serial.print(pitch, 3);
  
  // Omega_Pendel:
//  Serial.print("  gX: ");
//  Serial.print(gX, 3);
//  Serial.print(" gY: ");
//  Serial.print(gY, 3);
  
  // Theta_Hjul:
//  Serial.print("Pos_1: ");
//  Serial.print(wheelPos_1);
//  Serial.print("Pos_2: ");
//  Serial.print(wheelPos_2);
  
  // Omega_Hjul:
//  Serial.print(" Hastighet_1 (deg/s): ");
//  Serial.print(wheelSpeed_1 * (180/PI));
//  Serial.print(" fW_1 (rad/s): ");
//  Serial.print(";");
//  Serial.print(filteredSpeed_1);
//  Serial.print("    Hastighet_2 (rad/s): ");
//  Serial.print(wheelSpeed_2);
//  Serial.print(" fW_2 (rad/s): ");
//  Serial.print(filteredSpeed_2);

//  Serial.print(" int_1: ");
//  Serial.print(integralSpeedError_1);
//  Serial.print(" int_2: ");
//  Serial.print(integralSpeedError_2);
  

//  Serial.print(" u_1: ");
//  Serial.print(u_1);
//  Serial.print(" I_prev_1: ");
//  Serial.print(I_prev_1);
//  Serial.print(" u_2: ");
//  Serial.print(u_2);
//  Serial.print(" I_prev_2: ");
//  Serial.print(I_prev_2);
//  Serial.print(" I_1: "); 
//  Serial.print(I_1);
//  Serial.print(" I_2: "); 
//  Serial.print(I_2);

   if(vertical) {
//    Serial.println(" vertical is true");
  } else {
//    Serial.println(" vertical is false");
  }
  
}

 void deltaTime_calc(){
  unsigned long currentTime = millis();
  dt = (currentTime - previousTime) / 1000.0; // Delta tid i sekunder
  previousTime = currentTime;
}

void verticalCheck(){
  float threshold = 0.2
  ; // radianer
  float startProgram = 0.03;
  if( pitch > threshold || pitch < -threshold || roll > threshold || roll < -threshold ){
    vertical = false;
    integratorReset();
  }
  else if( pitch < startProgram && pitch > -startProgram && roll < startProgram && roll > -startProgram){
    vertical = true; 
  }
}

unsigned long previousMillis = 0;

void variableSetpoint(){
  if(variableSet == true){
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 10000) {
      previousMillis = currentMillis;
      if (desiredSpeed == -30) {
        desiredSpeed = 30;
      } else {
        desiredSpeed = -30;
      }
    }
  }
}
