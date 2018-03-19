#include <Keyboard.h>

#define SOFT_POT_PIN A0 // Pin connected to softpot wiper
#define RULER_OFFSET 15 // The point (value in inches) on the ruler where softpot starts.
#define SOFT_POT_LENGTH 200 // Softpot length in tenths (1 tenth = 1/10 inch)

void setup() {
  Serial.begin(9600);
  pinMode(SOFT_POT_PIN, INPUT);
  Keyboard.begin();
}

void loop() {
  // Read in the soft pot's ADC value
  int softPotADC = analogRead(SOFT_POT_PIN);

  if (softPotADC > 0) {
    // Map the 0-1023 value to 0-SOFT_POT_LENGTH
    float d = map(softPotADC, 0, 1023, 0, SOFT_POT_LENGTH);

    float l = RULER_OFFSET + (d / 10);
    Serial.println(String(l) + " inches");

    Keyboard.print(l);
  }

  delay(500);
}
