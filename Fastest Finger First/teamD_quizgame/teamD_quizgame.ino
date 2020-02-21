#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "DT_LAB";
const char* password = "fthu@050318";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets


IPAddress broadastIP (255,255,255,255);
unsigned int materUdpPort = 8888;

int pushButton = D4;
int pushButton2 = D3;
int pushButton3 = D2;
int pushButton4 = D1;
int Buzz=D8;
int LED=D7;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);
  pinMode(pushButton3, INPUT_PULLUP);
  pinMode(pushButton4, INPUT_PULLUP);
  pinMode(Buzz,OUTPUT);
  pinMode(LED,OUTPUT);
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  /*int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
*/
int buttonState = digitalRead(pushButton);
  int buttonState2 = digitalRead(pushButton2);
  int buttonState3 = digitalRead(pushButton3);
  int buttonState4 = digitalRead(pushButton4);
if(buttonState==0 || buttonState2==0 || buttonState3==0 || buttonState4==0){digitalWrite(Buzz,HIGH);digitalWrite(LED,HIGH);} 
  else{digitalWrite(Buzz,LOW);digitalWrite(LED,LOW);}

if(!digitalRead(pushButton)){
    char  replyPacket[] = "D1";  // a reply string to send back
    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(broadastIP, materUdpPort);
    Udp.write(replyPacket);
    Udp.endPacket();
    Serial.println("D1");
    delay(1000);
   }
   if(!digitalRead(pushButton2)){
    char  replyPacket[] = "D2";  // a reply string to send back
    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(broadastIP, materUdpPort);
    Udp.write(replyPacket);
    Udp.endPacket();
    Serial.println("D2");
    delay(1000);
   }
   if(!digitalRead(pushButton3)){
    char  replyPacket[] = "D3";  // a reply string to send back
    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(broadastIP, materUdpPort);
    Udp.write(replyPacket);
    Udp.endPacket();
    Serial.println("D3");
    delay(1000);
   }
   if(!digitalRead(pushButton4)){
    char  replyPacket[] = "D4";  // a reply string to send back
    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(broadastIP, materUdpPort);
    Udp.write(replyPacket);
    Udp.endPacket();
    Serial.println("D4");
    delay(1000);
   }
}
