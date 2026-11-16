# Task 03 — Robot Wall Follower: Connections

Board shown: VEGA ARIES v3. Driver: L298N.

| Component | Signal | Board connection |
|---|---|---|
| L298N | IN1 | D14 |
| L298N | IN2 | D15 |
| L298N | IN3 | D13 |
| L298N | IN4 | D12 |
| L298N | GND | Common GND with board |

**Important limitations:** The supplied Task 03 sketch is a motor-sequence test only; it does not contain HC-SR04 trigger/echo pins or wall-distance feedback. ENA/ENB and motor-supply wiring are not assigned in this sketch. The report says the HC-SR04/runtime path was unsupported and D12–D15 had circuit-mapping warnings. Do not treat this as a completed autonomous wall follower.