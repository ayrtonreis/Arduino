// Dot.h
#ifndef Dot_H
#define Dot_H
#include "FastLED.h"

class Dot
{
  public:
    Dot(int origin, int num_leds, CRGB *arr);
    Dot();
    void Update(int t);
    void Rotate();
    
    CRGB* leds;
    int pos;
    int counter = 0;
    int map_pos[8] = {0,0,0,0,0,0,0,0};
    int max_length;

};

#endif
