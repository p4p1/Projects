#include <capteur_humidite.h>

float tempe, humi;

void setup() {
  Serial.begin(115200);

}

void loop() {
  readHumidityCapteur(&tempe, &humi);
  Serial.print(" --- Nouvelle lecture --- "); 

  Serial.print("Humidite (%): "); // Humidité
  Serial.println(tempe);

  Serial.print("Temperature (°C): "); // Température
  Serial.println(humi);

  delay(1000); // Pause avant prochaine lecture

}
