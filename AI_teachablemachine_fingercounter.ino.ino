
const byte LED_1 = 2;
const byte LED_2 = 3;
const byte LED_3 = 4;

void setLedCount(byte numberOfLeds) {
  digitalWrite(LED_1, numberOfLeds >= 1 ? HIGH : LOW);
  digitalWrite(LED_2, numberOfLeds >= 2 ? HIGH : LOW);
  digitalWrite(LED_3, numberOfLeds >= 3 ? HIGH : LOW);
}

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  setLedCount(0);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {

    char command = Serial.read();

    switch (command) {

      case '0':
        setLedCount(0);
        break;

      case '1':
        setLedCount(1);
        break;

      case '2':
        setLedCount(2);
        break;

      case '3':
        setLedCount(3);
        break;
    }
  }
}