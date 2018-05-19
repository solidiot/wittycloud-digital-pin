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

  // Connect to WiFi
  // TODO: Whether need to connect only once? How to reconnect in case of errors?
  WiFi.mode(WIFI_STA);
  WiFi.begin("Volya", "SocSocovich");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("*");
  }

  Serial.println();
  Serial.println("Connected to WiFi:");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());  
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
