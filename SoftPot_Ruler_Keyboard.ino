#include <Keyboard.h>

#define BUTTON 7
#define SOFT_POT_PIN A0 // Pin connected to softpot wiper
#define RULER_OFFSET 15 // The point (value in inches) on the ruler where softpot starts.
#define SOFT_POT_LENGTH 200 // Softpot length in tenths (1 tenth = 1/10 inch)

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(SOFT_POT_PIN, INPUT);
  Serial.begin(9600); // debug
  Keyboard.begin();
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    // Read in the soft pot's ADC value
    int softPotADC = analogRead(SOFT_POT_PIN);

    if (softPotADC > 0)  {
      // Map the 0-1023 value to 0-SOFT_POT_LENGTH
      float d = map(softPotADC, 0, 1023, 0, SOFT_POT_LENGTH);

      float l = RULER_OFFSET + (d / 10);

      Serial.println(String(l) + " inches"); // debug

      Keyboard.print(l);
    }

    delay(500);
  }
}
