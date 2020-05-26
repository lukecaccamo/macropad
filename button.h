#define DEBOUNCE_DELAY 25

unsigned long lastDebounceTime = 0;

class Button
{
public:
	uint8_t pin;

	Button(uint8_t pin)
	{
		this->pin = pin;
		this->state = LOW;
		this->lastState = LOW;
	}

	bool IsPressed()
	{
		this->reading = digitalRead(this->pin);

		if (this->reading != this->lastState)
		{
			lastDebounceTime = millis();
		}

		if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY && this->reading != this->state)
		{
			this->state = this->reading;
			this->lastState = this->reading;
			return this->state == LOW;
		}

		this->lastState = this->reading;

		return false;
	}

private:
	uint8_t reading;
	uint8_t state;
	uint8_t lastState;
};