#include <ThingerESP32.h>

#define COLUMN_ON LOW
#define ROW_ON HIGH

int columns[]  = {2, 2, 2};
int rows[]  = {2, 2, 2, 2, 2};
const int columnLength = sizeof(columns)/sizeof(int);
const int rowLength = sizeof(rows)/sizeof(int);

byte bitmap1[rowLength][columnLength];
int numberOfDays = 0;
int arrowDir = 0;

void UpdateDigits() {
  SetBitmap(numberOfDays, bitmap1);
  PrintBitmap(bitmap1);
}

void setup(){
    Serial.begin(9600);

    // Setup led pins
    for (int i = 0; i < rowLength; i++) {
        pinMode(rows[i], OUTPUT);
        digitalWrite(rows[i], !ROW_ON);
    }
    for (int i = 0; i < columnLength; i++) {
        pinMode(columns[i], OUTPUT);
        digitalWrite(columns[i], !COLUMN_ON);
    }

    ThingerSetupFunction();
}

void loop() {
    ShowBitmap(bitmap1);

    ThingerLoopFunction();
}

