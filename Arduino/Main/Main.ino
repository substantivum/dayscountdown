#include <ThingerESP32.h>

#define COLUMN_ON LOW
#define ROW_ON HIGH

int columns[]  = {2, 2, 2, 2, 2, 2};
int rows[]  = {2, 2, 2, 2, 2};
const int columnLength = sizeof(columns)/sizeof(int);
const int rowLength = sizeof(rows)/sizeof(int);

byte bitmap[rowLength][columnLength];
int numberOfDays[] = {0,0}; // Split the number into two digits
int _numberOfDays = 0; // Internal tracker
int arrowRight = 0;
int currentDay = 0;

void setup(){
  Serial.begin(9600);

  // Setup led pins
  for (int i = 0; i < rowLength; i++) {
      pinMode(rows[i], OUTPUT);
  }
  for (int i = 0; i < columnLength; i++) {
      pinMode(columns[i], OUTPUT);
  }

  // Clear both screens
  ClearScreen(rows, columns);

  ThingerSetupFunction();

  currentDay = GetCurrentDay();
}

void loop() {
  if (HasDateChanged()) {
    // Update display
    _numberOfDays -= 1;
    NewCountdownRecieved(_numberOfDays, arrowRight);
  }

  ThingerLoopFunction();

  // Show the screen
  DisplayDaysOnScreen();
}


