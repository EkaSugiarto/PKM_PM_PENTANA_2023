#include <WiFi.h>
#include "NTP.h"
#include "Pompa.h"
#include "Suhu.h"
#include "pH.h"
#include "Level.h"
#include "TS.h"
#include "LCD.h"

#define ssid "WLAN"
#define pass "00000000"

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Serial.begin(9600);

  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
    delay(500);
  }
  Serial.print("Terhubung");

  pHS();
  NTPS();
  LCDS();
  LevelS();
  TSS();
  PompaS();
}

void SensorRead() {
  pHL();
  NTPL();
  LevelL();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED) setup();

  NTPL();
  PompaL();

  if (waktu.getSeconds() % 2 == 0) {
    SensorRead();
    LCDL();
  }

  if (waktu.getSeconds() % 30 == 0) {
    SensorRead();
    TSL();
  }

  delay(500);
}
