#ifndef GLOBALLEDS_H
#define GLOBALLEDS_H
#include "FastLED.h"
#include "Dot.h"
#include "Line.h"
#include "Arduino.h"

void AllLedsOff(CRGB* arr);

bool IsLedValid(int index, CRGB* arr);

void MovingDots(CRGB* arr, int updates_per_second);

void RandomDots(CRGB* arr, int density, int cycles, int updates_per_second);

void MovingLines(CRGB* arr, int size, CHSV color, int updates_per_second);

void AllLedsIntro(CRGB* arr, int size);


#endif /* GLOBALLEDS_H */
