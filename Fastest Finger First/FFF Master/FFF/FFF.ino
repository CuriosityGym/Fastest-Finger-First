#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Hash.h>
#include <WiFiManager.h>    /////
#include <EEPROM.h>               ////
#include <WiFiUdp.h>
#include "play.h"

WiFiUDP Udp;
unsigned int localUdpPort = 8888;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back


int pushButton = D3;


const int threshold = 1;  // threshold value to decide when the detected sound is a knock or not
int Time = 0;


#define USE_SERIAL Serial

//ESP8266WiFiMulti WiFiMulti;

ESP8266WebServer server(80);// = ESP8266WebServer(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {

    switch(type) {
        case WStype_DISCONNECTED:
            USE_SERIAL.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            USE_SERIAL.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Ready!");
        }
            break;
        case WStype_TEXT:
            USE_SERIAL.printf("[%u] get Text: %s\n", num, payload);

            if(payload[0] == '#') {
                // we get RGB data

                // decode rgb data
                uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);

            }

            break;
    }

}

void setup() {
    USE_SERIAL.begin(115200);
    pinMode(pushButton, INPUT_PULLUP);
  
    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }
/*
    WiFiMulti.addAP("DT_LAB", "fthu@050318");

    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }
  */
   WiFiManager wifiManager;                    ////
    // wifiManager.resetSettings();                  ///
     wifiManager.autoConnect("FFF");               ////
     Serial.println("connected...yeey :)");         ////
     Serial.println( WiFi.SSID().c_str());       /////
     Serial.println(WiFi.psk().c_str());                ///
    //String ssid1 = WiFi.SSID().c_str();        ////
    wifiManager.setConfigPortalTimeout(180);         //////

     Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

    // start webSocket server
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    if(MDNS.begin("esp8266")) {
        USE_SERIAL.println("MDNS responder started");
        USE_SERIAL.println(WiFi.localIP());
    }

    // handle index
    server.on("/", []() {
        // send index.html
        String s = MAIN_page;
        server.send(200, "text/html", s);
    });
    server.begin();
    // Add service to MDNS
    MDNS.addService("http", "tcp", 80);
    MDNS.addService("ws", "tcp", 81);
}

void loop() {
  int buttonState = digitalRead(pushButton);

  while(buttonState==0){}

  
   int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
   // Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
  }
    webSocket.loop();
    server.handleClient();
    


 

    
    
    // send a message to websocket is Option A
    if (buttonState == 0) {
      webSocket.sendTXT(0,"incomingPacket");
      //delay(100);
    }

    // send a message to websocket
    if (buttonState == threshold) {
      Time = Time + 1;
      buttonState = millis();
      String thisString = String(Time);
      webSocket.sendTXT(0,incomingPacket);
      //delay(100);
    } 
}
