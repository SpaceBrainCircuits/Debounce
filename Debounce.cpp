/*
  Debounce.cpp - Library for debouncing input pins.
*/

#include "Arduino.h"
#include "Debounce.h"

Debounce::Debounce(int pin, unsigned long debounceDelay)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _debounceDelay = debounceDelay;
}

int Debounce::PinState()
{
  int reading = digitalRead(_pin);

  if (reading != _lastPinState) {
    // reset the debouncing timer
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the pin state has changed:
    if (reading != _pinState) {
      _pinState = reading;
    }
  }

  // save the reading. Next time through the loop, it'll be the _lastPinState:
  _lastPinState = reading;

  return _pinState;
}
