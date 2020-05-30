// Need Keyboard v1.0.2+
#include "Keyboard.h"

void pressAndRelease(uint8_t key)
{
    Keyboard.press(key);
    Keyboard.releaseAll();
}

void shortCut(uint8_t modifier, uint8_t key) 
{
    Keyboard.press(modifier);
    Keyboard.press(key);
    Keyboard.releaseAll();
}

void doubleMod(uint8_t modifier1, uint8_t modifier2, uint8_t key) 
{
    Keyboard.press(modifier1);
    Keyboard.press(modifier2);
    Keyboard.press(key);
    Keyboard.releaseAll();
}

void chord(uint8_t modifier, uint8_t key1, uint8_t key2) 
{
    Keyboard.press(modifier);

    Keyboard.press(key1);
    Keyboard.release(key1);
       
    Keyboard.press(key2);
    Keyboard.releaseAll();
}


