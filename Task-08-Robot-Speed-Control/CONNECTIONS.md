# Task 08 — Robot Speed Control: Connections

Board: VEGA ARIES v3. Driver: L298N. Pin assignments are taken from the supplied Task 123 sketch.

| L298N pin | VEGA ARIES connection |
|---|---|
| ENA (PWM) | D9 |
| IN1 | D7 |
| IN2 | D8 |
| ENB (PWM) | D17 |
| IN3 | D18 |
| IN4 | D19 |
| GND | Common GND with board |

Connect the motors to the L298N output terminals and provide a suitable motor supply. Exact motor supply voltage and output polarity are not specified in the supplied files. **Verification:** PWM speed behaviour is not yet verified; the report mentions the screenshot still showing the previous task's serial message and six GPIO wiring warnings.