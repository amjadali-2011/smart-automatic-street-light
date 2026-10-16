/*
  Smart Automatic Street Light
  ALVEMIO Technologies — Imagine. Build. Innovate.

  Wiring:
    LDR leg 1 -> +5V
    LDR leg 2 -> A0
    10k resistor from A0 -> GND
    D9 -> 220-330 ohm resistor -> LED anode
    LED cathode -> GND

  With this divider, A0 generally reads higher in brighter light.
  The LED turns on when the reading is below DARK_THRESHOLD.

  Hardware testing status: not yet verified on a physical board.
*/

const int LDR_PIN = A0;
const int LED_PIN = 9;
const int DARK_THRESHOLD = 400;  // Tune from Serial Monitor readings (0-1023)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  bool isDark = (lightValue < DARK_THRESHOLD);

  digitalWrite(LED_PIN, isDark ? HIGH : LOW);

  Serial.print("LDR reading: ");
  Serial.print(lightValue);
  Serial.print(" | Condition: ");
  Serial.println(isDark ? "DARK - LED ON" : "BRIGHT - LED OFF");

  delay(250);
}
