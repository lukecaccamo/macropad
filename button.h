class Button
{
public:
    uint8_t pin;
    uint8_t state;
    uint8_t lastState;

    Button(uint8_t pin)
    {
        this->pin = pin;
        this->state = LOW;
        this->lastState = LOW;
    }
};