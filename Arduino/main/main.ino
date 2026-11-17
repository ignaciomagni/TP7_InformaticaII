int pinE1 = 2;
int pinE2 = 3;
int pinL1 = 8;
int pinL2 = 9;

bool estadoAnteriorE1 = HIGH;
bool estadoAnteriorE2 = HIGH;
bool estadoL1 = false;
bool estadoL2 = false;

void setup() {
  pinMode(pinE1, INPUT_PULLUP);
  pinMode(pinE2, INPUT_PULLUP);
  pinMode(pinL1, OUTPUT);
  pinMode(pinL2, OUTPUT);

  digitalWrite(pinL1, LOW);
  digitalWrite(pinL2, LOW);
  
  Serial.begin(9600);
}

void loop() {
  bool lecturaE1 = digitalRead(pinE1);
  bool lecturaE2 = digitalRead(pinE2);

  if (lecturaE1 == LOW && estadoAnteriorE1 == HIGH) {
    delay(30);
    if (digitalRead(pinE1) == LOW) {
      estadoL1 = !estadoL1;
      digitalWrite(pinL1, estadoL1 ? HIGH : LOW);
    }
  }
  estadoAnteriorE1 = lecturaE1;

  if (lecturaE2 == LOW && estadoAnteriorE2 == HIGH) {
    delay(30);
    if (digitalRead(pinE2) == LOW) {
      estadoL2 = !estadoL2;
      digitalWrite(pinL2, estadoL2 ? HIGH : LOW);
    }
  }
  estadoAnteriorE2 = lecturaE2;

  if (Serial.available() > 0) {
    char comando = Serial.read();
    if (comando == 'A') { estadoL1 = true;  digitalWrite(pinL1, HIGH); }
    if (comando == 'a') { estadoL1 = false; digitalWrite(pinL1, LOW); }
    if (comando == 'B') { estadoL2 = true;  digitalWrite(pinL2, HIGH); }
    if (comando == 'b') { estadoL2 = false; digitalWrite(pinL2, LOW); }
  }

  Serial.print(estadoL1 ? 1 : 0);
  Serial.print(",");
  Serial.print(estadoL2 ? 1 : 0);
  Serial.print(",");
  Serial.print(lecturaE1 == LOW ? 1 : 0); // Para mostrar el pulso momentáneo en E1 si se desea
  Serial.print(",");
  Serial.println(lecturaE2 == LOW ? 1 : 0);

  delay(50);
}
