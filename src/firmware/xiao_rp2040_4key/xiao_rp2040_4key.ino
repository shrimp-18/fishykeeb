
#include "Keyboard.h"
#include <Adafruit_NeoPixel.h>

const uint8_t KEY_PINS[4] = {D4, D7, D8, D10};
enum KeyAction { SINGLE_KEY, COMBO_KEY };

struct KeyMap {
  KeyAction type;
  uint8_t modifier;   
  uint8_t key;       
};

KeyMap keymap[4] = {
  { SINGLE_KEY, 0,             'a' },                 // SW1 -> 'a'
  { SINGLE_KEY, 0,             'b' },                 // SW2 -> 'b'
  { SINGLE_KEY, 0,             KEY_RETURN },           // SW3 -> Enter
  { COMBO_KEY,  KEY_LEFT_CTRL, 'c' },                  // SW4 -> Ctrl+C
};


const uint16_t DEBOUNCE_MS = 15;

bool lastReading[4]   = {HIGH, HIGH, HIGH, HIGH};
bool stableState[4]   = {HIGH, HIGH, HIGH, HIGH};
unsigned long lastChangeTime[4] = {0, 0, 0, 0};
-
#define LED_PIN     D3
#define LED_COUNT   2

const uint8_t BACKLIGHT_R = 20;
const uint8_t BACKLIGHT_G = 20;
const uint8_t BACKLIGHT_B = 30;

const uint8_t BACKLIGHT_BRIGHTNESS = 40;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

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

  strip.begin();
  strip.setBrightness(BACKLIGHT_BRIGHTNESS);
  for (uint8_t i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(BACKLIGHT_R, BACKLIGHT_G, BACKLIGHT_B));
  }
  strip.show();
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
