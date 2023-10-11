#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <String.h>

//Deklarasi objek LCD 20x4 dengan nama "sibocil" yang memiliki address 0x27 (lihat keterangan LCD di toko saat membeli, dia address nya berapa)
LiquidCrystal_I2C sibocil(0x27, 20, 4);

void LCDS() {
  sibocil.begin(20, 4);
  sibocil.init();
  sibocil.backlight();
}

//Fungsi untuk menampilkan keterangan level air, turbidity air, pH air, dan suhu air ke LCD 20x4
void LCDL() {
  sibocil.clear();
  sibocil.setCursor(0, 0);
  sibocil.print("T Udr = " + String(DHTT) + " C");

  sibocil.setCursor(0, 1);
  sibocil.print("H Udr = " + String(DHTH) + " %");

  sibocil.setCursor(0, 2);
  sibocil.print("H Air = " + String(level) + " cm");

  sibocil.setCursor(0, 3);
  sibocil.print("pH    = " + String(pHv));
}