# Task 02 — Line Following Robot: Connections

Board/runtime: VEGA ARIES v2 / MbedO. Motor driver: L298N.

| Component | Signal | Board connection |
|---|---|---|
| Left IR sensor | OUT | D9 |
| Right IR sensor | OUT | D8 |
| L298N | IN1 | D14 |
| L298N | IN2 | D15 |
| L298N | IN3 | D13 |
| L298N | IN4 | D12 |
| L298N | GND | Common GND with board |
| IR sensors / L298N | VCC | Use each module's rated supply; verify logic voltage compatibility |

**Not confirmed in supplied code:** L298N ENA/ENB enable-pin wiring and motor power wiring. The report records unresolved D12–D15 circuit-mapping warnings; motor movement was not verified. Reconnect and verify each driver input in MbedO before marking complete.