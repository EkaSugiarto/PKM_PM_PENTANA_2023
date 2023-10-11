#include <WiFiUdp.h>
#include <NTPClient.h>

const char* ntpServer = "pool.ntp.org";
const long gmtOffset = 25200;
const int daylightOffset = 3600;
int hr, mi, sec;
String date, timee;

WiFiUDP ntpUDP;
WiFiClient client;
NTPClient waktu(ntpUDP, ntpServer, gmtOffset, daylightOffset);

void NTPS() {
  waktu.begin();
  waktu.update();
}

void NTPL() {
  waktu.update();

  String date_time = waktu.getFormattedDate();
  int index_date = date_time.indexOf("T");
  date = date_time.substring(0, index_date);
  timee = waktu.getFormattedTime();
}