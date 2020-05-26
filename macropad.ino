#include "Keyboard.h"
#include "Button.h"
#include "Potentiometer.h"

// Digital Pin mapping
#define WHITE_PIN 2
#define BLUE_PIN 3

// Analog Pin mapping
#define DIAL_PIN 0

// Initialize components
Button buttons[] = {
	Button(WHITE_PIN),
	Button(BLUE_PIN)};
#define NUM_BUTTONS sizeof(buttons) / sizeof(Button)

#define DIAL_THRESHOLD 75
Potentiometer dial(DIAL_PIN, DIAL_THRESHOLD);

void pollButtons()
{
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		if (buttons[i].IsPressed())
		{
			switch (buttons[i].pin)
			{
			case WHITE_PIN:
				Serial.println("W Pressed");
				break;
			case BLUE_PIN:
				Serial.println("B Pressed");
				break;
			default:
				break;
			}
		}
	}
}

void pollDial()
{
	switch (dial.TakeReading())
	{
	case INCREASING:
		Serial.println("INC");
		dial.PrintReading();
		break;
	case DECREASING:
		Serial.println("DEC");
		dial.PrintReading();
		break;
	default:
		break;
	}
}

void setup()
{
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		pinMode(buttons[i].pin, INPUT_PULLUP);
	}

	Keyboard.begin();
}

void loop()
{
	pollButtons();
	pollDial();
}
