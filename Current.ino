float I_1 = 0;
float I_2 = 0;
float u_1 = 0;
float u_2 = 0;
float I_prev_1 = 0;
float I_prev_2 = 0;
float dI_1 = 0;
float dI_2 = 0;
float Ke = 0.017475;
float Ra = 5;
float La = 0.0625;
float n = 19.255;
float currentDt = 0;

void currentUpdate() {
    unsigned long currentCurrentTime = micros();

    if (prevCurrentTime > 0) {
        currentDt = (currentCurrentTime - prevCurrentTime) / 1000000.0;
        if (currentDt > 0) {
            I_1 = ((u_2/25) - filteredSpeed_1 * Ke - La * (I_1 - I_prev_1) / currentDt) / Ra;
            I_2 = ((u_2/25) - filteredSpeed_2 * Ke - La * (I_2 - I_prev_2) / currentDt) / Ra;
            I_prev_1 = I_1;
            I_prev_2 = I_2;
        }
    }
    prevCurrentTime = currentCurrentTime; // Oppdater tiden for neste iterasjon
}
