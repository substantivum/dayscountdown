byte ZERO[5][3] = {
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
      memcpy(bitmap, ZERO, sizeof(bitmap));
      break;
    case 1:
      memcpy(bitmap, ONE, sizeof(bitmap));
      break;
    case 2:
      memcpy(bitmap, TWO, sizeof(bitmap));
      break;
    case 3:
      memcpy(bitmap, THREE, sizeof(bitmap));
      break;
    case 4:
      memcpy(bitmap, FOUR, sizeof(bitmap));
      break;
    case 5:
      memcpy(bitmap, FIVE, sizeof(bitmap));
      break;
    case 6:
      memcpy(bitmap, SIX, sizeof(bitmap));
      break;
    case 7:
      memcpy(bitmap, SEVEN, sizeof(bitmap));
      break;
    case 8:
      memcpy(bitmap, EIGHT, sizeof(bitmap));
      break;
    case 9:
      memcpy(bitmap, NINE, sizeof(bitmap));
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