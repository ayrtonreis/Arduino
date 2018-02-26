#include <SD.h>
#include <SPI.h>
//#include <ArduinoSTL.h>

using namespace std;

File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno
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
  
//  // Create/Open file 
//  myFile = SD.open("test.txt", FILE_WRITE);
//  
//  // if the file opened okay, write to it:
//  if (myFile) {
//    Serial.println("Writing to file...");
//    // Write to file
//    myFile.println("Testing text 1, 2 ,3...");
//    myFile.close(); // close the file
//    Serial.println("Done.");
//  }
//  // if the file didn't open, print an error:
//  else {
//    Serial.println("error opening test.txt");
//  }
  // Reading the file
  myFile = SD.open("bytesfile.txt");

  long t0 = 0;
  
  if (myFile) {
    Serial.println("Read:");
    // Reading the whole file

    t0 = millis();

    char b = 'a';
	//vector<uint32_t> v;
    
    
    while (myFile.available()) {
      b = myFile.read();

      //char number[7];
	  String str;
      int i = 0;
      
      while(myFile.available() && b!= '\n'){
        //number[i] = b;
		str += b;
        b = myFile.read();
      }

       uint32_t number_int = str.toInt();
	   //v.push_back(number_int);
	   //Serial.print(str);
    //   Serial.print("  Number: ");
    //   Serial.println(number_int);

	   if (b == '\n')
		   break;
      
   }
	
   long tf = millis() - t0;
   Serial.println();
   Serial.print("Time: ");
   Serial.println(tf);

   //for (uint32_t n : v) {
	  // std::cout << n << '\n';
   //}
   
    myFile.close();
  }
  else {
    Serial.println("error opening test.txt");
  }
  
}
void loop() {

}
