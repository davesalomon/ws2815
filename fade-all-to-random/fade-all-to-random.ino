#include <FastLED.h>
#define LED_PIN     6

#define NUM_LEDS    300
#define BRIGHTNESS  100
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
  FadeToColour(rand() % 255, rand() % 255, rand() % 255);
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
