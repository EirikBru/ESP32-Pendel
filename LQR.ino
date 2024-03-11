float k1 = -400;
float k2 = -100;
float k3 = -1;
float k4 = 5;

void lqrControl(){
  u_2 = -(k1*pitch + k2*filteredGyroPitch + k3*wheelSpeed_2 + k4*I_2);
  u_2 = u_2 * 25;
  u_2 = constrain(u_2, -255 + deadBand, 255 - deadBand);
}
