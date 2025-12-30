#include "ArduHelpers.h"




void setup()
{
    Serial.begin(115200);
}




void loop()
{
    double x = 100.25;
    double y = 0.234;

    double constrained_x = constrain_val(x, 0, 99.4);
    double minimized     = min_val(constrained_x, y);
    double mapped        = map_val(0.0, -1, 0.5, 100, 200);

    Serial.print("x: ");             Serial.println(x);
    Serial.print("y: ");             Serial.println(y);
    Serial.print("constrained_x: "); Serial.println(constrained_x);
    Serial.print("minimized: ");     Serial.println(minimized);
    Serial.print("mapped: ");        Serial.println(mapped);
    Serial.println();

    delay(1000);
}