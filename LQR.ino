/*
 * Selve kontroll algoritmen, denne kanger de forskjellige statene med gainmatrisen (K), her
 * bare laget som variabler k1 - k4 og ki.
 */


void lqrControl(){
  
  u_1 = -(k1*(roll+rO) + k2*(gX+0.023) + k3*filteredSpeed_1 + k4*I_1 + ki*integralSpeedError_1);
  u_1 = u_1 * 25;
  u_1 = constrain(u_1, -255 + deadBand, 255 - deadBand);

    
  u_2 = -(k1*(pitch+pO) + k2*(gY+0.028) + k3*filteredSpeed_2 + k4*I_2 + ki*integralSpeedError_2);
  u_2 = u_2 * 25;
  u_2 = constrain(u_2, -255 + deadBand, 255 - deadBand);

}
