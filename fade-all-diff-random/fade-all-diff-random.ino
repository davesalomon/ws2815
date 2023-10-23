#include <FastLED.h>
#define LED_PIN     6
#define NUM_LEDS    100
#define BRIGHTNESS  100
#define LED_TYPE    WS2812
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100
 
int pcarr[NUM_LEDS][3] = {};
int tcarr[NUM_LEDS][3] = {};
int ccarr[NUM_LEDS][3] = {};

int cstep = 0;

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
    ccarr[dot][0] = 0;
    ccarr[dot][1] = 0;
    ccarr[dot][2] = 0;
  }
  FastLED.show();
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    tcarr[dot][0] = rand() % 255;
    tcarr[dot][1] = rand() % 255;
    tcarr[dot][2] = rand() % 255;
  }
  FadeToColour();
}
 
void FadeToColour() {
  for (int i = 0; i < steps; i++) {
    for(int dot = 0; dot < NUM_LEDS;  dot++) { 
      float redDelta = tcarr[dot][0] - pcarr[dot][0];
      redDelta = redDelta / steps;
    
      float greenDelta = tcarr[dot][1] - pcarr[dot][1];
      greenDelta = greenDelta / steps;
    
      float blueDelta = tcarr[dot][2] - pcarr[dot][2];
      blueDelta = blueDelta / steps;
    
      float redCurrent = pcarr[dot][0] + (redDelta * i);
      float greenCurrent = pcarr[dot][1] + (greenDelta * i);
      float blueCurrent = pcarr[dot][2] + (blueDelta * i);
      setColour(redCurrent, greenCurrent, blueCurrent, dot);

      pcarr[dot][0] = redCurrent;
      pcarr[dot][1] = greenCurrent;
      pcarr[dot][2] = blueCurrent;
    }
    FastLED.show();
    delay(fade_delay);  //Delay between steps
  }
  delay(1000); //Wait at peak colour before continuing
}
 
void setColour(int r, int g, int b, int lednum) {
  leds[lednum] = CRGB(r, g, b);
}
