// Dot.cpp
#include "Dot.h"
#include "FastLED.h"

Dot::Dot(int origin, int num_leds, CRGB* arr){
  leds = arr;
  leds[origin] = 0xf74040;
  pos = origin;
  max_length = num_leds;
  
  int _map_pos[] = {origin, origin+1, origin+2, origin+1, origin, origin-1, origin-2, origin-3};

  for(int i = 0; i<8; i++){
    map_pos[i] = _map_pos[i];
    //Serial.println(map_pos[i]);
  }
}

Dot::Dot(){
}

void Dot::Update(int t){
  if(counter < 8){
    leds[pos] = CRGB::Black;
    pos = map_pos[counter];
    //Serial.println(pos);
    leds[pos] = 0xf74040;
    counter++;
  }
  else{
    leds[pos] = CRGB::Black;
  }
}

void Dot::Rotate(){
  leds[pos] = CRGB::Black;
  if(pos<150){
    pos++;
    leds[pos] = 0xf74040;
  }
  
}

