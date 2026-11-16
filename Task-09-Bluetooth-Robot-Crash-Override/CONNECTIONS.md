# Task 09 — Bluetooth Robot with Crash Override: Connections

Board: VEGA ARIES v3. Modules: HC-05, HC-SR04, L298N. Pin assignments below are taken from the supplied Task 128 sketch.

| Component | Signal | Board connection |
|---|---|---|
| L298N | ENA | D9 |
| L298N | IN1 | D7 |
| L298N | IN2 | D8 |
| L298N | ENB | D17 |
| L298N | IN3 | D18 |
| L298N | IN4 | D19 |
| HC-SR04 | TRIG | D5 |
| HC-SR04 | ECHO | D6 |
| HC-05 | UART | `Serial2` (physical RX/TX pin numbers are not specified in the supplied sketch) |
| All modules | GND | Common GND |

Use a suitable motor supply and verify HC-05 logic-level compatibility before connecting UART. The ZIP does not provide the Serial2 pin map or full power wiring, so check the VEGA ARIES v3 board documentation. The report says HC-05/runtime support and the interpreted code path were not verified.