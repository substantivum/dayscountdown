#include <ThingerESP32.h>

#define COLUMN_ON HIGH
#define ROW_ON LOW
#define ARROW_ON HIGH
 
int columns[]  = {14, 12, 13, 21, 19, 18};
int rows[]  = {27, 26, 25, 33, 32};
const int columnLength = sizeof(columns)/sizeof(int);
const int rowLength = sizeof(rows)/sizeof(int);

int arrowsPositive[] = {4, 2};
int arrowsNegative[] = {15, 0};

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
  for (int i = 0; i < 2; i++) {
    pinMode(arrowsPositive[i], OUTPUT);
    pinMode(arrowsNegative[i], OUTPUT);
    digitalWrite(arrowsPositive[i], !ARROW_ON);
    digitalWrite(arrowsNegative[i], !ARROW_ON);
  }

  // Clear both screens
  ClearScreen(rows, columns);

  ThingerSetupFunction();

  currentDay = GetCurrentDay();

  NewCountdownRecieved(_numberOfDays, 1);
}

void loop() {
  if (HasDateChanged()) {
    // Update display
    _numberOfDays -= 1;
    NewCountdownRecieved(_numberOfDays, arrowRight);
  }

  // Show the screen
  DisplayDaysOnScreen();

  // Check if we should change arrow direction
  HandleArrow();

  ThingerLoopFunction();
}


