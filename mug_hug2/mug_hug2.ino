
#include <Adafruit_NeoPixel.h>
#ifndef __AVR_ATtiny85__
//#define DEBUG
#endif
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 0
#define STRIP 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  setupTemperature();

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println(getColor(50));

#endif
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show();

  strip.setPixelColor(0, getColor(82));
  strip.show();
  delay(1000);
  strip.setPixelColor(0, getColor(62));
  strip.show();
  delay(1000);
  strip.setPixelColor(0, getColor(42));
  strip.show();
  delay(1000);
  strip.setPixelColor(0, getColor(22));
  strip.show();
  delay(1000);
  strip.setPixelColor(0, getColor(12));
  strip.show();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float celsius = getTemperature();
#ifdef DEBUG
  Serial.println(celsius);
#endif
  for (byte i = 0; i < STRIP; i++) {
    strip.setPixelColor(i, getColor(getTemperature()));
  }
  strip.show();
  delay(500);

}
