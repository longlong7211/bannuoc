#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <time.h>
#include <EEPROM.h>

#define pinLEDsmart D1
#define PIN_BUTTON D8
#define pinbomCAM D0
#define pinbomPEPSI D1
#define pinbomLOC D2
//#define TRIG_PIN D1
//#define ECHO_PIN D0
//#define TIME_OUT 5000
int timeStart = 1000;
int CAMstatus = 0, PEPSIstatus = 0, LOCstatus = 0;
static long lastPress = 0;
bool longpress = false;
bool in_smartconfig = false;
int statusgettime =1;
ESP8266WebServer server(80);
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  if (EEPROM.read(100) != NULL) {
    timeStart = map(EEPROM.read(100),49,57,1,9)*1000;
    Serial.println(timeStart);
  }
  pinMode(pinbomCAM, OUTPUT);
  pinMode(pinbomPEPSI, OUTPUT);
  pinMode(pinbomLOC, OUTPUT);
//  pinMode(TRIG_PIN, OUTPUT);
//  pinMode(ECHO_PIN, INPUT);
  WiFi.begin("B304-Gamer", "LacHong@2019");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("wifi conected");
  Serial.println(WiFi.localIP());
  server.on("/", handle_OnConnect);
  server.on("/admin", adminlogin);
  server.on("/camClick", camON);
  server.on("/pepsiClick", pepsiON);
  server.on("/StingClick", locON);
  server.onNotFound(handle_NotFound);
  server.begin();
}
void loop() {
  server.handleClient();
  dongco();
  settime();
  //ktwifiConfig();
}
