#include <Arduino.h>

#include "implementation/u8g2_display.hpp"
#include "config.hpp"

U8g2Display display(DISPLAY_SCL_PIN, DISPLAY_SDA_PIN, DISPLAY_RST_PIN);

void setup()
{
  Serial.begin(115200);
  delay(1000);
  
  display.drawTitle("TEST");
}

void loop()
{
}
