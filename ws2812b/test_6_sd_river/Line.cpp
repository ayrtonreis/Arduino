// Line.cpp
#include "Line.h"
#include "FastLED.h"

Line::Line(int tail_, int head_, int leds_length, CRGB *arr){
  max_length = leds_length;
  leds = arr;

  tail = min(tail_, head_);
  head = max(tail_, head_);
 
  tail = abs(tail_%max_length);
  head = abs(head_%max_length);
}

Line::Line(){
}

void Line::FixRange(bool is_circular){
  if(tail<0){
    tail = max_length + tail;
  }
  else if(is_circular && tail >= max_length){
    tail = tail%max_length;
  }
  
  if(head<0){
    head = max_length + head;
  }
  else if(is_circular && head >= max_length){
    head = head%max_length;
  }
}

void Line::Move(bool is_circular, bool has_trail, int steps, CHSV color){
  
  if(!has_trail){
    if(steps > 0){
      if(steps == 1){
        leds[tail] = CRGB::Black;
      }
      else{
        int original_head = head;
        head = tail + steps-1; //%max_length;
		FixRange(is_circular);
        DrawOnly(is_circular, CHSV(0, 0, 0));
        head = original_head;
      }
    }
    else if(steps < 0){ //negative steps
      if(steps == -1){
        leds[head] = CRGB::Black;
      }
      else{
        int original_tail = tail;
    
        tail = head + steps-1;
		FixRange(is_circular);
        DrawOnly(is_circular, CHSV(0, 0, 0));
        
        
        tail = original_tail;
      }
    }
    else
      return; //steps = 0, so do nothing
  }
  
  head = head + steps;
  tail = tail + steps;
  FixRange(is_circular); //Changes tail or head if needed
  DrawOnly(is_circular, color);
  
}

void Line::DrawOnly(bool is_circular, CHSV color){

  if( tail < head){
      for(int i = tail; i <= head; i++){
          leds[i] = color;
      }
  }
  else{
      for(int i = tail; i <= head + max_length; i++){
    
        if(i<max_length){
          leds[i] = color;
        }
        else if(is_circular){
          leds[i - max_length] = color;
        }
      }
  }


}

void Line::ToLight(uint8_t factor) {
	for (int i = tail; i <= head; i++) {
		leds[i].fadeLightBy(factor);
	}
}

void Line::ToDark(uint8_t factor) {
	for (int i = tail; i <= head; i++) {
		leds[i].fadeToBlackBy(factor);
	}
}