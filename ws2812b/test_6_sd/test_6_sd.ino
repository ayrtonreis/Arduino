#include "FastLED.h"
#include <SD.h>
#include <SPI.h>

#define NUM_LEDS 150 
#define DATA_PIN 6   // Arduino pin used for Data
#define BRIGHTNESS  200
#define UPDATES_PER_SECOND 100000

CRGB leds[NUM_LEDS]; // Define the array of leds

File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno
uint16_t strip_length;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  

  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);

  // SD Card Initialization
  if (SD.begin())
  {
	  Serial.println("SD card is ready to use.");
  }
  else
  {
	  Serial.println("SD card initialization failed");
	  return;
  }

  
}

bool turn_off = false;
void loop() {

	if (!turn_off) {
		musicShow();
	}

	if (Serial.available() > 0) {
		char input = Serial.read();
		Serial.println(input);
		if (input != '\n' && input != '\r') {
			if (input == 'x') {
				turn_off = true;
			}
			else {
				turn_off = false;
				delay(1000);
			}
		}
	}
	
	
}

void musicShow() {
	String file_name = "returnB.txt";

	myFile = SD.open(file_name);

	long t0 = 0;
	long t0_abs = millis();

	if (myFile) {
		Serial.println("Read:");

		uint16_t row = 0;

		strip_length = myFile.read();
		//Serial.print("Length: ");
		//Serial.println(strip_length);

		while (myFile.available()) {
			//Serial.print("Row " + String(row) + ": ");

			t0 = millis();
			for (uint16_t counter = 0; counter < strip_length; counter++) {
				//Serial.print("RGB ["+String(counter)+"]: ");
				//if(row >= 70 && row <= 80){
				//if (counter < strip_length -1) {
				// Serial.print(myFile.read()); Serial.print(" ");
				// Serial.print(myFile.read()); Serial.print(" ");
				// Serial.print(myFile.read()); Serial.print(", ");
				//}
				//else {
				// Serial.print(myFile.read()); Serial.print(" ");
				// Serial.print(myFile.read()); Serial.print(" ");
				// Serial.println(myFile.read());
				//}
				//}
				//else {
				// myFile.read(); myFile.read(); myFile.read();
				//}

				uint8_t R = myFile.read();
				uint8_t G = myFile.read();
				uint8_t B = myFile.read();

				leds[counter] = CRGB(R, G, B);


				//if (counter == 149) {
				// Serial.print("RGB: ");
				// Serial.print(R);
				// Serial.print(G);
				// Serial.println(B);
				//}

				//Serial.print(counter);
				//Serial.print("-");

			}
			//Serial.println();
			FastLED.show();
			row++;

			long tf = millis() - t0;

			while (tf < 22) {
				tf = millis() - t0;
			}
			delayMicroseconds(520);

			//Serial.print("Time: ");
			//Serial.println(tf);
		}

		long tf_abs = millis();
		Serial.print("Total time: ");
		Serial.println(tf_abs - t0_abs);

		myFile.close();

		delay(800);
		fill_solid(leds, NUM_LEDS, CRGB::Black);
		FastLED.show();

		Serial.println("THE END");
	}
	else {
		Serial.println("error opening test.txt");
	}
}