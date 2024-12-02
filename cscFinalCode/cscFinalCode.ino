#include <Adafruit_NeoPixel.h>

//neopixel strips (4 count)
int neoAmt1 = 8;
int neoPin1 = 5;
Adafruit_NeoPixel strip1(neoAmt1, neoPin1);

int neoAmt2 = 8;
int neoPin2 = 4;
Adafruit_NeoPixel strip2(neoAmt2, neoPin2);

int neoAmt3 = 8;
int neoPin3 = 3;
Adafruit_NeoPixel strip3(neoAmt3, neoPin3);

int neoAmt4 = 8;
int neoPin4 = 2;
Adafruit_NeoPixel strip4(neoAmt4, neoPin4);

//buttons and states (4)
const int buttonPin1 = 13;
const int buttonPin2 = 12;
const int buttonPin3 = 11;
const int buttonPin4 = 10;

boolean button1State = false;
boolean prevButton1State = false;

boolean button2State = false;
boolean prevButton2State = false;

boolean button3State = false;
boolean prevButton3State = false;

boolean button4State = false;
boolean prevButton4State = false;

uint32_t blue1 = strip1.Color(0, 0, 255);
uint32_t blue2 = strip2.Color(0, 0, 255);
uint32_t blue3 = strip3.Color(0, 0, 255);
uint32_t blue4 = strip4.Color(0, 0, 255);


void setup()
{
  Serial.begin(9600);
  strip1.begin();  
  strip2.begin();  
  strip3.begin();  
  strip4.begin();  

  strip1.setBrightness(200);
  strip1.clear();
  strip1.show();
  
  strip2.setBrightness(200);
  strip2.clear();
  strip2.show();
  
  strip3.setBrightness(200);
  strip3.clear();
  strip3.show();
  
  strip4.setBrightness(200);
  strip4.clear();
  strip4.show();
}

void loop()
{
  handleButtons();
}


void handleButtons(){
  prevButton1State = button1State;
  button1State = digitalRead(buttonPin1);
 	 if(button1State == true && prevButton1State == false) {
    	travelLight(blue1, 200, 1);
      
 	 }
    
  
  prevButton2State = button2State;
  button2State = digitalRead(buttonPin2);
    if(button2State == true && prevButton2State == false) {
      travelLight(blue2, 200, 2);
    }

  
  prevButton3State = button3State;
  button3State = digitalRead(buttonPin3);
    if(button3State == true && prevButton3State == false) {
    	travelLight(blue3, 200, 3);
    }

  
  prevButton4State = button4State;
  button4State = digitalRead(buttonPin4);
    if(button4State == true && prevButton4State == false) {
      travelLight(blue4, 200, 4);
    }

  
  delay(15);
}


void travelLight(uint32_t c, int delayTime, int stripNum) {

   if(stripNum == 1) {
    for(int i = strip1.numPixels()-1; i >= 0; i--) {
      strip1.setPixelColor(i, c); 
      strip1.show(); 
      delay(delayTime); 
    }
     delay(3000); 
     Serial.println("lol");
     strip1.clear(); 
     strip1.show(); 
   }
  
   if(stripNum == 2) {
    for(int i = strip2.numPixels()-1; i >= 0; i--) {
      strip2.setPixelColor(i, c); 
      strip2.show(); 
      delay(delayTime); 
    }
     delay(3000); 
     Serial.println("lol");
     strip2.clear(); 
     strip2.show(); 
   }
  
     if(stripNum == 3) {
    for(int i = strip3.numPixels()-1; i >= 0; i--) {
      strip3.setPixelColor(i, c); 
      strip3.show(); 
      delay(delayTime); 
    }
     delay(3000); 
     Serial.println("lol");
     strip3.clear(); 
     strip3.show(); 
   }
  
    if(stripNum == 4) {
    for(int i = strip4.numPixels()-1; i >=0; i--) {
      strip4.setPixelColor(i, c); 
      strip4.show(); 
      delay(delayTime); 
    }
      delay(3000); 
     Serial.println("lol");
     strip4.clear(); 
     strip4.show(); 
   }

}




