# Task 01 — Sounding Sentry Guard

**Internship:** Tarcin Robotics & Embedded Systems  
**Reference:** Aries Advanced — Task 141

## Objective
Build a sensor-based security alert prototype that monitors motion and nearby objects, activates a buzzer when an alert condition is detected, and displays system information on a 16x2 I2C LCD.

## Components
- VEGA ARIES board
- HC-SR04 ultrasonic sensor
- PIR motion sensor
- Buzzer
- 16x2 I2C LCD

## Pin connections

| Component | Pin / Signal | VEGA ARIES |
|---|---|---:|
| HC-SR04 | TRIG | D14 |
| HC-SR04 | ECHO | D15 |
| PIR | OUT | D17 |
| Buzzer | Signal | D12 |
| LCD | SDA/SCL | I2C interface |

## Working principle
1. The ultrasonic sensor is triggered to measure the distance to a nearby object.
2. The PIR sensor is read to determine whether motion is detected.
3. If motion is detected or the measured distance is below 50 cm, the buzzer is activated and an intruder alert is sent to the LCD and Serial Monitor.
4. Otherwise, the buzzer remains OFF and the system reports a secure status.

## Observed simulation output
- PIR motion simulation activated: Serial Monitor showed `ALARM - Intruder Detected! Distance: 0 cm | Motion: 1`; buzzer output was HIGH.
- PIR motion simulation inactive: Serial Monitor showed the secure status with `Motion: 0`.
- The PIR-triggered alert and secure-state transitions were observed in the MbedO simulation.

## Learning outcomes
- Digital input reading from a PIR sensor.
- Digital output control for a buzzer.
- HC-SR04 TRIG/ECHO measurement concept.
- I2C LCD initialization and status display.
- Combining sensor conditions using a logical OR operation.
- Monitoring embedded application output through the Serial Monitor.

## Source code
The complete sketch is available in `Code/Task_01_Sounding_Sentry_Guard.ino`.

## MbedO workspace
[Open Task 01 in MbedO](https://mbedo-dev.tarcin.in/designer/p/8d8c7342-69f2-4169-8a5c-30d8cb8fa5a7/project-1).
