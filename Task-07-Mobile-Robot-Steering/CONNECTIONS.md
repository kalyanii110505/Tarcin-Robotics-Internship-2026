# Task 07 — Mobile Robot Left/Right Steering: Connections

Board: VEGA ARIES v3. Driver: L298N. Pin assignments are taken from the supplied Task 122 sketch.

| L298N pin | VEGA ARIES connection |
|---|---|
| ENA | D9 |
| IN1 | D7 |
| IN2 | D8 |
| ENB | D17 |
| IN3 | D18 |
| IN4 | D19 |
| GND | Common GND with board |

Connect left/right motors to the corresponding L298N output pairs and use a suitable motor supply. Exact motor-output polarity and supply voltage are not stated in the supplied README/code. The report says serial messages and motor-widget states were observed but six GPIO wiring warnings remain; verify the actual wiring before claiming complete operation.