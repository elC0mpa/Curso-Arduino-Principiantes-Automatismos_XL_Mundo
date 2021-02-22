#include <Arduino.h>
#define BUTTON D3
#define LED D4

bool led_state = true;

// If Arduino board - > delete ICACHE_RAM_ATTR
void ICACHE_RAM_ATTR buttonPressed()
{
  led_state = !led_state;
  digitalWrite(LED, led_state);
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  if (digitalPinToInterrupt(BUTTON) != NOT_AN_INTERRUPT)
  {
    attachInterrupt(BUTTON, buttonPressed, FALLING);
    // FALLING -> 1 -> 0
    digitalWrite(LED, led_state);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Another task
  delay(2000);
}