#define SENSOR_PORT 2
#define GREEN_PORT 12

void setup() {
  pinMode(SENSOR_PORT, INPUT);
  pinMode(GREEN_PORT, OUTPUT);
}

void loop() {
  int sensorState = digitalRead(SENSOR_PORT);
  if (sensorState) {
    digitalWrite(GREEN_PORT, HIGH);
  } else {
    digitalWrite(GREEN_PORT, LOW);
  }
}
