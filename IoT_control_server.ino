#include "thingProperties.h"

// Pines de tu nanoESP32-C6
const int PIN_RELE_1 = 2; // GPIO 2
const int PIN_RELE_2 = 3; // GPIO 3

void setup() {
  Serial.begin(115200);
  delay(1500); 

  pinMode(PIN_RELE_1, OUTPUT);
  pinMode(PIN_RELE_2, OUTPUT);

  // Apagar relés al inicio (Lógica activa en LOW)
  digitalWrite(PIN_RELE_1, HIGH);
  digitalWrite(PIN_RELE_2, HIGH);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

void onRele1Change() {
  if (rele_1) {
    digitalWrite(PIN_RELE_1, LOW);  // Encender Relé 1
  } else {
    digitalWrite(PIN_RELE_1, HIGH); // Apagar Relé 1
  }
}

void onRele2Change() {
  if (rele_2) {
    digitalWrite(PIN_RELE_2, LOW);  // Encender Relé 2
  } else {
    digitalWrite(PIN_RELE_2, HIGH); // Apagar Relé 2
  }
}