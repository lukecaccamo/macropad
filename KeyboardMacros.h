// Need Keyboard v1.0.2+
#include "Keyboard.h"

#define NUMPAD_SLASH 220 // Keypad /
#define NUMPAD_STAR 221 // Keypad *
#define NUMPAD_MINUS 222 // Keypad -
#define NUMPAD_PLUS 223 // Keypad +
#define NUMPAD_ENTER 224 // Keypad ENTER
#define NUMPAD_1 225 // Keypad 1 and End
#define NUMPAD_2 226 // Keypad 2 and Down Arrow
#define NUMPAD_3 227 // Keypad 3 and PageDn
#define NUMPAD_4 228 // Keypad 4 and Left Arrow
#define NUMPAD_5 229 // Keypad 5
#define NUMPAD_6 230 // Keypad 6 and Right Arrow
#define NUMPAD_7 231 // Keypad 7 and Home
#define NUMPAD_8 232 // Keypad 8 and Up Arrow
#define NUMPAD_9 233 // Keypad 9 and PageUp
#define NUMPAD_0 234 // Keypad 0 and Insert
#define NUMPAD_DELETE 235 // Keypad . and Delete

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


