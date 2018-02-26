#include "FastLED.h"
#define NUM_LEDS 150 
#define DATA_PIN 6   // Arduino pin used for Data

CRGB leds[NUM_LEDS]; // Define the array of leds


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = CRGB::Black;
    FastLED.show();
  }

}

void loop() {

}
