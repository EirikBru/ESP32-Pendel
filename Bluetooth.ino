void bluetoothUpdate() {
  // Antar at k1, k2, k3, k4 er globale variabler av typen float
  extern float k1, k2, k3, k4, desiredSpeed;

  if (SerialBT.available()) {
    String message = SerialBT.readStringUntil('\n');
    message.trim();

    // Sjekker og oppdaterer k1
    if (message.startsWith("k1 ")) {
      k1 = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer k2
    else if (message.startsWith("k2 ")) {
      k2 = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer k3
    else if (message.startsWith("k3 ")) {
      k3 = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer k4
    else if (message.startsWith("k4 ")) {
      k4 = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer ki
    else if (message.startsWith("ki ")) {
      ki = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer roll offset
    else if (message.startsWith("rO ")) {
      rO = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer pitch offset
    else if (message.startsWith("pO ")) {
      pO = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer deadBand offset
    else if (message.startsWith("db ")) {
      deadBand = message.substring(3).toFloat();
    }
    // Sjekker og oppdaterer desiredSpeed offset
    else if (message.startsWith("ds ")) {
      desiredSpeed = message.substring(3).toFloat();
    }
    // Variabelt setpunkt
    else if (message.startsWith("start sp")) {
      variableSet = true;
    }
    else if (message.startsWith("stop sp")) {
      variableSet = false;
      desiredSpeed = 0;
    }
    // Skriver ut oppdaterte verdier
    SerialBT.println("k1=" + String(k1) + ", k2=" + String(k2) + ", k3=" + String(k3) + ", k4=" + String(k4) + ", ki=" + String(ki) + ", rO=" + String(rO) + ", pO=" + String(pO) + ", db=" + String(deadBand)+ ", ds=" + String(desiredSpeed));
//    Serial.println("Verdier: k1=" + String(k1) + ", k2=" + String(k2) + ", k3=" + String(k3) + ", k4=" + String(k4));
  }
}
