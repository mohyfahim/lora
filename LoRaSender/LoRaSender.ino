#include <SPI.h>
#include <LoRa.h>

//#define ss 5
//#define rst 14
//#define dio0 2

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
//  LoRa.setPins(ss, rst, dio0);
//LoRa.setTxPower(2);

   while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
//    LoRa.setSyncWord(0xF3);
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

  delay(5000);
}
