#include <Arduino.h>
#define BUTTON D3
#define LED D4

bool led_state = true;
void setup()
{
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, led_state);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Another task
  delay(2000);
  if (digitalRead(BUTTON) == LOW)
  {
    led_state = !led_state;
    digitalWrite(LED, led_state);
    delay(200);
  }
}