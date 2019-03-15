int segPins[] = {3, 2, 8, 10, 11, 14, 9};
int displayPins[] = {16, 15};
int displayBuf[2];

const int segCode[10][7]{
  // segment display code table
  //        a = 3
  // f = 14         b = 2
  //        g = 9
  // e = 11        c = 8
  //        d = 10
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
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);

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
