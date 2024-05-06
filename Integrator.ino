/*
 *  Dette er en integrator på ønsket hjulhastighet. som gjør det mulig å få korrekt
 *  reaksjonshjul hastighet over tid. Uten denne vil hjul ha en kostant hastighet som 
 *  kompanserer for offset (da denne sjelden er 100% riktig). Hvis offset hadde vært eksakt 0,
 *  ville hjulet stått helt i ro. Men dette muliggjør ønsket hjulhastighet som vil gå til eksakt dette
 *  når offset blir kompansert for. Som også muligjør at vekting (legge vekt på en av aksene) noe som er meget kult!
 */

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
