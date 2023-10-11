bool Pompa;

void PompaS() {
  pinMode(25, OUTPUT);
}

void PompaL() {
  if ((waktu.getMinutes() % 5 == 0)) {
    digitalWrite(25, LOW);
    Pompa = 1;
  }

  else {
    digitalWrite(25, HIGH);
    Pompa = 0;
  }
}