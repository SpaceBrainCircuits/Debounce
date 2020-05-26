/*
  Debounce.h - Library for debouncing input pins.
*/

#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"

class Debounce
{
  public:
    Debounce(int pin, unsigned long debounceDelay);
    int PinState(); //Check this if HIGH or LOW
  private:
    int _pin;
    int _lastPinState;
    int _pinState;
    unsigned long _lastDebounceTime = 0; // the last time the input pin was toggled
    unsigned long _debounceDelay; // the debounce delay
};

#endif
