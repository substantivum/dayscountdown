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

void SetBitmap() {
  byte temp[1][5][3];

  // Second number (screen)
  for (int row = 0; row < rowLength; row++) {
    for (int column = 0; column < columnLength/2; column++) {
      int bitmapi1[2] = {row, column};
      int bitmapi2[2] = {row, column + 3};
      int numberi[2] = {row, column};
      _SetBitmapIndex(numberOfDays[0], bitmap, bitmapi1, numberi);
      _SetBitmapIndex(numberOfDays[1], bitmap, bitmapi2, numberi);
    }
  }
}

void _SetBitmapIndex(int number, byte bitmap[rowLength][columnLength], int bitmapi[2], int numberi[2]) {
  switch (number) {
    case 0:
      bitmap[bitmapi[0]][bitmapi[1]] = ZERO[numberi[0]][numberi[1]];
      break;
    case 1:
      bitmap[bitmapi[0]][bitmapi[1]] = ONE[numberi[0]][numberi[1]];
      break;
    case 2:
      bitmap[bitmapi[0]][bitmapi[1]] = TWO[numberi[0]][numberi[1]];
      break;
    case 3:
      bitmap[bitmapi[0]][bitmapi[1]] = THREE[numberi[0]][numberi[1]];
      break;
    case 4:
      bitmap[bitmapi[0]][bitmapi[1]] = FOUR[numberi[0]][numberi[1]];
      break;
    case 5:
      bitmap[bitmapi[0]][bitmapi[1]] = FIVE[numberi[0]][numberi[1]];
      break;
    case 6:
      bitmap[bitmapi[0]][bitmapi[1]] = SIX[numberi[0]][numberi[1]];
      break;
    case 7:
      bitmap[bitmapi[0]][bitmapi[1]] = SEVEN[numberi[0]][numberi[1]];
      break;
    case 8:
      bitmap[bitmapi[0]][bitmapi[1]] = EIGHT[numberi[0]][numberi[1]];
      break;
    case 9:
      bitmap[bitmapi[0]][bitmapi[1]] = NINE[numberi[0]][numberi[1]];
      break;
    default:
      bitmap[bitmapi[0]][bitmapi[1]] = ZERO[numberi[0]][numberi[1]];
      break;
  }
}

void PrintBitmap(byte bitmap[rowLength][columnLength]) {
  for (int i = 0; i < rowLength; i++) {
    for (int j = 0; j < columnLength; j++) {
      if (j % 3 == 0)
      {
        Serial.print("| ");
      }
      Serial.print(bitmap[i][j]);
      Serial.print(" ");
    }
    Serial.println("|");
  }
}