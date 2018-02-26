#include "GlobalLeds.h"
#include "Line.h"
#include "Arduino.h"

void AllLedsOff(CRGB* leds) {
  for(int dot = 0; dot < 150; dot++) { 
    leds[dot] = CRGB::Black;
  }
  FastLED.show();
}

bool IsLedValid(int index, CRGB* leds){
  return index > 0 && index <= sizeof(leds)/sizeof(leds[0]);
}


void MovingDots(CRGB* leds, int updates_per_second){

  Dot pointers[8];
  int origins[8] = {0, 20, 40, 60, 80, 100, 120, 140};

  for(int i =0; i<8; i++){
    pointers[i] = Dot(origins[i],0, leds); 
  }

  for(int i = 0; i < 150; i++){ 
    int t = millis();

    for(int j =0; j<8; j++){
      //pointers[j].Update(0); 
      pointers[j].Rotate();
    }
    
    FastLED.show();
    FastLED.delay(1000 / updates_per_second);
  }
}

void RandomDots(CRGB* leds, int density, int num_cycles, int updates_per_second){
  randomSeed(analogRead(0));
  uint8_t rand_pos;
  uint8_t arr_last_pos[density];
  int leds_length = 150;
  CRGB colors[] = {0x00ff08,0x51ad54,0x6dffb6,0x00cc66,0x00cec4,0x72ff00,0xe1ff38};
  uint8_t colors_length = sizeof(colors)/sizeof(colors[0]);
  
  for(int cycle = 0; cycle < num_cycles; cycle++){
    for(int i=0; i<density; i++){
      rand_pos = random(leds_length);
      arr_last_pos[i] = rand_pos;
      //Serial.println(q.nbRecs());
      leds[rand_pos] = colors[random(colors_length)];
      FastLED.show();
    }
    FastLED.delay(1000 / updates_per_second); 
    
    for(int i=0; i<density; i++){
      //Serial.println(arr_last_pos[i]);
      leds[arr_last_pos[i]] = CRGB::Black;
    }
  }
  FastLED.show();
}

void MovingLines(CRGB* leds, int size, CHSV color, int updates_per_second){
  int leds_length = 150;


  //Line l = Line(0,149,150,leds); //tail, head, num_leds, array_of_leds
  //l.DrawOnly(true, CHSV(169, 255, 100));
  //FastLED.show();
  //delay(1600);

  long t0 = millis();
  AllLedsIntro(leds, leds_length);

//  for(long j = 0; j < 300; j++){
//	  long t = sqrt(j) + j*j/100;
//	  delay(1000/(1+t));
////    Serial.print("j: "); Serial.println(j);
////    Serial.print(l.tail); Serial.print("  "); Serial.println(l.head); delay(10);
//	  color.sat = max((color.sat - 1), 0);
//	  color.val = max((color.val - 1), 0);
//    l.Move(true, false, 1, color);
//    FastLED.show();
//
//	delay(4000);
//  }

  //for (int i = 0; i < 10; i++) {
	 // Serial.print(i); Serial.print(" - ");
	 // Serial.println(leds[i].raw[0]);
  //}

  //for (int i = 0; i < 10; i++) {
	 // CRGB c = CRGB(0,0,0);
	 // leds[i] = leds[i].lerp8(CHSV(40,255,255), 128);
	 // Serial.print(i); Serial.print(" - ");
	 // Serial.println(leds[i].raw[0]);
  //}
  //FastLED.show();
  //delay(1000);




  Serial.print("Time: ");
  Serial.println(millis()-t0);
  delay(1000);
  AllLedsOff(leds);
  delay(2000);

//  for(uint32_t j = 0; j < 100; j++){
//    l.Move(false, false, 1, color); //is_circular, has_trail, steps, color
//    FastLED.show();
//    delay(100);
//  }
//  AllLedsOff(leds);
//  delay(4000);
}

void AllLedsIntro(CRGB* leds, int length) {
	Line l = Line(0, length-1, length, leds); //tail, head, num_leds, array_of_leds
	l.DrawOnly(true, CHSV(169, 255, 100));
	FastLED.show();

	for (int i = 0; i < 200; i++) {
		l.ToDark(1);
		FastLED.show();
		Serial.println(leds[0].getLuma());
		delay(10);

	}

	//delay(1000);
}

