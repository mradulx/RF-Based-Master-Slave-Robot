# RF-Based Master-Slave Robot

> A wireless master-slave robotic system designed to transmit operator commands over RF and reproduce the corresponding motion on a remote slave robot.

![Project Status](https://img.shields.io/badge/status-in%20development-orange)
![Domain](https://img.shields.io/badge/domain-ECE%20%7C%20Embedded%20Systems-blue)
![Communication](https://img.shields.io/badge/communication-RF-green)
![Platform](https://img.shields.io/badge/platform-Arduino%20%2F%20MCU-lightgrey)

## Overview

This project implements a **master-slave robotic system** in which the master unit captures the operator's commands and transmits them wirelessly using an RF communication link. The slave unit receives the commands and drives its actuators to reproduce the requested movement.

The project combines **embedded systems, wireless communication, motor control, and robotics** into a single ECE application.

## System Architecture

```text
                    MASTER UNIT
        ┌─────────────────────────────┐
        │ Joystick / Sensors / Input  │
        └──────────────┬──────────────┘
                       ↓
        ┌─────────────────────────────┐
        │      Master Controller      │
        │       (Microcontroller)     │
        └──────────────┬──────────────┘
                       ↓
        ┌─────────────────────────────┐
        │        RF Transmitter       │
        └──────────────┬──────────────┘
                       │
                  ~ RF LINK ~
                       │
        ┌──────────────▼──────────────┐
        │         RF Receiver         │
        └──────────────┬──────────────┘
                       ↓
        ┌─────────────────────────────┐
        │       Slave Controller      │
        │       (Microcontroller)     │
        └──────────────┬──────────────┘
                       ↓
        ┌─────────────────────────────┐
        │ Motor / Servo Driver Stage  │
        └──────────────┬──────────────┘
                       ↓
                    SLAVE ROBOT
```

## Working Principle

1. The operator moves the master controls.
2. The master microcontroller reads the input values.
3. Input values are converted into a structured data packet.
4. The RF transmitter sends the packet wirelessly.
5. The slave RF receiver receives the transmitted data.
6. The slave controller validates and decodes the packet.
7. The actuator control stage converts the commands into motor/servo movement.
8. The slave robot reproduces the commanded motion.

## Repository Structure

```text
RF-Based-Master-Slave-Robot/
│
├── README.md
├── .gitignore
│
├── docs/
│   └── system-architecture.md
│
├── hardware/
│   ├── master/
│   └── slave/
│
├── software/
│   ├── master/
│   │   └── master.ino
│   └── slave/
│       └── slave.ino
│
├── 3d-model/
│   └── README.md
│
├── images/
│   └── README.md
│
└── LICENSE
```

## Main Subsystems

| Subsystem | Function |
|---|---|
| Master Controller | Reads operator commands |
| RF Transmitter | Sends commands wirelessly |
| RF Receiver | Receives command packets |
| Slave Controller | Decodes received commands |
| Driver Stage | Controls actuators |
| Slave Robot | Performs the commanded movement |
| Power Supply | Provides regulated power |

## Software Architecture

The software is divided into two independent firmware units:

### Master Firmware

```text
Read Inputs
    ↓
Map / Filter Values
    ↓
Build Data Packet
    ↓
Transmit Packet
    ↓
Repeat
```

### Slave Firmware

```text
Receive Packet
    ↓
Validate Packet
    ↓
Decode Commands
    ↓
Apply Safety Limits
    ↓
Drive Actuators
    ↓
Repeat
```

## Communication Packet

The final packet format should be adapted to the RF module used in the hardware build. A typical packet can contain:

```text
[START] [COMMAND 1] [COMMAND 2] [COMMAND 3] [COMMAND 4] [CHECK] [END]
```

A checksum/validation field is recommended so corrupted RF data does not directly command the motors.

## Hardware

Add the exact components used in the final prototype here, for example:

- Master microcontroller
- Slave microcontroller
- RF transmitter module
- RF receiver module
- Joystick / potentiometers / sensors
- Servo motors or DC motors
- Motor driver
- Power supply / battery
- Robot chassis or robotic arm mechanism
- Connecting wires and supporting electronics

> Component names and pin assignments should be updated after the final hardware prototype is frozen.

## Safety Considerations

The slave firmware should include:

- Command timeout / communication-loss stop
- Actuator angle or speed limits
- Valid-packet checking
- Safe startup position
- Separate logic and motor power where appropriate
- Emergency stop provision for the physical prototype

## Future Scope

- Bidirectional RF communication
- Feedback from slave to master
- Position sensors / encoders
- Closed-loop control
- Improved packet error detection
- Longer-range communication
- Obstacle detection
- Camera-based remote operation
- ESP32-based telemetry and monitoring

## Project Status

**Current stage:** Hardware/software development

This repository will contain the final circuit, firmware, CAD/3D model, photographs, documentation, and testing results as the project progresses.

## Author

**Mradul Singh**  
ECE | Embedded Systems | Robotics

GitHub: https://github.com/mradulx
