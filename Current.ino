float I_2 = 0;
float u_2 = 0;
float I_prev_2 = 0;
float dI_2 = 0;
float Ke = 0.017475;
float Ra = 5;
float La = 0.0625;
float n = 19.255;
float currentDt = 0;

void updateCurrent() {
    unsigned long currentCurrentTime = micros();

    if (prevCurrentTime > 0) {
        currentDt = (currentCurrentTime - prevCurrentTime) / 1000000.0;
        if (currentDt > 0) {
            I_2 = (u_2 - wheelSpeed_2 * Ke - La * (I_2 - I_prev_2) / currentDt) / Ra;
            I_prev_2 = I_2;
        }
    }
    prevCurrentTime = currentCurrentTime; // Oppdater tiden for neste iterasjon
}
