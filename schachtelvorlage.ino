

#include <Adafruit_NeoPixel.h>
#include "ordering.h"


#define PIN            13

#define NUMPIXELS      MAT_WIDTH * MAT_HEIGHT

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10;


void setup() 
{
  pixels.begin(); 
  delay(2000); //Schont usb ports
}

void loop() 
{
  rainbowCycle(20);
}

void setPixelWrapped (uint16_t x, uint16_t y, uint32_t color)
{
  x = x % MAT_WIDTH;
  y = y % MAT_HEIGHT;
  pixels.setPixelColor(mat[x][y], color);
}

uint32_t Wheel(byte WheelPos) 
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels .Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
