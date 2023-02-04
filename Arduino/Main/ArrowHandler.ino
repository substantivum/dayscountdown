int _lastArrowRight = arrowRight;
void HandleArrow() {
  if (_lastArrowRight == arrowRight || arrowRight > 1 || arrowRight < 0) {
    return;
  }

  for (int i = 0; i < 2; i++) {
    if (i == arrowRight) {
      digitalWrite(arrowsPositive[i], ARROW_ON);
    } else {
      digitalWrite(arrowsPositive[i], !ARROW_ON);
    }
  }

  _lastArrowRight = arrowRight;
}