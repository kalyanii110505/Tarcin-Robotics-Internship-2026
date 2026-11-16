# Task 06 — Dual Motor Drive: Connections

Board: VEGA ARIES v3. Driver: L298N. Pin assignments are taken from the supplied Task 121 sketch.

| L298N pin | VEGA ARIES connection |
|---|---|
| ENA | D9 |
| IN1 | D7 |
| IN2 | D8 |
| ENB | D17 |
| IN3 | D18 |
| IN4 | D19 |
| GND | Common GND with board |

Connect the two motors to the L298N output terminals and use a suitable separate motor supply as required by the driver/motors. The supplied files do not specify the motor supply voltage. The report notes GPIO-to-circuit mapping warnings, so verify all six control wires in MbedO/hardware before considering the task fully tested.