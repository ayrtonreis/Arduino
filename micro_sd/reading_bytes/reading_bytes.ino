#include <SD.h>
#include <SPI.h>
//#include <ArduinoSTL.h>

using namespace std;

File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno
uint16_t strip_length;

void setup() {
    
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);
  
  // SD Card Initialization
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }

  String file_name = "return_B.txt";

  myFile = SD.open(file_name);

  long t0 = 0;
  
  if (myFile) {
	  Serial.println("Read:");

	  uint16_t row = 0;

	  strip_length = myFile.read();
	  Serial.print("Length: ");
	  Serial.println(strip_length);

	  while (myFile.available()) {
		  //Serial.print("Row " + String(row) + ": ");

		  t0 = millis();
		  for (uint16_t counter = 0; counter < strip_length; counter++) {
			  //byte b = myFile.read();
			  //Serial.print("RGB ["+String(counter)+"]: ");
			  //Serial.print(myFile.read()); Serial.print(" ");
			  //Serial.print(myFile.read()); Serial.print(" ");
			  //Serial.print(myFile.read()); Serial.print(", ");
			  myFile.read();
			  myFile.read();
			  myFile.read();
		  }
		  //Serial.println();

		  row++;

		  long tf = millis() - t0;
		  Serial.println();
		  Serial.print("Time: ");
		  Serial.println(tf);
	  }

	  myFile.close();
  }
  else {
	  Serial.println("error opening test.txt");
  }

}
  
void loop() {

}
