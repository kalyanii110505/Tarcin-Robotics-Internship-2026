// Task 08 - Robot Speed Control (Official GitHub Task 123)
// VEGA ARIES v3 + L298N
// Existing custom pin connections intentionally preserved.

// Motor A - Left
const int ENA = 9;
const int IN1 = 7;
const int IN2 = 8;

// Motor B - Right
const int ENB = 17;
const int IN3 = 18;
const int IN4 = 19;

void stopMotors() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 0);
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

  // Set both motors to forward direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.begin(115200);
  Serial.println("Robot Speed Control Initialized");
}

void loop() {
  // Level 1: Stop - PWM 0
  Serial.println("Motor Speed: 0 (Stopped)");
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(2000);

  // Level 2: Slow - PWM 100
  Serial.println("Motor Speed: 100 (Slow)");
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  delay(2000);

  // Level 3: Medium - PWM 180
  Serial.println("Motor Speed: 180 (Medium)");
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
  delay(2000);

  // Level 4: Full Speed - PWM 255
  Serial.println("Motor Speed: 255 (Full Speed)");
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  delay(2000);
}