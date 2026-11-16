# Task 10 — OLED Complementary Filter Balancer: Connections

Board: VEGA ARIES v3. Both devices share the I2C bus.

| Device | Signal | Board connection |
|---|---|---|
| MPU-6050 | VCC | 3V3 |
| MPU-6050 | GND | GND |
| MPU-6050 | SDA | SDA0 / GP17 |
| MPU-6050 | SCL | SCL0 / GP16 |
| SSD1306 OLED | VCC | 3V3 |
| SSD1306 OLED | GND | GND |
| SSD1306 OLED | SDA | SDA0 / GP17 |
| SSD1306 OLED | SCL | SCL0 / GP16 |

Both modules share SDA, SCL, and common ground. The supplied README gives OLED I2C address 0x3C. **Verification:** the report says the IMU data connection and parser/API path are not verified; the OLED's own simulator status screen is not proof that the complementary-filter output works.