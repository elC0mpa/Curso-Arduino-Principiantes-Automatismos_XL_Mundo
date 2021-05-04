#include <Arduino.h>
#include <TimerOne.h>

bool led_state = false;

void blinkLED(void)
{
  led_state = !led_state;
  digitalWrite(LED_BUILTIN, led_state);
}

void setup(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, led_state);
  Timer1.initialize(2000000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
}


void loop(void)
{
}