/* Programing the Nano
 *  
 *  Board: Nano
 *  Bootloader : ATMega 328 (Old Bootloader)
 *  Programmer : AVR ISP
 *  
 *  Hit the reset button on the board as you hit Upload. The board goes into 
 *  Bootloader mode for a bit before it resumes the current program
 LEDs are numbered as follows

 8  9  26  27  44  45  62
 7 10  25  28  43  46  61
 6 11  24  29  42  47  60
 5 12  23  30  41  48  59
 4 13  22  31  40  49  58
 3 14  21  32  39  50  57
 2 15  20  33  38  51  56
 1 16  19  34  37  52  55
 0 17  18  35  36  53  54

*/

#include <FastLED.h>
#define NUM_LEDS 63
#define DATA_PIN 4

int wait=10;   // millis()
int waitClear=10 ; 
int intSize = sizeof( int );
int hue;

CRGB leds[NUM_LEDS];

//  int x, e, o, c, z;

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
int letterP[19] = {9,10,11,12,13,14,15,16,17,26,27,44,46,60,59,49,39,32,21 };
int letterR[] = {0,1,2,3,4,5,6,7,8,9,13,26,22,27,31,32,38,40,44,46,49,52,54,58,59,60};
int letterS[] = {19,13,14,15,16,17,18,22,26,27,31,35,36,40,44,45,46,47,48,49,53};
int letterT[] = {8,9,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,44,45,62};

int rows[] = {0,17,18,35,36,53,54};
int centre[] = {31};
int c1[] = {23, 30, 41, 40, 39, 32, 21, 22 };
int c2[] = {11,24,29,42,47,48,49,50,51,38,33,39,20,15,14,13,12};
int c3[] = {7,10,25,28,43,46,61,60,59,58,57,56,55,52,37,34,19,16,1,2,3,4,5,6};

int topBar[] = {8,9,26,27,44,45,62};
int botBar[] = {0,17,18,35,36,53,54};
int spiral[] = {31,30,23,22,21,32,39,40,41,42,29,24,11,12,13,14,15,20,33,38,51,50,49,48,47,46,43,28,25,10,7,6,5,4,3,2,1,16,19,34,37,52,55,56,57,58,59,60,61,62,45,44,27,26,9,8,0,17,18,35,36,53,54};

#define NUM_COLORS 6
CRGB rainbow[]  = { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Blue, CRGB::Violet };

void setup() {
  
FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
Serial.begin(115200);

clearAll(waitClear);  
}

void loop() {

 rainBowOut();

 pride();

 rainBowIn();

 pride();

 spiralShow();

 pride();

 cylon(7);
 
 pride();
 
}

void oneLed( CRGB colour, bool clear, int aLed ){
  leds[ aLed ] = colour;
  FastLED.show();
  delay( wait );
  if (clear){ 
    clearAll( waitClear );
  }
}

void showLeds( int lArray[], CRGB colour, int arrLen  ){
 for (int x=0; x < arrLen ; x++ ){
//  leds[ lArray[x] ] = colour;
     leds[ lArray[x] ] = CHSV(hue++, 255, 255);
 }

 FastLED.show(); 
}


void clearAll(int clearWait ) {
 int c;
 for( c=0; c < NUM_LEDS ; c++ ) {
  delay(5);
  leds[c] = CRGB::Black;
 }
 FastLED.show();
 delay( clearWait );  
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void rainBowOut() {
 int rainBow, c_centre, c_c1, c_c2, c_c3, x;
 clearAll(300);
 for (int x=0; x <= 10 ; x++ ){
//  for ( rainBow = 0; rainBow <= NUM_COLORS-1; rainBow++ ){
   showLeds( c3, hue++, sizeof( c3 )/2 ); 
   showLeds( c2, hue++, sizeof( c2 )/2 );
   c_c2 = c_c1;
   showLeds( c1, hue++, sizeof( c1 )/2 );
   c_c1 = c_centre;
   showLeds( centre, hue++, sizeof( centre )/2 );
   showLeds( topBar, hue++, sizeof( topBar )/2 );
   showLeds( botBar, hue++, sizeof( botBar )/2 );
   c_centre = rainBow;
   delay( 400 );
//  }
 }
} 

void rainBowIn() {
 int rainBow, c_centre, c_c1, c_c2, c_c3, x;
 clearAll(300);
 for (int x=0; x <= 10 ; x++ ){
//  for ( rainBow = 0; rainBow <= NUM_COLORS-1; rainBow++ ){
   showLeds( centre, hue++, sizeof( centre )/2 );
   showLeds( topBar, hue++, sizeof( topBar )/2 );
   showLeds( botBar, hue++, sizeof( botBar )/2 );
   showLeds( c1, hue++, sizeof( c1 )/2 );
   c_c1 = c_c2;
   showLeds( c2, hue++, sizeof( c2 )/2 );
   c_c2 = c_c3;
   showLeds( c3, hue++, sizeof( c3 )/2 ); 
   c_c3 = rainBow;
   delay( 400 );
 // }
 }
}

void pride() {
 int colour;
 // for ( colour = 0; colour <= NUM_COLORS-1; colour++ ){
  clearAll(0);
  showLeds( letterP, rainbow[colour], sizeof( letterP ) /2 );
  delay(200);
  clearAll(0);
  showLeds( letterR, rainbow[colour], sizeof( letterR ) /2 );
  delay(200);
  clearAll(0);
  showLeds( letterI, rainbow[colour], sizeof( letterI ) /2 );
  delay(200);
  clearAll(0);
  showLeds( letterD, rainbow[colour], sizeof( letterD ) /2 );
  delay(200);
  clearAll(0);
  showLeds( letterE, rainbow[colour], sizeof( letterE ) /2 );
  delay(200);
 // }

}

void spiralShow() {
 int colour = 0, arrSize = sizeof( spiral )/intSize;
 clearAll(0);
 Serial.println( arrSize );
 for ( int j=1; j < 10; j++ ) {
  for ( int x=0; x < ( arrSize ) ; x++ ){
   leds[ spiral[ x ] ] = CHSV(hue++, 255, 255);
   FastLED.show();
  //colour++;
 // if (colour >= NUM_COLORS ) {
  //  colour = 0;
 //   };
  delay( 20 );
  }
 }
}

void cylon(int repeats) { 
  static uint8_t hue = 0;
  clearAll(0);
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
// Nicola
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
*/
