void NewCountdownRecieved(int days, int arrow) {
  // Save the new values
  arrowDir = arrow;
  _numberOfDays = days;
  SplitNumberOfDays(days, numberOfDays);

  // Update the bitmaps
  SetBitmap(numberOfDays[0], bitmap1);
  SetBitmap(numberOfDays[1], bitmap2);

  // Print the bitmaps to the serial output
  Serial.print("Days left: ");
  Serial.print(numberOfDays[0]);
  Serial.print(" : ");
  Serial.println(numberOfDays[1]);
  Serial.println("Bitmap1");
  PrintBitmap(bitmap1);
  Serial.println("Bitmap2");
  PrintBitmap(bitmap2);
}

void SplitNumberOfDays(int days, int splitDaysDesitnation[2]) {
  int second = days % 10;
  int first = (days - second) / 10;

  if (first < 10) {
    splitDaysDesitnation[0] = first;
    splitDaysDesitnation[1] = second;
  }
}