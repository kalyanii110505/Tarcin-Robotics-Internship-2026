// Task 07 - GitHub Advanced Task 122
// Mobile Robot Left/Right Steering
// Board: VEGA ARIES v3 | Simulator: MbedO
// Existing custom pin connections intentionally preserved.

const int ENA = 9;
const int IN1 = 7;
const int IN2 = 8;

const int ENB = 17;
const int IN3 = 18;
const int IN4 = 19;

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
  Serial.println("Mobile Robot Steering Initialized");
}

void loop() {
  // Phase 1: Forward - 2 seconds
  Serial.println("Direction: Forward");
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);

  // Phase 2: Sharp Right Turn - 1.5 seconds
  Serial.println("Direction: Sharp Right Turn");
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1500);

  // Phase 3: Forward - 2 seconds
  Serial.println("Direction: Forward");
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);

  // Phase 4: Sharp Left Turn - 1.5 seconds
  Serial.println("Direction: Sharp Left Turn");
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1500);

  // Phase 5: Stop - 2 seconds
  Serial.println("Direction: Stop");
  stopMotors();
  delay(2000);
}