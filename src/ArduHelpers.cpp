#include "Arduino.h"
#include "ArduHelpers.h"

void forceAllPinsHigh()
{
    for (uint8_t pin = 0; pin < NUM_DIGITAL_PINS; pin++)
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }
}

// https://stackoverflow.com/a/70890675/9860973
long factorial(const int& n)
{
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}