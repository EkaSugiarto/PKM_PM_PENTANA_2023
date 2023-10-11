#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

OneWire alaala(23);
DallasTemperature ajojing(&alaala);
DHT dehate(16, DHT11);

float T, DHTT, DHTH;

void SuhuS() {
  ajojing.begin();
  dehate.begin();
}

void SuhuL() {
  ajojing.requestTemperatures();
  T = ajojing.getTempCByIndex(0);
  DHTH = dehate.readHumidity();
  DHTT = dehate.readTemperature();
}