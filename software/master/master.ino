/*
 * RF-Based Master-Slave Robot
 * MASTER CONTROLLER
 *
 * This is a hardware-independent project skeleton.
 * Update the RF library, pins and input mapping after
 * the final hardware components are confirmed.
 */

const int INPUT_1 = A0;
const int INPUT_2 = A1;
const int INPUT_3 = A2;
const int INPUT_4 = A3;

struct CommandPacket {
  uint16_t c1;
  uint16_t c2;
  uint16_t c3;
  uint16_t c4;
  uint16_t checksum;
};

uint16_t calculateChecksum(const CommandPacket &packet) {
  return packet.c1 ^ packet.c2 ^ packet.c3 ^ packet.c4;
}

void setup() {
  Serial.begin(9600);

  pinMode(INPUT_1, INPUT);
  pinMode(INPUT_2, INPUT);
  pinMode(INPUT_3, INPUT);
  pinMode(INPUT_4, INPUT);

  // Initialize the actual RF transmitter here.
}

void loop() {
  CommandPacket packet;

  packet.c1 = analogRead(INPUT_1);
  packet.c2 = analogRead(INPUT_2);
  packet.c3 = analogRead(INPUT_3);
  packet.c4 = analogRead(INPUT_4);

  packet.checksum = calculateChecksum(packet);

  /*
   * Replace this with the transmit call for the
   * RF module used in the final prototype.
   *
   * Example:
   * radio.write(&packet, sizeof(packet));
   */

  Serial.print("C1: ");
  Serial.print(packet.c1);
  Serial.print(" C2: ");
  Serial.print(packet.c2);
  Serial.print(" C3: ");
  Serial.print(packet.c3);
  Serial.print(" C4: ");
  Serial.println(packet.c4);

  delay(50);
}
