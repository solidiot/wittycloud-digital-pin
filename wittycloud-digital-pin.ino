#include "configuration.h"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

WiFiClient client;
String response = "";

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
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
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

  if (!client.connected()) {

    // Process and clean the previous response
    if (0 < response.length()) {
      Serial.println("HTTP response:");
      Serial.println(response);
      response = "";
    }

    // Connect to the Web server
    if (client.connect(ONION_REDIS_API_GATEWAY_IP, ONION_REDIS_API_GATEWAY_PORT)) {
      Serial.println("Connected to Web server");
      // client.println("POST /SolidIoT/WittyCloudDigitalPin/PIRMotion HTTP/1.1");
      client.println("POST /test/Echo/echo HTTP/1.0");
      client.println("Content-Length: 2");
      client.println();
      client.println("{}");
      client.println();
    } 
  }

  while (client.available()) {
    char c = client.read();
    response += c;
  } 

  int sensorState = digitalRead(SENSOR_PORT);
  if (sensorState) {
    digitalWrite(GREEN_PORT, HIGH);
    Serial.println("Motion detected");
  } else {
    digitalWrite(GREEN_PORT, LOW);
  }
}
