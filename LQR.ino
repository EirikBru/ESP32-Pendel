float k1 = -400;
float k2 = -100;
float k3 = 1;
float k4 = 0;

void lqrControl(){
  
  u_1 = -(k1*(roll-0.045) + k2*(gX+0.03) + k3*filteredSpeed_1 + k4*I_1);
  u_1 = u_1 * 25;
  u_1 = constrain(u_1, -255 + deadBand, 255 - deadBand);

    
  u_2 = -(k1*(pitch+0.01) + k2*(gY+0.03) + k3*filteredSpeed_2 + k4*I_2);
  u_2 = u_2 * 25;
  u_2 = constrain(u_2, -255 + deadBand, 255 - deadBand);

}
