#define SENSOR_PORT 2
#define GREEN_PORT 12

#include <ESP8266WiFi.h>

void setup() {

  pinMode(SENSOR_PORT, INPUT);
  pinMode(GREEN_PORT, OUTPUT);

  // Start the serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println("ESP8266 digital pin will start");
  Serial.setDebugOutput(true);
}

void loop() {
  int sensorState = digitalRead(SENSOR_PORT);
  if (sensorState) {
    digitalWrite(GREEN_PORT, HIGH);
    Serial.println("Motion detected");
  } else {
    digitalWrite(GREEN_PORT, LOW);
  }
}
