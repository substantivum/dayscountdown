byte ZERO[5][3]= {
  {0,1,0},
  {1,0,1},
  {0,0,0},
  {1,0,1},
  {0,1,0}
};

byte ONE[5][3]= {
  {0,0,0},
  {0,0,1},
  {0,0,0},
  {0,0,1},
  {0,0,0}
};

byte TWO[5][3]= {
  {0,1,0},
  {0,0,1},
  {0,1,0},
  {1,0,0},
  {0,1,0}
};

byte THREE[5][3]= {
  {0,1,0},
  {0,0,1},
  {0,1,0},
  {0,0,1},
  {0,1,0}
};

byte FOUR[5][3]= {
  {0,0,0},
  {1,0,1},
  {0,1,0},
  {0,0,1},
  {0,0,0}
};

byte FIVE[5][3]= {
  {0,1,0},
  {1,0,0},
  {0,1,0},
  {0,0,1},
  {0,1,0}
};

byte SIX[5][3]= {
  {0,1,0},
  {1,0,0},
  {0,1,0},
  {1,0,1},
  {0,1,0}
};

byte SEVEN[5][3]= {
  {0,1,0},
  {0,0,1},
  {0,0,0},
  {0,0,1},
  {0,0,0}
};

byte EIGHT[5][3]= {
  {0,1,0},
  {1,0,1},
  {0,1,0},
  {1,0,1},
  {0,1,0}
};

byte NINE[5][3]= {
  {0,1,0},
  {1,0,1},
  {0,1,0},
  {0,0,1},
  {0,1,0}
};

void SetBitmap(int number, byte bitmap[rowLength][columnLength]) {
  switch (number) {
    case 0:
      memcpy(ZERO, bitmap, sizeof(bitmap));
      break;
    case 1:
      memcpy(ONE, bitmap, sizeof(bitmap));
      break;
    case 2:
      memcpy(TWO, bitmap, sizeof(bitmap));
      break;
    case 3:
      memcpy(THREE, bitmap, sizeof(bitmap));
      break;
    case 4:
      memcpy(FOUR, bitmap, sizeof(bitmap));
      break;
    case 5:
      memcpy(FIVE, bitmap, sizeof(bitmap));
      break;
    case 6:
      memcpy(SIX, bitmap, sizeof(bitmap));
      break;
    case 7:
      memcpy(SEVEN, bitmap, sizeof(bitmap));
      break;
    case 8:
      memcpy(EIGHT, bitmap, sizeof(bitmap));
      break;
    case 9:
      memcpy(NINE, bitmap, sizeof(bitmap));
      break;
  }
}

void PrintBitmap(byte bitmap[rowLength][columnLength]) {
  for (int i = 0; i < rowLength; i++) {
    for (int j = 0; j < columnLength; j++) {
      Serial.print(bitmap[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}