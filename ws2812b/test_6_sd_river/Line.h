// Line.h
#ifndef LINE_H
#define LINE_H
#include "FastLED.h"

class Line
{
  public:
    Line(int tail, int head, int leds_length, CRGB *arr);
    Line();
    void FixRange(bool is_circular);
    void DrawOnly(bool is_circular, CHSV color);
    void Move(bool is_circular, bool has_trail, int steps, CHSV color);
	void ToLight(uint8_t factor);
	void ToDark(uint8_t factor);
    
    CRGB* leds;
    int head;
    int tail;
    int counter = 0;
    int max_length;

};

#endif
