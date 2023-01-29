// rows
#define COLUMN_ON LOW
#define ROW_ON HIGH

int rows[]  = {2, 3, 4};
int columns[]  = {8, 9};
int sizeRows = sizeof(rows)/sizeof(int);
int sizeColumns = sizeof(columns)/sizeof(int);

void setup() {
  for (int i = 0; i < sizeRows; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], !ROW_ON);
  }
  for (int i = 0; i < sizeColumns; i++) {
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], !COLUMN_ON);
  }
}

void selectRow(int num) {
  for (int i = 0; i < sizeRows; i++) {
    if(num == i) {
      digitalWrite(rows[i], ROW_ON);
    }
    else {
      digitalWrite(rows[i], !ROW_ON);
    }
  }
}

void selectColumn(int num) {
  for (int i = 0; i < sizeColumns; i++) {
    if(num == i) {
      digitalWrite(columns[i], COLUMN_ON);
    }
    else {
      digitalWrite(columns[i], !COLUMN_ON);
    }
  }
}

void loop() {
  for (int i = 0; i < sizeRows; i++) {
    selectRow(i);
    for(int j = 0; j < sizeColumns; j++) {
      selectColumn(j);
      delay(200);
    }
  }
}