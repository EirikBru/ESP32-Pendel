void printStuff(){
  // Theta_Pendel:
//  Serial.print("Roll: ");
//  Serial.print(roll * (180/PI));
  Serial.print(" Pitch: ");
  Serial.print(pitch * (180/PI));
  
  // Omega_Pendel:
//  Serial.print("   gyroRoll: ");
//  Serial.print(filteredGyroRoll * (180/PI));
  Serial.print(" filteredgyroPitch: ");
  Serial.print(filteredGyroPitch * (180/PI));
  
  // Theta_Hjul:
//  Serial.print("Pos_1: ");
//  Serial.print(wheelPos_1);
//  Serial.print("Pos_2: ");
//  Serial.print(wheelPos_2);
  
  // Omega_Hjul:
//  Serial.print(" Hastighet_1 (deg/s): ");
//  Serial.println(wheelSpeed_1 * (180/PI));
//  Serial.print(filteredSpeed_1 * (180/PI));
  Serial.print("    Hastighet_2 (deg/s): ");
  Serial.print(wheelSpeed_2 * (180/PI));
//  Serial.println(filteredSpeed_2 * (180/PI));

  Serial.print(" u_2: ");
  Serial.print(u_2);
  Serial.print(" I_prev_2: ");
  Serial.print(I_prev_2);
  Serial.print(" I_2: "); 
  Serial.println(I_2);
}

 void deltaTime_calc(){
  unsigned long currentTime = millis();
  dt = (currentTime - previousTime) / 1000.0; // Delta tid i sekunder
  previousTime = currentTime;
}
