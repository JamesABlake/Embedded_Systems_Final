#include "Game.h"
#include "JoyStick.h"
#include <MD_MAX72xx.h>
#include <new.h>

#define pinJoyX A13
#define pinJoyY A14
#define pinJoyS A15

#define pinRand A7

#define pinCLK A2
#define pinData A0
#define pinCS A1

JoyStick joyStick(pinJoyX, pinJoyY, pinJoyS);
MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::PAROLA_HW, pinData, pinCLK, pinCS, 1);
Game game;

uint8_t buffer[8];

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 8);
  randomSeed(analogRead(pinRand));
  game.Setup();
}

void loop() {
  // Reset the game when the button is pressed.
  if (joyStick.ButtonDown()) {
    ResetGame();
  }

  // If there's input, put it into result and pass it to the game.
  Point result = (Point){ 0, 0 };
  if (joyStick.GetInput(&result))
    game.direction = result;

  if (game.Update()) {
    ResetGame();
  }

  // Pass visuals from the game to the display
  // Note: The screen is drawn right to left so this needs to be set to the last
  // column and the buffer created inverted
  game.GetVisuals(buffer);
  mx.setBuffer(7, 8, buffer);
}

void ResetGame() {
  game.~Game();
  new (&game) Game();
  game.Setup();
}
