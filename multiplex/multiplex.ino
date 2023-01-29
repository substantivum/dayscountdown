#define COLUMN_ON LOW
#define ROW_ON HIGH

int columns[]  = {8, 9};
int rows[]  = {2, 3, 4};
int columnLength = sizeof(columns)/sizeof(int);
int rowLength = sizeof(rows)/sizeof(int);

int bitmap1[3][2] = {
    {1, 0},
    {1, 0},
    {1, 1},
};

void setup(){
    for (int i = 0; i < rowLength; i++) {
        pinMode(rows[i], OUTPUT);
        digitalWrite(rows[i], !ROW_ON);
    }
    for (int i = 0; i < columnLength; i++) {
        pinMode(columns[i], OUTPUT);
        digitalWrite(columns[i], !COLUMN_ON);
    }
}

void loop() {
    ShowBitmap(bitmap1);
}

void ShowBitmap(int[][] bitmap) {
    for (int i = 0; i < rowLength; i++) {
        SelectRow(i);
        for (int j = 0; j < columnLength; j++) {
            SetColumnState(i, bitmap[i][j]);
        }
        delay(2);
    }
}

void SelectRow(int row, bool turnOffOthers = true) {
    for (int i = 0; i < rowLength; i++) {
        if (i == row) {
            digitalWrite(rows[i], ROW_ON);
        } else if (turnOffOthers) {
            digitalWrite(rows[i], !ROW_ON);
        }
    }
}

void SelectColumn(int column, bool turnOffOthers = true) {
    for (int i = 0; i < columnLength; i++) {
        if (i == column) {
            digitalWrite(columns[i], COLUMN_ON);
        } else if (turnOffOthers) {
            digitalWrite(columns[i], !COLUMN_ON);
        }
    }
}

void SetColumnState(int column, int state) {
    for (int i = 0; i < columnLength; i++) {
        if (i == column) {
            digitalWrite(columns[i], state);
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

void ClearScreen() {
    for (int i = 0; i < rowLength; i++) {
        digitalWrite(rows[i], !ROW_ON);
    }

    for (int j = 0; j < columnLength; j++) {
        digitalWrite(columns[i], !COLUMN_ON);
    }
}