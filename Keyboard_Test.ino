#include <Keyboard.h>

void setup() {
  Keyboard.begin();
}

void loop() {
  Keyboard.write('1');
  delay(1000);

  Keyboard.print(23.45);
  delay(1000);

  Keyboard.println(45.32);
  delay(1000);
}
