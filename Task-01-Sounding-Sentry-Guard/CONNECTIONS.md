# Task 01 — Sounding Sentry Guard: Connections

Board/runtime in the supplied report: VEGA ARIES v2 / THEJAS32 browser runtime.

| Component | Signal | Board connection |
|---|---|---|
| HC-SR04 | TRIG | D14 |
| HC-SR04 | ECHO | D15 |
| PIR sensor | OUT | D17 |
| Buzzer | Signal | D12 |
| 16x2 I2C LCD | SDA/SCL | Board I2C via Wire (default pins not specified in the supplied sketch) |
| All modules | GND | Common GND |
| Modules requiring power | VCC | Use the module's rated supply; confirm voltage against its datasheet |

**Important:** D14/D15/D17/D12 are taken from the original sketch. The report says ultrasonic distance measurement was not verified because the tested runtime reported `pulseIn()` and `delayMicroseconds()` as undefined. Confirm actual board I2C pins and supply requirements before hardware wiring.