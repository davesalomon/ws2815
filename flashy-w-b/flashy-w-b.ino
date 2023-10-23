#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    300
#define BRIGHTNESS  25
#define LED_TYPE    WS2812
#define COLOR_ORDER RGB
#define DELAY 100
CRGB leds[NUM_LEDS];

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
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    setColour(255, 255, 255, dot);
  }
  FastLED.show();
  delay(DELAY);

  for (int dot = 0; dot < NUM_LEDS; dot++) {
    setColour(255, 0, 0, dot);
  }
  FastLED.show();
  delay(DELAY);

  for (int dot = 0; dot < NUM_LEDS; dot++) {
    setColour(0, 255, 0, dot);
  }
  FastLED.show();
  delay(DELAY);

  for (int dot = 0; dot < NUM_LEDS; dot++) {
    setColour(0, 0, 255, dot);
  }
  FastLED.show();
  delay(DELAY);
    
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    setColour(0,0,0,dot);
  }
  FastLED.show(); 
  delay(DELAY);
}

void setColour(int r, int g, int b, int lednum) {
  leds[lednum] = CRGB(r, g, b);
}