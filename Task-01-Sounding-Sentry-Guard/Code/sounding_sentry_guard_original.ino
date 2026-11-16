#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 14;
const int echoPin = 15;
const int pirPin = 17;
const int buzzerPin = 12;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.print("Sentry Guard ON");
  delay(1500);
  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  int motionDetected = digitalRead(pirPin);

  lcd.setCursor(0, 0);

  if (motionDetected == HIGH || (distance > 0 && distance < 50)) {
    digitalWrite(buzzerPin, HIGH);
    lcd.print("ALERT: INTRUDER!");
    lcd.setCursor(0, 1);
    lcd.print("D: ");
    lcd.print(distance);
    lcd.print("cm | PIR: ACT");

    Serial.print("ALARM - Intruder Detected! Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Motion: ");
    Serial.println(motionDetected);
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.print("STATUS: SECURE  ");
    lcd.setCursor(0, 1);
    lcd.print("D: ");
    if (distance > 400 || distance <= 0) {
      lcd.print("Out of range ");
    } else {
      lcd.print(distance);
      lcd.print("cm        ");
    }

    Serial.print("Secure - Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Motion: ");
    Serial.println(motionDetected);
  }
  delay(500);
}