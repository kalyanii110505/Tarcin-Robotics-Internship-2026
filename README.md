# Tarcin Robotics & Embedded Systems Internship 2026

A structured portfolio of ten robotics and embedded-systems tasks using VEGA ARIES boards and the Tarcin MbedO environment.

## Project index

| Task | Project | Source code | Wiring / connections |
|---|---|---|---|
| 01 | Sounding Sentry Guard | [Open code](Task-01-Sounding-Sentry-Guard/Code/sounding_sentry_guard_original.ino) | [Open connections](Task-01-Sounding-Sentry-Guard/CONNECTIONS.md) |
| 02 | Line Following Robot | [Open code](Task-02-Line-Following-Robot/Code/Task_02_Line_Following_Robot.ino) | [Open connections](Task-02-Line-Following-Robot/CONNECTIONS.md) |
| 03 | Robot Wall Follower — motor test | [Open code](Task-03-Robot-Wall-Follower/Code/Task_03_Motor_Test_VEGA_ARIES_V3.ino) | [Open connections](Task-03-Robot-Wall-Follower/CONNECTIONS.md) |
| 04 | SD Card Data Logger | [Open code](Task-04-SD-Card-Data-Logger/Code/Task_04_SD_Card_Data_Logger.ino) | [Open connections](Task-04-SD-Card-Data-Logger/CONNECTIONS.md) |
| 05 | DC Motor PID Speed — preliminary motor test | [Open code](Task-05-DC-Motor-PID-Speed/Code/main.ino) | [Open connections](Task-05-DC-Motor-PID-Speed/CONNECTIONS.md) |
| 06 | Dual Motor Drive | [Open code](Task-06-Dual-Motor-Drive/Code/Task_121_Dual_Motor_Drive.ino) | [Open connections](Task-06-Dual-Motor-Drive/CONNECTIONS.md) |
| 07 | Mobile Robot Left/Right Steering | [Open code](Task-07-Mobile-Robot-Steering/Code/Task_122_Mobile_Robot_Left_Right_Steering.ino) | [Open connections](Task-07-Mobile-Robot-Steering/CONNECTIONS.md) |
| 08 | Robot Speed Control | [Open code](Task-08-Robot-Speed-Control/Code/Task_123_Robot_Speed_Control.ino) | [Open connections](Task-08-Robot-Speed-Control/CONNECTIONS.md) |
| 09 | Bluetooth Robot Crash Override | [Open code](Task-09-Bluetooth-Robot-Crash-Override/Code/Task_128_Bluetooth_Robot_Crash_Override.ino) | [Open connections](Task-09-Bluetooth-Robot-Crash-Override/CONNECTIONS.md) |
| 10 | OLED Complementary Filter Balancer | [Open code](Task-10-OLED-Complementary-Filter-Balancer/Code/Task_155_OLED_Complementary_Filter.ino) | [Open connections](Task-10-OLED-Complementary-Filter-Balancer/CONNECTIONS.md) |

## Important verification notes

- Task 03 currently contains a motor-sequence test, not a completed autonomous wall follower.
- Task 05 currently contains a basic motor-direction test; encoder feedback, RPM measurement and closed-loop PID are not verified.
- Task 01 ultrasonic ranging, Task 02 motor mapping, Task 04 SD initialization, Task 08 PWM behaviour, Task 09 Bluetooth/runtime support and Task 10 IMU/parser integration still have documented limitations.
- The connection documents distinguish source-code pin assignments from wiring that is not specified or not yet verified. Confirm board pin maps, supply voltages and common-ground requirements before physical wiring.

## Evidence and screenshots

The project reports preserve observed simulator output, warnings and pending work. Circuit screenshots are being added separately; no screenshot upload is claimed here.

## Author

Akash Arun Dukare  
Electronics & Telecommunication Engineering  
[GitHub profile](https://github.com/dukareakash369-coder)
