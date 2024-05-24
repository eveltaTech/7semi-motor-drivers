#include "WiFi.h"
 
const char* ssid = "evelta-Air"; //choose your wireless ssid
const char* password = "reeshu@123"; //put your wireless password here.
//const char* ssid = "OMKAR"; 
//const char* password = "12345678"; 
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the Evelta WiFi network");
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //show ip address when connected on serial monitor.
}
 
void loop() {}