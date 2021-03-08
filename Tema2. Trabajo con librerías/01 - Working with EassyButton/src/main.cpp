/*
  Name:		PressedForDuration.ino
  Created:	9/5/2018 10:49:52 AM
  Author:	Evert Arias
  Description: Example to demostrate how to use the library to detect a pressed for a given duration on a button.
*/
#include <Arduino.h>
#include <EasyButton.h>

// Arduino pin where the button is connected to.
#define BUTTON_PIN D3
#define LED_PIN D4
// Instance of the button.
EasyButton button(BUTTON_PIN, 100);
// Callback function to be called when the button is pressed.
void onPressedForDuration()
{
  digitalWrite(LED_PIN, LOW);
}

void onSequence()
{
  digitalWrite(LED_PIN, HIGH);
}

void setup()
{
  // Initialize the button.
  button.begin();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  // Add the callback function to be called when the button is pressed for at least the given time.
  button.onPressedFor(2000, onPressedForDuration);
  button.onSequence(2, 1500, onSequence);
}

void loop()
{
  // Continuously read the status of the button.
  button.read();
}