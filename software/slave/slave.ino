/*
 * RF-Based Master-Slave Robot
 * SLAVE CONTROLLER
 *
 * This is a hardware-independent project skeleton.
 * Update the RF library, actuator pins and mapping after
 * the final hardware components are confirmed.
 */

struct CommandPacket {
  uint16_t c1;
  uint16_t c2;
  uint16_t c3;
  uint16_t c4;
  uint16_t checksum;
};

unsigned long lastValidPacket = 0;
const unsigned long COMMAND_TIMEOUT = 500;

bool validPacket(const CommandPacket &packet) {
  uint16_t checksum =
      packet.c1 ^ packet.c2 ^ packet.c3 ^ packet.c4;

  return checksum == packet.checksum;
}

void stopActuators() {
  // Implement the safe stop state for the final driver.
}

void applyCommands(const CommandPacket &packet) {
  /*
   * Convert packet values to actuator commands here.
   *
   * Examples:
   * servo.write(angle);
   * motorDriver.setSpeed(speed);
   */

  Serial.print("C1: ");
  Serial.print(packet.c1);
  Serial.print(" C2: ");
  Serial.print(packet.c2);
  Serial.print(" C3: ");
  Serial.print(packet.c3);
  Serial.print(" C4: ");
  Serial.println(packet.c4);
}

void setup() {
  Serial.begin(9600);

  // Initialize RF receiver here.
  // Initialize motors/servos here.

  stopActuators();
}

void loop() {
  CommandPacket packet;

  /*
   * Replace this section with the receive call for
   * the RF module used in the final prototype.
   *
   * Example:
   * if (radio.available()) {
   *   radio.read(&packet, sizeof(packet));
   * }
   */

  // Example validation flow:
  // if (validPacket(packet)) {
  //   lastValidPacket = millis();
  //   applyCommands(packet);
  // }

  if (millis() - lastValidPacket > COMMAND_TIMEOUT) {
    stopActuators();
  }

  delay(10);
}
