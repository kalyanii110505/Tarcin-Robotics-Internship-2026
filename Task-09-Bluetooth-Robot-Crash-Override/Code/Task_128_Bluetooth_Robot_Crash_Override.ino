/*
  TASK 128 - Bluetooth Robot with Crash Override
  Board: VEGA ARIES v3
  Driver: L298N | Bluetooth: HC-05 | Sensor: HC-SR04

  Existing motor pin mapping retained from the user's circuit.
  NOTE: MbedO Interpreted Lite reports that custom while loops and
  function calls are unsupported. This sketch is intended for a
  compiled environment with the required Arduino-compatible APIs.
*/

// LEFT MOTOR
const int ENA = 9;
const int IN1 = 7;
const int IN2 = 8;

// RIGHT MOTOR
const int ENB = 17;
const int IN3 = 18;
const int IN4 = 19;

// HC-SR04 alternate pins
const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

char currentDirection = 'S';

void stopMotors() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  currentDirection = 'S';
}

unsigned long readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) return 999UL;

  // Integer approximation: duration * 0.034 / 2
  return (duration * 17UL) / 1000UL;
}

void moveForward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  currentDirection = 'F';
}

void moveBackward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  currentDirection = 'B';
}

void turnLeft() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  currentDirection = 'L';
}

void turnRight() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  currentDirection = 'R';
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  stopMotors();

  Serial.begin(115200);
  Serial2.begin(9600);

  printf("Bluetooth Robot Crash Override Started\n");
  Serial2.println("Control Online. Waiting for commands...");
}

void loop() {
  unsigned long distance = readDistanceCm();

  // Continuous forward safety override
  if (distance <= 15UL && currentDirection == 'F') {
    stopMotors();
    printf("SAFETY TRIPPED: Emergency Stop!\n");
    Serial2.println("CRASH WARNING: Obstacle detected.");
  }

  if (Serial2.available() > 0) {
    char cmd = Serial2.read();
    printf("Received Command: %c\n", cmd);

    if (cmd == 'F' || cmd == 'f') {
      if (distance <= 15UL) {
        stopMotors();
        Serial2.println("ALERT: Obstacle Ahead. Forward blocked.");
      } else {
        moveForward();
        Serial2.println("Action: Forward");
      }
    } else if (cmd == 'B' || cmd == 'b') {
      moveBackward();
      Serial2.println("Action: Backward");
    } else if (cmd == 'L' || cmd == 'l') {
      turnLeft();
      Serial2.println("Action: Left");
    } else if (cmd == 'R' || cmd == 'r') {
      turnRight();
      Serial2.println("Action: Right");
    } else if (cmd == 'S' || cmd == 's') {
      stopMotors();
      Serial2.println("Action: Stop");
    }
  }

  delay(60);
}