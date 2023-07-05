#include <WiFi.h>
#include <WiFiManager.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <DHT.h>
#include <SPI.h>
#include <LoRa.h>
WebServer server(80);
const char *ssid = "";
const char *password = "";
#define ss 4
#define rst 5
#define dio0 2
float level; //For detect the level of the water
void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  wifisetupInit();
    if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
  loraInit(); //Begin Lora 
}

void loop() {
    
    int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    // Serial.print("Received packet ");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      level = LoRaData.toFloat();
      Serial.print(level);
      Serial.println("\n");
    }
  }
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}
float loraProcessing(){
  return level;
}