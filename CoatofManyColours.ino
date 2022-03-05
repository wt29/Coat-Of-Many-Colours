/* Programing the Nano
 *  
 *  Board: Nano
 *  Bootloader : ATMega 328 (Old Bootloader)
 *  Programmer : AVR ISP
 *  
 *  Hit the reset button on the board as you hit Upload. The board goes into 
 *  Bootloader mode for a bit before it resumes the current program
 */

#include <FastLED.h>
#define NUM_LEDS 63
#define DATA_PIN 4

int wait=500;   // millis()
int waitClear=300; 

CRGB leds[NUM_LEDS];

int x, e, o, c, z;

int Evens[] = {0,2,4,6,8,10,12,14,16};
int Odds[] =  {1,3,5,7,9,11,13,15,17};

int hash[] = {6,7,9,10,11,12,23,24,25,26,28,29};
int heart[] = {6,7,8,9,12,13,21,25,29,33,39,43,45,48,49,60,61,62};

int number1[] = {36,43,45,46,47,48,49,50,51,52,53,54};
int number6[] = {2,3,4,5,6,10,11,14,16,18,22,26,27,31,35,40,44,46,50,52,56,60};
int number0[] = {3,4,5,10,11,15,16,18,26,27,35,36,46,47,51,52,57,58,59};

int letterA[] = {0,1,2,3,12,13,14,21,24,25,27,32,39,42,43,48,49,50,54,55,56,57};
int letterC[] = {2,3,4,5,6,10,16,18,26,27,35,36,44,45,53};
int letterD[] = {9,10,11,12,13,14,15,16,17,18,26,27,35,37,43,47,51,57,58,59};
int letterE[] = {9,10,11,12,13,14,15,16,17,18,22,26,27,31,35,36,44};
int letterH[] = {9,10,11,12,13,14,15,16,17,22,31,40,45,46,47,48,49,50,51,52,53};
int letterI[] = {18,26,27,28,29,30,31,32,33,34,35,36,44};
int letterL[] = {9,10,11,12,13,14,15,16,17,18,35,36,53};
int letterM[] = {0,1,2,3,4,5,6,7,8,9,10,23,24,31,32,41,42,45,46,54,55,56,57,58,59,60,61,62};
int letterN[] = {9,10,11,12,13,14,15,16,17,25,26,29,30,31,38,39,40,52,53,54,55,56,57,58,59,60,61,62};
int letterO[] = {10,11,12,13,14,15,16,18,26,27,35,36,44,46,47,48,48,50,51,52};
int letterR[] = {0,1,2,3,4,5,6,7,8,9,13,26,22,27,31,32,38,40,44,46,49,52,54,58,59,60};
int letterS[] = {19,13,14,15,16,17,18,22,26,27,31,35,36,40,44,45,46,47,48,49,53};
int letterT[] = {8,9,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,44,45,62};

int rows[] = {0,17,18,35,36,53,54};


void setup() {
  
FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

Serial.begin(115200);

}

void loop() {

clearAll(waitClear);  

/*
// Tech Central 
showLeds( letterT, CRGB::White, true, sizeof( letterT ) );
showLeds( letterE, CRGB::Red, true, sizeof( letterE ) );
showLeds( letterC, CRGB::Blue, true, sizeof( letterC ) );
showLeds( letterH, CRGB::Orange, true, sizeof( letterH ) );
showLeds( letterC, CRGB::Green, true, sizeof( letterC ) );
showLeds( letterE, CRGB::Pink, true, sizeof( letterE ) );
showLeds( letterN, CRGB::Yellow, true, sizeof( letterN ) );
showLeds( letterT, CRGB::Purple, true, sizeof( letterT ) );
showLeds( letterR, CRGB::Cyan, true, sizeof( letterR ) );
showLeds( letterA, CRGB::Red, true, sizeof( letterA ) );
showLeds( letterL, CRGB::Blue, true, sizeof( letterL ) );


// Hi Chris

showLeds( letterH, CRGB::Blue, true, sizeof( letterH ) );
showLeds( letterI, CRGB::Blue, true, sizeof( letterI ) );
clearAll(1000);
showLeds( letterC, CRGB::Blue, true, sizeof( letterC ) );
showLeds( letterH, CRGB::Blue, true, sizeof( letterH ) );
showLeds( letterR, CRGB::Blue, true, sizeof( letterR ) );
showLeds( letterI, CRGB::Blue, true, sizeof( letterI ) );
showLeds( letterS, CRGB::Blue, true, sizeof( letterS ) );
*/
showLeds( letterN, CRGB::Yellow, true, sizeof( letterN ) );
showLeds( letterI, CRGB::Blue, true, sizeof( letterI ) );
showLeds( letterC, CRGB::Green, true, sizeof( letterC ) );
showLeds( letterO, CRGB::Purple, true, sizeof( letterO ) );
showLeds( letterL, CRGB::Blue, true, sizeof( letterL ) );
showLeds( letterA, CRGB::Red, true, sizeof( letterA ) );
oneLed( CRGB::Blue, false, 17 );
oneLed( CRGB::Blue, false, 18 );
oneLed( CRGB::Blue, false, 35 );
oneLed( CRGB::Blue, false, 36 );
oneLed( CRGB::Blue, false, 53 );
clearAll( 100 );
showLeds( number6, CRGB::Red, false, sizeof( number6 ) );
clearAll(1);
showLeds( number6, CRGB::Pink, false, sizeof( number6 ) );
clearAll(1);
showLeds( number0, CRGB::White, false, sizeof( number0 ) );
clearAll(1);
showLeds( number0, CRGB::Purple, false, sizeof( number0 ) );
clearAll(1);
cylon(7);
clearAll( 500 );

}

void oneLed( CRGB colour, bool clear, int aLed ){
  leds[ aLed ] = colour;
  FastLED.show();
  delay( wait );
  if (clear){ 
    clearAll( waitClear );
  }
}

void showLeds( int lArray[], CRGB colour, bool clear, int sizeOfArray  ){

for (int x=0; x < ( sizeOfArray/sizeof(int)) ; x++ ){
    Serial.print( lArray[x] );
    leds[ lArray[x] ] = colour; 
    
}
     Serial.println();
     FastLED.show(); 
     delay( wait );
     if (clear){ 
      clearAll( waitClear );
     }
}


void clearAll(int clearWait ) {

  for( c=0; c < NUM_LEDS ; c++ ) {
    delay(5);
    leds[c] = CRGB::Black;
  }
     FastLED.show();
     delay( clearWait );  
  }
  

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void cylon(int repeats) { 
  static uint8_t hue = 0;
  // First slide the led in one direction
  for(int j = 1; j <= repeats; j++ ){
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }

  // Now go in the other direction.  
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
  }  // Do it a couple of times
}
