const int tr = 19, ec = 18;
float level;

void LevelS() {
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
}

void LevelL() {
  digitalWrite(tr, LOW);
  delayMicroseconds(2);
  digitalWrite(tr, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr, LOW);

  long t = pulseIn(ec, HIGH);
  level = t * 0.034 / 2;
}