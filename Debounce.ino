#include "Debounce.h"

Debounce Record(3, 50); //(pin number, debounceDelay)

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  if (Record.PinState() == HIGH)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
}
