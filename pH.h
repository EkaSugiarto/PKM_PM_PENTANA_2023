#define pinph 34

float pHv;

void pHS() {
  pinMode(pinph, INPUT);
}

void pHL() {
  pHv = -0.0047* analogRead(pinph) + 15.315;
}