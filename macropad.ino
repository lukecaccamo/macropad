#include "Button.h"
#include "Potentiometer.h"
#include "KeyboardMacros.h"

///////////////  Digital pin mapping  ///////////////
#define WHITE_PIN 2
#define YELLOW_PIN 3
#define GREEN_PIN 4
#define RED_PIN 5
#define BLACK_PIN 6
#define BLUE_PIN 7

///////////////  Analog pin mapping   ///////////////
#define DIAL_PIN 0

/////////////// Initialize components ///////////////

// Buttons
Button buttons[] = {
	Button(WHITE_PIN),
	Button(YELLOW_PIN),
	Button(GREEN_PIN),
	Button(RED_PIN),
	Button(BLACK_PIN),
	Button(BLUE_PIN)};
#define NUM_BUTTONS sizeof(buttons) / sizeof(Button)

// Dials
#define DIAL_THRESHOLD 60
Potentiometer dial(DIAL_PIN, DIAL_THRESHOLD);
 
/////////////// --------------------- ///////////////

void pollButtons()
{
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		if (buttons[i].IsPressed())
		{
			switch (buttons[i].pin)
			{
			case WHITE_PIN:
			// Binding for scripts
				doubleMod(KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_HOME);
				break;
			case GREEN_PIN:
			// Binding for scripts
				doubleMod(KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_END);
				break;
			case BLACK_PIN:
			// Binding for scripts
				doubleMod(KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_PAGE_UP);
				break;
			case YELLOW_PIN:
			// Goto Implementation
				shortCut(KEY_LEFT_CTRL, KEY_F12);
				break;
			case RED_PIN:
			// Run unit test
				chord(KEY_LEFT_CTRL, 'u', 'r');
				break;
			case BLUE_PIN:
			// Build
				doubleMod(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 'b');
				break;

			default:
				break;
			}
		}
	}
}

void pollDial()
{
	switch (dial.GetReading())
	{
	case INCREASING:
	// Undo
		shortCut(KEY_LEFT_CTRL, 'z');
		break;
	case DECREASING:
	// Redo
		shortCut(KEY_LEFT_CTRL, 'y');
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
