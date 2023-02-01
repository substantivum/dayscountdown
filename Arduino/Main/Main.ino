#include <ThingerESP32.h>

#define COLUMN_ON LOW
#define ROW_ON HIGH

int columns1[]  = {2, 2, 2};
int rows1[]  = {2, 2, 2, 2, 2};
int columns2[]  = {2, 2, 2};
int rows2[]  = {2, 2, 2, 2, 2};
const int columnLength = sizeof(columns1)/sizeof(int);
const int rowLength = sizeof(rows1)/sizeof(int);

byte bitmap1[rowLength][columnLength];
byte bitmap2[rowLength][columnLength];
int numberOfDays[] = {0,0}; // Split the number into two digits
int _numberOfDays = 0; // Internal tracker
int arrowDir = 0;
int currentDayOfTheWeek = 0;

void setup(){
  Serial.begin(9600);

  // Setup led pins
  for (int i = 0; i < rowLength; i++) {
      pinMode(rows1[i], OUTPUT);
      pinMode(rows2[i], OUTPUT);
  }
  for (int i = 0; i < columnLength; i++) {
      pinMode(columns1[i], OUTPUT);
      pinMode(columns2[i], OUTPUT);
  }

  // Clear both screens
  ClearScreen(rows1, columns1);
  ClearScreen(rows2, columns2);

  ThingerSetupFunction();

  currentDayOfTheWeek = GetCurrentDay();

  NewCountdownRecieved(15, 1); // Delete me, only for testing
}

void loop() {
  if (HasDateChanged()) {
    // Update display
    _numberOfDays -= 1;
    NewCountdownRecieved(_numberOfDays, arrowDir);
  }

  ThingerLoopFunction();

  // Show the screen
  DisplayDaysOnScreen();
}


