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
  setColour(255, 0, 0);
  setColour(255, 127, 0);
  setColour(255, 255, 0);
  setColour(0, 255, 0);
  setColour(0, 0, 255);
  setColour(127, 0, 255);
  setColour(255, 0, 255);
}
 
void setColour(int r, int g, int b) {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = CRGB(r, g, b);
  }
  FastLED.show();

  delay(150);
}
