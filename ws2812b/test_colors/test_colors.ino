#include "FastLED.h"
#include <SD.h>
#include <SPI.h>

#define NUM_LEDS 150 
#define DATA_PIN 6   // Arduino pin used for Data
#define BRIGHTNESS  64
#define UPDATES_PER_SECOND 100000

CRGB leds[NUM_LEDS]; // Define the array of leds

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void fill_leds(CRGB* leds, uint16_t n, uint32_t color) {
	fill_solid(leds, n, color);
	FastLED.show();
	delay(10000);
}

void loop() {
	uint32_t colors[] = { 0xfc0000, 0xfc7100, 0xfc9f00, 0xfcff00,0xffc700,0xe9ff00,0xc3ff00,0x7fff00,0x00ff4c,0x00ffae,0x00ffdd,0x00ffff,0x00c7ff,0x0099ff,0x0077ff,0x0000ff,0x2200ff,0x5000ff,0x7f00ff, 0xb200ff, 0xe100ff, 0xff00e1, 0xff00ae, 0xff007b, 0xff0048, 0xff0000, 0x000000 };


	for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++)
		fill_leds(leds, 50, colors[i]);

	delay(8000);
  
}