void DisplayDaysOnScreen() {
  ShowBitmapOnScreen(rows, columns, bitmap);
}

unsigned long long bitmapTimer = millis();
unsigned long long bitmapTimerDelay = 2;
int selectedRow = 0;
void ShowBitmapOnScreen(int rows[rowLength], int columns[columnLength], byte bitmap[rowLength][columnLength]) {
  if ((millis() - bitmapTimer + 1) > bitmapTimerDelay) {
    for (int j = 0; j < columnLength; j++) {
        SetColumnState(j, bitmap[selectedRow][j], columns);
    }
    SelectRow(selectedRow, rows);

    selectedRow = (selectedRow+1) % rowLength;

    bitmapTimer = millis();
  }
}

/*
void ShowBitmapOnScreen(int rows[rowLength], int columns[columnLength], byte bitmap[rowLength][columnLength]) {
    for (int i = 0; i < rowLength; i++) {
          SelectRow(i, rows);
          for (int j = 0; j < columnLength; j++) {
              SetColumnState(j, bitmap[i][j], columns);
          }
          delay(2);
          ClearColumns(columns);
    }
}*/

void SelectRow(int row, int rows[rowLength]) {
    for (int i = 0; i < rowLength; i++) {
        if (i == row) {
            digitalWrite(rows[i], ROW_ON);
        } else {
            digitalWrite(rows[i], !ROW_ON);
        }
    }
}

void SetColumnState(int column, int state, int columns[columnLength]) {
  if (state == 1) {
    digitalWrite(columns[column], COLUMN_ON);
  } else {
    digitalWrite(columns[column], !COLUMN_ON);
  }
}

void ClearRows(int rows[rowLength]) {
    for (int i = 0; i < rowLength; i++) {
        digitalWrite(rows[i], !ROW_ON);
    }
}

void ClearColumns(int columns[columnLength]) {
    for (int i = 0; i < columnLength; i++) {
        digitalWrite(columns[i], !COLUMN_ON);
    }
}

void ClearScreen(int rows[rowLength], int columns[columnLength]) {
    ClearRows(rows);
    ClearColumns(columns);
}
