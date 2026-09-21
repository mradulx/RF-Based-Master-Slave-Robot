# System Architecture

## RF-Based Master-Slave Robot

### 1. Master Unit

The master unit is the operator interface. It senses the desired movement and converts it into digital control data.

**Flow:**

Input controls → Microcontroller → Data processing → RF transmitter

### 2. Wireless RF Link

The RF subsystem provides the communication path between the master and slave units.

The communication layer should define:

- Data rate
- Transmission interval
- Packet format
- Addressing, if supported
- Error detection
- Communication timeout

### 3. Slave Unit

The slave receives the command packet and converts it into actuator commands.

**Flow:**

RF receiver → Microcontroller → Packet validation → Command mapping → Driver → Actuator

### 4. Recommended Control Loop

```text
MASTER
  │
  ├─ Read inputs
  ├─ Filter/map values
  ├─ Create packet
  └─ Transmit
          │
          ▼
      RF CHANNEL
          │
          ▼
SLAVE
  ├─ Receive
  ├─ Validate
  ├─ Decode
  ├─ Apply limits
  └─ Drive actuator
```

### 5. Failure Handling

If no valid packet is received for a configurable timeout period, the slave should enter a safe state and stop or hold the actuators according to the mechanical design.

### 6. Final Hardware Mapping

The exact GPIO pins, RF module model, actuator type, supply voltage, and controller model must be documented here after the prototype wiring is finalized.
