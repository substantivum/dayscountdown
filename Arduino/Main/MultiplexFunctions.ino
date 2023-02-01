void DisplayDaysOnScreen() {
  ShowBitmapOnScreen(rows1, columns1, bitmap1);
  ShowBitmapOnScreen(rows2, columns2, bitmap2);
}

void ShowBitmapOnScreen(int rows[rowLength], int columns[columnLength], byte bitmap[rowLength][columnLength]) {
    for (int i = 0; i < rowLength; i++) {
        SelectRow(i, rows);
        for (int j = 0; j < columnLength; j++) {
            SetColumnState(j, bitmap[i][j], columns);
        }
        delay(2);
        ClearColumns(columns);
    }
}

void SelectRow(int row, int rows[rowLength]) {
    for (int i = 0; i < rowLength; i++) {
        if (i == row) {
            digitalWrite(rows[i], ROW_ON);
        } else {
            digitalWrite(rows[i], !ROW_ON);
        }
    }
}

void SelectColumn(int column, int columns[columnLength]) {
    for (int i = 0; i < columnLength; i++) {
        if (i == column) {
            digitalWrite(columns[i], COLUMN_ON);
        } else {
            digitalWrite(columns[i], !COLUMN_ON);
        }
    }
}

void SetRowState(int row, int state, int rows[rowLength]) {
    for (int i = 0; i < rowLength; i++) {
        if (i == row) {
            digitalWrite(rows[i], state);
            break;
        }
    }
}

void SetColumnState(int column, int state, int columns[columnLength]) {
    for (int i = 0; i < columnLength; i++) {
        if (i == column) {
            digitalWrite(columns[i], !state);
            break;
        }
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
