/*
 * Task 03: Robot Wall Follower - Motor Driver Test
 * Board shown in MbedO: VEGA ARIES V3
 * Driver: L298N
 * Note: Motor sequence test only; no HC-SR04 feedback.
 */
const int IN1 = 14;
const int IN2 = 15;
const int IN3 = 13;
const int IN4 = 12;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(115200);
  Serial.println("Motor Test Started");
}

void loop() {
  Serial.println("Moving Forward");
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(2000);

  Serial.println("Turning Right");
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
  delay(2000);

  Serial.println("Turning Left");
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(2000);

  Serial.println("Stopping");
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  delay(2000);
}