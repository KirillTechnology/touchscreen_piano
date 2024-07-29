  #define X1 A0
  #define X2 A1
  #define Y1 A2
  #define Y2 A3

  int whiteKeys[] = {190, 0, 290, 0, 430, 570, 0, 710, 0, 850, 0, 960};
  int blackKeys[] = {0, 240, 0, 400, 0, 0, 610, 0, 760, 0, 900, 0};
  int tones[] = {523, 554, 587, 622, 659, 698, 740, 784, 830, 880, 932, 988};

void setup() {
  

  Serial.begin(9600);
}

void loop() {
  pinMode(X1, OUTPUT);
  pinMode(X2, OUTPUT);
  pinMode(Y1, INPUT_PULLUP);
  pinMode(Y2, INPUT);
  digitalWrite(X1, LOW);
  digitalWrite(X2, HIGH);
  delay(5);

  int x = analogRead(Y1);
  delay(5);

  pinMode(X1, INPUT_PULLUP);
  pinMode(X2, INPUT);
  pinMode(Y1, OUTPUT);
  pinMode(Y2, OUTPUT);
  digitalWrite(Y1, LOW);
  digitalWrite(Y2, HIGH);
  delay(5);

  int y = analogRead(X1);
  delay(5);

  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);

  if (x > 1000) {
    noTone(12);
  } else {
    int i = 0;

    if (y > 500) {
      while (x > (blackKeys[i])) {
        i++;
      }
    } else {
      while (x > (whiteKeys[i])) {
        i++;
      }
    }
    tone(12, tones[i]);
  }
delay(100);
}
