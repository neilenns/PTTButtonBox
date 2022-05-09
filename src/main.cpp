#include <Arduino.h>
#include <Joystick.h>

// The build version comes from an environment variable. Use the VERSION
// define wherever the version is needed.
#define STRINGIZER(arg) #arg
#define STR_VALUE(arg) STRINGIZER(arg)
#define VERSION STR_VALUE(BUILD_VERSION)

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 1, 0, false, false, false, false, false, false, false, false, false, false, false);

constexpr uint8_t pttButtonPin = 14;

void setup()
{
  delay(5000);
  Serial.begin(115200);
  Serial.print("Version: ");
  Serial.println(VERSION);

  pinMode(pttButtonPin, INPUT_PULLUP);

  Joystick.begin();
}

int lastButtonState = 0;

void loop()
{
  int currentButtonState = !digitalRead(pttButtonPin);

  if (currentButtonState != lastButtonState)
  {
    Joystick.setButton(0, currentButtonState);
    lastButtonState = currentButtonState;
  }

  delay(200);
}