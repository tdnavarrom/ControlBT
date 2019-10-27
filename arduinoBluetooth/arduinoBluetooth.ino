#define SW 34
String s, value = "250";
void setup()
{
  pinMode(SW, INPUT);
  Serial1.begin(9600);
  Serial.begin(9600);
}

bool keyword(char c) {
  return c == 'a' or c == 'p' or c == 'm' or c == 's' or c == 'h' or c == 'E';
}

void loop() {
  if (Serial1.available()) {
    char c = Serial1.read();
    if (keyword(c)) {
      if (s == "") Serial.println(c);
      else {
        Serial.println(s);
        value = s;
      }
      s = "";
    } else s += c;
  }
  else if (digitalRead(SW)) {
    String string = "*4301,492383,222223,422," + String(value) + ",Bienvenido#";
    Serial1.println(string);
    Serial.println(string);
    delay(100);
  }
}
