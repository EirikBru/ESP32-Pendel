void printStuff(){
  // Theta_Pendel:
  Serial.print("Roll: ");
  Serial.print(roll, 3);
  Serial.print(" Pitch: ");
  Serial.print(pitch, 3);
  
  // Omega_Pendel:
  Serial.print("::  gX: ");
  Serial.print(gX, 3);
  Serial.print(" gY: ");
  Serial.print(gY, 3);
  
  // Theta_Hjul:
//  Serial.print("Pos_1: ");
//  Serial.print(wheelPos_1);
//  Serial.print("Pos_2: ");
//  Serial.print(wheelPos_2);
  
  // Omega_Hjul:
//  Serial.print(" Hastighet_1 (deg/s): ");
//  Serial.print(wheelSpeed_1 * (180/PI));
  Serial.print(" fW_1 (rad/s): ");
  Serial.print(filteredSpeed_1);
//  Serial.print("    Hastighet_2 (rad/s): ");
 // Serial.print(wheelSpeed_2);
  Serial.print(" fW_2 (rad/s): ");
  Serial.print(filteredSpeed_2);

  Serial.print(" u_1: ");
  Serial.print(u_1);
//  Serial.print(" I_prev_1: ");
//  Serial.print(I_prev_1);
  Serial.print(" u_2: ");
  Serial.print(u_2);
//  Serial.print(" I_prev_2: ");
//  Serial.print(I_prev_2);
  Serial.print(" I_1: "); 
  Serial.print(I_1);
  Serial.print(" I_2: "); 
  Serial.println(I_2);
}

 void deltaTime_calc(){
  unsigned long currentTime = millis();
  dt = (currentTime - previousTime) / 1000.0; // Delta tid i sekunder
  previousTime = currentTime;
}

int Tuning() {
  if (!Serial.available())  return 0;
  delay(2);
  char param = Serial.read();               // get parameter byte
  if (!Serial.available()) return 0;
  char cmd = Serial.read();                 // get command byte
  Serial.flush();
  switch (param) {
    case '1':
      if (cmd == '+')    k1 += 10;
      if (cmd == '-')    k1 -= 10;
      printValues();
      break;
    case '2':
      if (cmd == '+')    k2 += 5;
      if (cmd == '-')    k2 -= 5;
      printValues();
      break;
     case '3':
      if (cmd == '+')    k3 += 0.1;
      if (cmd == '-')    k3 -= 0.1;
      printValues();
      break;  
      case '4':
      if (cmd == '+')    k4 += 1;
      if (cmd == '-')    k4 -= 1;
      printValues();
      break;  
  }
}

void printValues() {
  Serial.print("k1: "); Serial.print(k1);
  Serial.print(" k2: "); Serial.print(k2);
  Serial.print(" k3: "); Serial.print(k3);  
  Serial.print(" k4: "); Serial.println(k3, 3);
}
