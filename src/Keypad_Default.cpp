#include "Config.h"

#include "Keypad_Default.h"

DefaultKeypad::DefaultKeypad(int back, int select, int up, int down) {
  pin_back = back;
  pin_select = select;
  pin_up = up;
  pin_down = down;
  pinMode(back,INPUT);
  pinMode(select,INPUT);
  pinMode(up,INPUT);
  pinMode(down,INPUT);
}
int DefaultKeypad::getPressedButton() {
  int return_pin = 0;
  if(DefaultKeypad::isButtonPressed(DefaultKeypad::KEY_BACK)) {
    return_pin = pin_back;
  }
  if(DefaultKeypad::isButtonPressed(DefaultKeypad::KEY_SELECT)) {
    return_pin = pin_select;
  }
  if(DefaultKeypad::isButtonPressed(DefaultKeypad::KEY_BUP)) {
    return_pin = pin_up;
  }
  if(DefaultKeypad::isButtonPressed(DefaultKeypad::KEY_BDOWN)) {
    return_pin = pin_down;
  }
  if(return_pin != 0) {
    _updateLastButtonTime();
  }
  return return_pin;
}
boolean DefaultKeypad::isButtonPressed(enum Buttons btn_label) {
  int checkPin;
  switch(btn_label) {
    case KEY_BACK:
    checkPin = pin_back;
    break; 
    case KEY_SELECT:
    checkPin = pin_select;
    break;
    case KEY_BUP:
    checkPin = pin_up;
    break;
    case KEY_BDOWN:
    checkPin = pin_down;
    break;
    
  }
  boolean isButtonPressed = (digitalRead(checkPin) == HIGH);
  if(isButtonPressed) {
    _updateLastButtonTime();
  }
  return isButtonPressed;
}
unsigned long DefaultKeypad::getButtonIdleTime() {
  return millis() - _lastButtonTime;
}
void DefaultKeypad::_updateLastButtonTime() {
  _lastButtonTime = millis();
}

