# Task 05 — DC Motor PID Speed: Connections

Board: VEGA ARIES v3. Driver: L298N.

| L298N pin | VEGA ARIES connection |
|---|---|
| ENA | D9 |
| IN1 | D7 |
| IN2 | D8 |
| GND | Common GND |

**Not yet specified/verified:** Encoder A/B pins, encoder supply, L298N motor-output wiring, motor supply, and ENB (not used by the supplied single-motor test). The report explicitly says encoder connections are unconfirmed and PID/RPM feedback is not implemented or verified. The simulator showed D7/D8/D9 wiring warnings; correct and retest these before claiming working motor control.