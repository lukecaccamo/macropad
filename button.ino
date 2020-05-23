#include "Keyboard.h"
#include "button.h"

#define WHITE_PIN 2
#define BLUE_PIN 3

Button buttons[] = {
	Button(WHITE_PIN),
	Button(BLUE_PIN)
};

#define NUM_BUTTONS sizeof(buttons)

uint8_t buttonReading = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup()
{
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		pinMode(buttons[i].pin, INPUT_PULLUP);
	}
}

void loop()
{

	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		Button *currButton = &buttons[i];

		buttonReading = digitalRead(currButton->pin);

		if (buttonReading != currButton->lastState)
		{
			lastDebounceTime = millis();
		}

		if ((millis() - lastDebounceTime) > debounceDelay && buttonReading != currButton->state)
		{

			currButton->state = buttonReading;

			if (currButton->state == LOW)
			{
				switch (currButton->pin)
				{
				case WHITE_PIN:
					Serial.println("White pressed");
					break;
				case BLUE_PIN:
					Serial.println("Blue pressed");
					break;
				default:
					break;
				}
			}
		}

		currButton->lastState = buttonReading;
	}
}
