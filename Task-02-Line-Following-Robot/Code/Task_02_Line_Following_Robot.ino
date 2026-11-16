// Task 02: Line Following Robot
// Board: VEGA ARIES V2 (MbedO runtime selection)
// Motor Driver: L298N

const int LEFT_SENSOR = 9;
const int RIGHT_SENSOR = 8;

const int IN1 = 14;
const int IN2 = 15;
const int IN3 = 13;
const int IN4 = 12;

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  Serial.println("Line Following Robot Initialized.");
}

void loop() {
  int leftState = digitalRead(LEFT_SENSOR);
  int rightState = digitalRead(RIGHT_SENSOR);

  if (leftState == LOW && rightState == LOW) {
    Serial.println("ON TRACK - Moving Forward");
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  } else if (leftState == HIGH && rightState == LOW) {
    Serial.println("DRIFTED RIGHT - Correcting Left");
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  } else if (leftState == LOW && rightState == HIGH) {
    Serial.println("DRIFTED LEFT - Correcting Right");
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  } else {
    Serial.println("JUNCTION/STOP - Stopping");
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  }
  delay(20);
}