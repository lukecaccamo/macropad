enum DialStatus
{
	NONE,
	INCREASING,
	DECREASING
};

class Potentiometer
{
public:
	uint8_t pin;
	// Reading is between 0 and 1023
	short reading;
	short lastReading;
	// Number of values to skip before registering a turn
	int threshold;

	Potentiometer(uint8_t pin, int threshold)
	{
		this->pin = pin;
		this->reading = 0;
		this->lastReading = 0;
		this->threshold = threshold;
	}

	void PrintReading()
	{
		Serial.println(this->reading);
	}

	DialStatus TakeReading()
	{
		this->reading = analogRead(this->pin);

		if (IsIncreasing())
		{
			this->lastReading = this->reading;
			return INCREASING;
		}
		else if (IsDecreasing())
		{
			this->lastReading = this->reading;
			return DECREASING;
		}

		return NONE;
	}

private:
	bool IsIncreasing()
	{
		return this->reading > this->lastReading && (this->reading - this->lastReading) > this->threshold;
	}

	bool IsDecreasing()
	{
		return this->reading < this->lastReading && (this->lastReading - this->reading) > this->threshold;
	}
};