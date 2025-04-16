#ifndef LED_H
#define LED_H

#include <FastLED.h>

#define LED_PIN     25   // Новый пин
#define NUM_LEDS    60   // 60 светодиодов
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

extern CRGB leds[NUM_LEDS];

void setupLedStrip();
void ledRed();
void ledGreen();
void ledBlue_blink();

#endif
