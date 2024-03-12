void bluetoothUpdate() {
  // Antar at k1, k2, k3, k4 er globale variabler av typen float
  extern float k1, k2, k3, k4;

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

    // Skriver ut oppdaterte verdier
    SerialBT.println("Verdier: k1=" + String(k1) + ", k2=" + String(k2) + ", k3=" + String(k3) + ", k4=" + String(k4));
    Serial.println("Verdier: k1=" + String(k1) + ", k2=" + String(k2) + ", k3=" + String(k3) + ", k4=" + String(k4));
  }
}
