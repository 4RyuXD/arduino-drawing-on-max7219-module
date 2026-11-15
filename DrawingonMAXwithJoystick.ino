// Include the library
#include <LedControl.h>

// Make the pins into variables
const int din = 12;
const int cs = 11;
const int clk = 52;

// Make the joystick pins into variables
const int joyx = A0;
const int joyy = A1;
const int sw = 13;

// Initialize the MAX7219 module
LedControl lc(din, clk, cs, 1);

// Make variables for the current position and assign the starting point
int ledposy = 7;
int ledposx = 7;

// Set drawmode to false when started
bool drawMode = false;

void setup() {
  // Set up the parameters of the MAX7219 module
  lc.shutdown(0, false);
  lc.setIntensity(0, 3);
  lc.clearDisplay(0);
  
  // Set the starting point
  lc.setLed(0, ledposx, ledposy, true);

  // Set Draw mode toggle pin to input
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  // Read the joystick analog values to determine joystick movements
  int x = analogRead(joyx);
  int y = analogRead(joyy);

  // Check whether drawing mode was toggled or not
  if (digitalRead(sw) == LOW) {
    drawMode = !drawMode;
    delay(500);
  }
  // If draw mode was turned on
  if (drawMode == true) {
    // Update Point position based on y value
    if (y > 550) {
      ledposy--;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (y < 470) {
      ledposy++;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }
    // update point position based on x value
    if (x > 550) {
      ledposx++;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (x < 470) {
      ledposx--;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }
    // send point to other side if boundary is crossed
    if (ledposx == 8) {
      ledposx = 0;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (ledposx == -1) {
      ledposx = 7;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }

    if (ledposy == 8) {
      ledposy = 0;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (ledposy == -1) {
      ledposy = 7;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }
    // else statement to prevent non draw mode and draw mode code clash
  } else {
    // Update led position based on y value of joystick
    if (y > 550) {
      lc.setLed(0, ledposx, ledposy, false);
      ledposy--;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (y < 470) {
      lc.setLed(0, ledposx, ledposy, false);
      ledposy++;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }

  // Update LED position based on joystick movement for the x value
    if(x > 550) {
      lc.setLed(0, ledposx, ledposy, false);
      ledposx++;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (x < 470) {
      lc.setLed(0, ledposx, ledposy, false);
      ledposx--;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }

  // When the LED point crosses its boundary, send the point to the other side
    if (ledposy == 8) {
      ledposy = 0;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (ledposy == -1) {
      ledposy = 7;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }

    if (ledposx == 8) {
      ledposx = 0;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    } else if (ledposx == -1) {
      ledposx = 7;
      lc.setLed(0, ledposx, ledposy, true);
      delay(300);
    }
  }
}





















































































































// Code by Hamdan Naseer (4RyuXD on Github)