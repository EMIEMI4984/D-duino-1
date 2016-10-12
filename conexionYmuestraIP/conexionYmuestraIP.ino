#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`


SSD1306  display(0x3c, D1, D2);

const char *ssid = "MOVISTARTL";
const char *password = "Martin89";


ESP8266WebServer server ( 80 );


void setup ( void ) {
 Serial.begin ( 115200 );
 WiFi.begin ( ssid, password );
 Serial.println ( "" );

   display.init();
 // Wait for connection
 while ( WiFi.status() != WL_CONNECTED ) {
  delay ( 500 );
  Serial.print ( "." );
    display.print(".");
 }

 Serial.println ( "" );
 Serial.print ( "Connected to " );
 Serial.println ( ssid );
 Serial.print ( "IP address: " );
 Serial.println ( WiFi.localIP() );
 display.clear();
    
 
 if ( MDNS.begin ( "esp8266" ) ) {
  Serial.println ( "MDNS responder started" );
 }

  Serial.println ( "HTTP server started" );



}

void loop() {
   
 display.setTextAlignment(TEXT_ALIGN_LEFT);
 display.setFont(ArialMT_Plain_24);
    display.drawString(0, 0, "Jarvis");
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 30, "En:");
    display.drawString(30, 30, ssid);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 46, "IP:");
    display.drawString(15, 30, WiFi.localIP().toString());
    display.display();
 
}


