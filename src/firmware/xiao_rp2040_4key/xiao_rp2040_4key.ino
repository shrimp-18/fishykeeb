#include "Keyboard.h"

const uint8_t KEY_PINS[4] = {D4, D7, D8, D10};
enum KeyAction { SINGLE_KEY, COMBO_KEY };

struct KeyMap {
  KeyAction type;
  uint8_t modifier;
  uint8_t key;
};

KeyMap keymap[4] = {
  { SINGLE_KEY, 0,             'a' },               
  { SINGLE_KEY, 0,             'b' },               
  { SINGLE_KEY, 0,             KEY_RETURN },          
  { COMBO_KEY,  KEY_LEFT_CTRL, 'c' },                 
};

const uint16_t DEBOUNCE_MS = 15;

bool lastReading[4]   = {HIGH, HIGH, HIGH, HIGH};
bool stableState[4]   = {HIGH, HIGH, HIGH, HIGH};
unsigned long lastChangeTime[4] = {0, 0, 0, 0};

void sendKey(const KeyMap &km, bool press) {
  if (km.type == SINGLE_KEY) {
    if (press) Keyboard.press(km.key);
    else       Keyboard.release(km.key);
  } else {
    if (press) {
      Keyboard.press(km.modifier);
      Keyboard.press(km.key);
    } else {
      Keyboard.release(km.key);
      Keyboard.release(km.modifier);
    }
  }
}

void setup() {
  for (uint8_t i = 0; i < 4; i++) {
    pinMode(KEY_PINS[i], INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop() {
  unsigned long now = millis();

  for (uint8_t i = 0; i < 4; i++) {
    bool reading = digitalRead(KEY_PINS[i]);

    if (reading != lastReading[i]) {
      lastChangeTime[i] = now;
      lastReading[i] = reading;
    }

    if ((now - lastChangeTime[i]) > DEBOUNCE_MS && reading != stableState[i]) {
      stableState[i] = reading;

      if (stableState[i] == LOW) {
        sendKey(keymap[i], true);
      } else {
        sendKey(keymap[i], false);
      }
    }
  }
}
