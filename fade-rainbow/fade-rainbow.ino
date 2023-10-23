#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    300
#define BRIGHTNESS  100
#define LED_TYPE    WS2812
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
 
//Previous value of RGB
int redPrevious, greenPrevious, bluePrevious = 0;
 
//Current value of RGB
float redCurrent, greenCurrent, blueCurrent = 0;
 
//Target value of RGB
int redTarget, greenTarget, blueTarget = 0;
 
int fade_delay = 0;
int steps = 16;
 
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
  FadeToColour(255, 0, 0);
  FadeToColour(255, 127, 0);
  FadeToColour(255, 255, 0);
  FadeToColour(0, 255, 0);
  FadeToColour(0, 0, 255);
  FadeToColour(127, 0, 255);
  FadeToColour(255, 0, 255); 
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
}
 
void setColour(int r, int g, int b, int lednum) {
  leds[lednum] = CRGB(r, g, b);
}
