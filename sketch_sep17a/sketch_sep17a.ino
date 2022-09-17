#include <Keyboard.h>

#define LED_SCROLLLOCK (1 << 2)

char f9Key = KEY_F9; //create rune
char f10Key = KEY_F10; //eat food
char f11Key = KEY_F11; //change ring

long lastMillisRune;
long lastMillisFood;
long lastMillisRing;
long sumMillisToRing = 0;
long sumMillisToFood = 0;
byte pickedIndex;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  delay(5000);
}

void loop() {

  //------------- RUNE -------------
  long millisRuneArray[8] = {35000, 36000, 37000, 38000, 39000, 40000, 41000, 42000};
  pickedIndex = random(8);
  lastMillisRune = millisRuneArray[pickedIndex];

  delay(lastMillisRune);
  pickedIndex = 0;
  Keyboard.press(f9Key);
  // Keyboard.print(F("-RUNE-"));
  delay(100);
  Keyboard.releaseAll();
  //------------- RUNE -------------

  //------------- RING -------------
  sumMillisToRing += lastMillisRune;

  long millisToChangeRing[8] = {540000, 541000, 542000, 550000, 560000, 540200, 548000, 570000};
  pickedIndex = random(8);
  lastMillisRing = millisToChangeRing[pickedIndex];

  if (sumMillisToRing > lastMillisRing){
    pickedIndex = 0;
    sumMillisToRing = 0;
    Keyboard.press(f11Key);
    // Keyboard.print(F("-RING-"));
    delay(100);
    Keyboard.releaseAll();
  }
  //------------- RING -------------

  //------------- FOOD -------------
  sumMillisToFood += lastMillisRune;

  long millisToEatFood[8] = {730000, 720000, 721000, 725000, 720800, 740000, 750000, 720020};
  pickedIndex = random(8);
  lastMillisFood = millisToEatFood[pickedIndex];

  if (sumMillisToFood > lastMillisFood){
    pickedIndex = 0;
    sumMillisToFood = 0;
    Keyboard.press(f10Key);
    // Keyboard.print(F("-FOOD-"));
    delay(100);
    Keyboard.releaseAll();
  }
  //------------- FOOD -------------
}
