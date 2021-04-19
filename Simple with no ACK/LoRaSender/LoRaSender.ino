#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");

   while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
//    LoRa.setSyncWord(0xF3);
LoRa.setTxPower(20);
LoRa.setSpreadingFactor(12);

}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();

  LoRa.print("hello ");

  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(2000);
}
