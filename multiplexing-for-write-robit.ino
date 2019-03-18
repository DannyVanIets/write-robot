//               a, b, c,  d, e, f,  g
int segPins[] = {9, 3, 10, 8, 2, 11, 12};
int displayPins[] = {15, 14};
int displayBuf[2];

const int segL[1][7]{
  // segment display code table
  //        a = 9
  // f = 11         b = 3
  //        g = 12
  // e = 2        c = 10
  //        d = 8
  //a, b, c, d, e, f, g
  { 0, 0, 0, 1, 1, 1, 0}  // L
};

const int segCode[10][7]{
  // segment display code table
  //        a = 9
  // f = 11         b = 3
  //        g = 12
  // e = 2        c = 10
  //        d = 8
  //a, b, c, d, e, f, g
  { 1, 1, 1, 1, 1, 1, 0},  // 0
  { 0, 1, 1, 0, 0, 0, 0},  // 1
  { 1, 1, 0, 1, 1, 0, 1},  // 2
  { 1, 1, 1, 1, 0, 0, 1},  // 3
  { 0, 1, 1, 0, 0, 1, 1},  // 4
  { 1, 0, 1, 1, 0, 1, 1},  // 5
  { 1, 0, 1, 1, 1, 1, 1},  // 6
  { 1, 1, 1, 0, 0, 0, 0},  // 7
  { 1, 1, 1, 1, 1, 1, 1},  // 8
  { 1, 1, 1, 1, 0, 1, 1}   // 9
};

void refreshDisplay(int digit1, int digit0) {
  digitalWrite(displayPins[0], HIGH);
  digitalWrite(displayPins[1], LOW);
  setSegments(digit0);
  delay(5);
  digitalWrite(displayPins[0], LOW);
  digitalWrite(displayPins[1], HIGH);
  setSegments(digit1);
  delay(5);
}

void setSegments(int n) {
  //digitalWrite(segPins[i], segL[n][i]);
  digitalWrite(segPins[14], segL[0][0]);
  for(int i = 0; i < 8; i++) {
    digitalWrite(segPins[i], segCode[n][i]);
  }
}

void setup() {
  // put your setup code here, to run once:
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT); //ground
    pinMode(15, OUTPUT); //ground

    displayBuf[1] = 0;
    displayBuf[0] = 0;
}

int i = 0, j = 0;
int startTime = 0;
int endTime;

void loop() {
  // put your main code here, to run repeatedly:
  refreshDisplay(displayBuf[1], displayBuf[0]);

  endTime = millis();
  if((endTime - startTime) >= 1000) {
    if(++i > 9) {
      i = 0;
      if(++j > 9) {
        j = 0;
      }
    }
    displayBuf[0] = i;
    displayBuf[1] = j;
    startTime = endTime;
  }
}
