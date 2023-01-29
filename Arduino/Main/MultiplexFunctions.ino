void ShowBitmap(byte bitmap[rowLength][columnLength]) {
    for (int i = 0; i < rowLength; i++) {
        SelectRow(i);
        for (int j = 0; j < columnLength; j++) {
            SetColumnState(j, bitmap[i][j]);
        }
        delay(2);
        ClearColumns();
    }
}

void SelectRow(int row) {
    for (int i = 0; i < rowLength; i++) {
        if (i == row) {
            digitalWrite(rows[i], ROW_ON);
        } else {
            digitalWrite(rows[i], !ROW_ON);
        }
    }
}

void SelectColumn(int column) {
    for (int i = 0; i < columnLength; i++) {
        if (i == column) {
            digitalWrite(columns[i], COLUMN_ON);
        } else {
            digitalWrite(columns[i], !COLUMN_ON);
        }
    }
}

void SetColumnState(int column, int state) {
    for (int i = 0; i < columnLength; i++) {
        if (i == column) {
            digitalWrite(columns[i], !state);
            break;
        }
    }
}

void SetRowState(int row, int state) {
    for (int i = 0; i < rowLength; i++) {
        if (i == row) {
            digitalWrite(rows[i], state);
            break;
        }
    }
}

void ClearRows() {
    for (int i = 0; i < rowLength; i++) {
        digitalWrite(rows[i], !ROW_ON);
    }
}

void ClearColumns() {
    for (int i = 0; i < columnLength; i++) {
        digitalWrite(columns[i], !COLUMN_ON);
    }
}

void ClearScreen() {
    ClearRows();
    ClearColumns();
}
