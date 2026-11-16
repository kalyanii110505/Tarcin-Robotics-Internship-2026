#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_MPU6050 mpu;

float alpha = 0.96;
float filteredAngle = 0.0;
float accelAngle = 0.0;
float gyroRate = 0.0;

unsigned long lastTime = 0;

bool oledOK = false;
bool mpuOK = false;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  oledOK = display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  mpuOK = mpu.begin();

  if (mpuOK) {
    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  }

  if (oledOK) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("COMPLEMENTARY FILTER");

    if (mpuOK) {
      display.println("MPU6050 READY");
    } else {
      display.println("MPU6050 ERROR");
    }

    display.display();
  }

  if (mpuOK && oledOK) {
    Serial.println("System initialized");
  } else {
    Serial.println("Initialization error");
  }

  lastTime = millis();
}

void loop() {
  if (!mpuOK || !oledOK) {
    return;
  }

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;

  mpu.getEvent(&accel, &gyro, &temp);

  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - lastTime;

  if (elapsed >= 50) {
    float dt = elapsed / 1000.0;
    lastTime = currentTime;

    accelAngle = atan2(accel.acceleration.y, accel.acceleration.z) * 180.0 / PI;
    gyroRate = gyro.gyro.x * 180.0 / PI;

    filteredAngle = alpha * (filteredAngle + gyroRate * dt) + (1.0 - alpha) * accelAngle;

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("COMPLEMENTARY FILTER");

    display.setCursor(0, 20);
    display.print("Accel: ");
    display.print(accelAngle, 1);
    display.println(" deg");

    display.setCursor(0, 40);
    display.print("Filtered: ");
    display.print(filteredAngle, 1);
    display.println(" deg");

    display.display();

    Serial.print("Accel: ");
    Serial.print(accelAngle, 2);
    Serial.print(" | Gyro: ");
    Serial.print(gyroRate, 2);
    Serial.print(" | Filtered: ");
    Serial.println(filteredAngle, 2);
  }
}