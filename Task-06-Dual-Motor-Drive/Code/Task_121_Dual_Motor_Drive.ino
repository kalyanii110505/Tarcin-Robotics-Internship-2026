// Task 121 - Dual Motor Drive (Forward / Reverse)
// Board: VEGA ARIES v3
// Motor Driver: L298N

// Motor A (Left)
const int ENA = 9;   // L298N ENA -> ARIES D9
const int IN1 = 7;   // L298N IN1 -> ARIES D7
const int IN2 = 8;   // L298N IN2 -> ARIES D8

// Motor B (Right)
const int ENB = 17;  // L298N ENB -> ARIES D17
const int IN3 = 18;  // L298N IN3 -> ARIES D18
const int IN4 = 19;  // L298N IN4 -> ARIES D19

void stopMotors() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  Serial.begin(115200);
  Serial.println("Task 121 - Dual Motor Drive Started");
}

void loop() {
  // Both motors forward
  Serial.println("Moving Forward");

  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(2000);

  // Stop both motors
  Serial.println("Motor Stop");
  stopMotors();
  delay(1000);

  // Both motors reverse
  Serial.println("Moving Reverse");

  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(2000);

  // Stop both motors
  Serial.println("Motor Stop");
  stopMotors();
  delay(1000);
}