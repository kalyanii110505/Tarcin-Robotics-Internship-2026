// Task 05 – DC Motor Direction Test
// Board: VEGA ARIES v3
// Driver: L298N
// Wiring plan:
//   L298N ENA -> ARIES D9
//   L298N IN1 -> ARIES D7
//   L298N IN2 -> ARIES D8
//   L298N GND -> Common GND
//
// This is a preliminary direction test only. It is NOT the final
// encoder-based PID speed controller.

const int ENA = 9;
const int IN1 = 7;
const int IN2 = 8;

void motorStop() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  motorStop();

  Serial.begin(115200);
  Serial.println("ARIES Motor Direction Test Started");
}

void loop() {
  Serial.println("Motor Forward");
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(3000);

  Serial.println("Motor Stop");
  motorStop();
  delay(2000);

  Serial.println("Motor Reverse");
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(3000);

  Serial.println("Motor Stop");
  motorStop();
  delay(2000);
}