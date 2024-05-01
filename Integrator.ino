void integratorUpdate(){
  float speedError_1 = desiredSpeed - filteredSpeed_1;
  float speedError_2 = -desiredSpeed - filteredSpeed_2;
  integralSpeedError_1 += speedError_1;
  integralSpeedError_2 += speedError_2;
}

void integratorReset(){
  integralSpeedError_1 = 0;
  integralSpeedError_2 = 0;
}
