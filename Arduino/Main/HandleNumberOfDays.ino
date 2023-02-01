void NewCountdownRecieved(int days, int arrow) {
  // Save the new values
  arrowRight = arrow;
  _numberOfDays = days;
  SplitNumberOfDays(days, numberOfDays);

  // Update the bitmaps
  SetBitmap();

  // Print the bitmaps to the serial output
  Serial.print("Days left: ");
  Serial.print(numberOfDays[0]);
  Serial.print(":");
  Serial.println(numberOfDays[1]);
  Serial.print("Arrow Dir: ");
  Serial.println(arrowRight);
  Serial.println("Bitmap");
  PrintBitmap(bitmap);
}

void SplitNumberOfDays(int days, int splitDaysDesitnation[2]) {
  int second = days % 10;
  int first = (days - second) / 10;

  if (first < 10) {
    splitDaysDesitnation[0] = first;
    splitDaysDesitnation[1] = second;
  }
}