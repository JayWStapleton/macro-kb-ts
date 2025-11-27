#include <Keyboard.h>

const int switch_pin_1 = 16;
const int switch_pin_2 = 9;

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  bitClear(DDRD,5);
  bitClear(DDRB,0);

  if (digitalRead(9) == 0) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('R');
    delay(150);
    Keyboard.releaseAll();
    
  } else if (digitalRead(15) == 0) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('T');
    delay(150);
    Keyboard.releaseAll();
  }
}
