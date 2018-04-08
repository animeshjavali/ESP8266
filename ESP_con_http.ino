#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <ESP8266HTTPClient.h>
char *ssid="Ani";
char *password="ibringit";

void setup() {
 /* pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);*/
Serial.begin(115200);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED){
  Serial.println("Connecting to....");
  delay(500);
}
  Serial.println("Connected to");

}

void loop() {
if(WiFi.status()==WL_CONNECTED){
  HTTPClient http;
  http.begin("https://databases-auth.000webhost.com/sql.php?server=1&db=id5230759_esp&table=led&pos=0&token=520f973f7ef8d882222aa0b93173c95b");
  int httpcode=http.GET();
  if(httpcode>0){
    String payload=http.getString();
    Serial.println(payload);
  /*  if(payload=='1')
      digitalWrite(8,HIGH);
    
    else if(payload=='2')
            digitalWrite(8,LOW);
            
    else if(payload=='3')
            digitalWrite(9,HIGH);
     else if(payload=='4')
            digitalWrite(9,LOW);
     */       
  }
  http.end();
}
delay(30000);
}
