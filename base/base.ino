#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    300
#define BRIGHTNESS  25
#define LED_TYPE    WS2812
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100
 
//Previous value of RGB
int redPrevious, greenPrevious, bluePrevious = 0;
 
//Current value of RGB
float redCurrent, greenCurrent, blueCurrent = 0;
 
//Target value of RGB
int redTarget, greenTarget, blueTarget = 0;
 
int fade_delay = 10;
int steps = 100;
 
void setup() { 
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = CRGB::Black;
  }
  FastLED.show();

  FastLED.setBrightness(BRIGHTNESS);
  
}
void loop() { 
  // FadeToColour(rand() % 255, rand() % 255, rand() % 255);


  // FadeToColour(0, 255, 0);

  // FadeToColour(255, 255, 255);

  // for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour(255, 0, 255, dot);
  //   FastLED.show();
  //   delay(50);
  // }

  // for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour(255, 0, 0, dot);
  //   FastLED.show();
  //   delay(50);
  // }

  for (int dot = 0; dot < NUM_LEDS; dot++) {
    int colr = rand() % 255;
    int colg = rand() % 255;
    int colb = rand() % 255;
    setColour( colr, colg, colb, dot);
    // FastLED.show();
    // setColour(0,0,0,dot);
    FastLED.show(); 
  }
 
  // delay(25);
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    setColour(0,0,0,dot);
    FastLED.show(); 
  }
  FastLED.show();
  // delay(25);

  // for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour(127, 255, 127, dot);
  // }
  // FastLED.show();

  // delay(500);

  //   for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour( 0, 0, 0, dot);
  // }
  // FastLED.show();

  // delay(500);

  // for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour( 0, 0, 255, dot);
  // }
  // FastLED.show();

  // delay(1000);

  // for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour( 255, 0, 0, dot);
  // }
  // FastLED.show();

  // delay(1000);


  // for (int dot = 0; dot < NUM_LEDS; dot++) {
  //   setColour(0, 0, 0, dot);
  // }
  // FastLED.show();

  // delay(500);
}
 
void FadeToColour(int r, int g, int b) {
  redPrevious = redCurrent;
  greenPrevious = greenCurrent;
  bluePrevious = blueCurrent;
 
  redTarget = r;
  greenTarget = g;
  blueTarget = b;
 
  float redDelta = redTarget - redPrevious;
  redDelta = redDelta / steps;
 
  float greenDelta = greenTarget - greenPrevious;
  greenDelta = greenDelta / steps;
 
  float blueDelta = blueTarget - bluePrevious;
  blueDelta = blueDelta / steps;
 
  for (int j = 1; j < steps; j++) {
    redCurrent = redPrevious + (redDelta * j);
    greenCurrent = greenPrevious + (greenDelta * j);
    blueCurrent = bluePrevious + (blueDelta * j);
      for(int dot = 0; dot < NUM_LEDS; dot++) { 
        setColour(redCurrent, greenCurrent, blueCurrent, dot);
      }
      FastLED.show();
      delay(fade_delay);  //Delay between steps
  }
  delay(1000); //Wait at peak colour before continuing
}
 
void setColour(int r, int g, int b, int lednum) {
  leds[lednum] = CRGB(r, g, b);
}


/*
#include <FastLED.h>
#define NUM_LEDS 300

#define LED_TYPE WS2812
#define COLOR_ORDER RGB
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
void setup() {  
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = CRGB::Blue;
  }
  FastLED.show();
}
*/