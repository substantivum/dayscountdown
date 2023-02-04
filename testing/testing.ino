// rows
#define COLUMN_ON HIGH
#define ROW_ON LOW
#define ARROW_ON HIGH
 
int rows[]  = {27, 26, 25, 33, 32};
int columns[]  = {14, 12, 13, 19, 21, 18};
const int sizeRows = sizeof(rows)/sizeof(int);
const int sizeColumns = sizeof(columns)/sizeof(int);

int arrowsPositive[] = {2, 4};
int arrowsNegative[] = {15, 0};

void setup() {
  for (int i = 0; i < sizeRows; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], !ROW_ON);
  }
  for (int i = 0; i < sizeColumns; i++) {
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], !COLUMN_ON);
  }

  pinMode(arrowsPositive[0], OUTPUT);
  pinMode(arrowsPositive[1], OUTPUT);
  pinMode(arrowsNegative[0], OUTPUT);
  pinMode(arrowsNegative[1], OUTPUT);
  digitalWrite(arrowsPositive[0], !ARROW_ON);
  digitalWrite(arrowsPositive[1], !ARROW_ON);
  digitalWrite(arrowsNegative[0], !ARROW_ON);
  digitalWrite(arrowsNegative[1], !ARROW_ON);
}

int bitmap[5][6] = {
  {0,0,0,0,1,0},
  {0,0,0,1,0,1},
  {0,0,0,0,1,0},
  {0,0,0,1,0,1},
  {0,0,0,0,1,0}
};


void loop() {
  for (int i = 0; i < sizeRows; i++) {
    for (int j = 0; j < sizeColumns; j++) {
      SetColumnState(j, bitmap[i][j], columns);
    }
    SelectRow(i, rows);
    delay(2);
  }
}

void SetColumnState(int column, int state, int columns[sizeColumns]) {
  if (state == 1) {
    digitalWrite(columns[column], COLUMN_ON);
  } else {
    digitalWrite(columns[column], !COLUMN_ON);
  }
}

void SelectRow(int row, int rows[sizeRows]) {
    for (int i = 0; i < sizeRows; i++) {
        if (i == row) {
            digitalWrite(rows[i], ROW_ON);
        } else {
            digitalWrite(rows[i], !ROW_ON);
        }
    }
}


/*
void loop() {
  for (int i = 0; i < sizeRows; i++) {
    digitalWrite(rows[i], ROW_ON);
    for(int j = 0; j < sizeColumns; j++) {
      digitalWrite(columns[j], COLUMN_ON);
      delay(200);
      digitalWrite(columns[j], !COLUMN_ON);
    }
    digitalWrite(rows[i], !ROW_ON);
  }

  for (int i = 0; i < 2; i++) {
    digitalWrite(arrowsPositive[i], ARROW_ON);
    delay(200);
    digitalWrite(arrowsPositive[i], !ARROW_ON);
  }
}
*/