#include "Servo.h"
Servo pen;

int multiply = 1;

String woord = "a"; // Set your word here
int fullCircleTime = 1200; //time robot needs to do a full circle

int i = 0;
int l = 0;
int k = 1;
int m = 0;

int lijn1_BreakPoint = 800; // linkerSensor
int lijn2_BreakPoint = 880; // middenSensor
int lijn3_BreakPoint = 870; // rechterSensor

int lijn1_value = 0;
int lijn2_value = 0;
int lijn3_value = 0;

//               a, b, c,  d, e, f,  g
int segPins[] = {9, 3, 10, 8, 2, 11, 12};
int displayPins[] = {15, 14};
int displayBuf[2];

int lengtewoord = 0;
int count = 0;

uint8_t vooruit = HIGH;
uint8_t achteruit = LOW;

int segmentA = 2;
int segmentC = 3;
int motorlinks = 6;
int richtingmotorlinks = 7;
int richtingmotorrechts = 4;
int motorrechts = 5;
int segmentB = 8;
int segmentD = 9;
int segmentE = 10;
int segmentF = 11;
int segmentG = 12;
int button = 13; // Read only
uint8_t lijn1 = A2; // linkerSensor
uint8_t lijn2 = A4; // middenSensor
uint8_t lijn3 = A3; // rechterSensor
uint8_t servomotor = A5;

void setup() {
  pen.attach(A5);
  Serial.begin(9600);

  // Setup for pins
  pinMode(motorlinks, OUTPUT);
  pinMode(motorrechts, OUTPUT);
  pinMode(servomotor, OUTPUT);
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(button, INPUT);
  pinMode(lijn1, INPUT);
  pinMode(lijn2, INPUT);
  pinMode(lijn3, INPUT);
  // Assign pinmode
  pinMode(14, OUTPUT); //ground
  pinMode(15, OUTPUT); //ground
  pendown();

}

// Segments


// int startTime = 0;
// int endTime;

const int segCode[11][7] {
  // segment display code table
  //        a = 9
  // f = 11         b = 3
  //        g = 12
  // e = 2        c = 10
  //        d = 8
  //a, b, c, d, e, f, g
  { 0, 0, 0, 1, 1, 1, 0},  // L
  { 0, 1, 1, 0, 0, 0, 0},  // 1
  { 1, 1, 0, 1, 1, 0, 1},  // 2
  { 1, 1, 1, 1, 0, 0, 1},  // 3
  { 0, 1, 1, 0, 0, 1, 1},  // 4
  { 1, 0, 1, 1, 0, 1, 1},  // 5
  { 1, 0, 1, 1, 1, 1, 1},  // 6
  { 1, 1, 1, 0, 0, 0, 0},  // 7
  { 1, 1, 1, 1, 1, 1, 1},  // 8
  { 1, 1, 1, 1, 0, 1, 1},   // 9
  { 0, 0, 0, 0, 0, 0, 0}  // Turns off segmentdisplay
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
  for (int k = 0; k < 8; k++) {
    digitalWrite(segPins[k], segCode[n][k]);
  }
}

// End of segments
void loop() {
  buttonPressed(); // Keeps running the function to check if the button is pressed.
}

void buttonPressed() {

  int buttonState = digitalRead(button);

  if ((buttonState == 1) && (i <= 0)) {
    Word();
    i++;
  }
}


String Word() {


  while (woord[count] != '\0') {
    count++;
    Serial.println(count);
  }

  for (char& c : woord) {

    char i = c;

    lengtewoord++;


    // If statements to check which functions need to run.
    if (c == 'a') {
      letterA();
    }
    if (i == 'b') {
      letterB();
    }
    if (i == 'c') {
      letterC();
    }
    if (i == 'd') {
      letterD();
    }
    if (i == 'e') {
      letterE();
    }
    if (i == 'f') {
      letterF();
    }
    if (i == 'g') {
      letterG();
    }
    if (i == 'h') {
      letterH();
    }
    if (i == 'i') {
      letterI();
    }
    if (i == 'j') {
      letterJ();
    }
    if (i == 'k') {
      letterK();
    }
    if (i == 'l') {
      letterL();
    }
    if (i == 'm') {
      letterM();
    }
    if (i == 'n') {
      letterN();
    }
    if (i == 'o') {
      letterO();
    }
    if (i == 'p') {
      letterP();
    }
    if (i == 'q') {
      letterQ();
    }
    if (i == 'r') {
      letterR();
    }
    if (i == 's') {
      letterS();
    }
    if (i == 't') {
      letterT();
    }
    if (i == 'u') {
      letterU();
    }
    if (i == 'v') {
      letterV();
    }
    if (i == 'w') {
      letterW();
    }
    if (i == 'x') {
      letterX();
    }
    if (i == 'y') {
      letterY();
    }
    if (i == 'z') {
      letterZ();
    }
  }

  // lettersDone(); // Robot is done writing and goes in to a corner.
}



// Movement functions ------------------------------------------------------------

double forward(double cm) { // Function to call when u want the robot to drive forward

  int i = 0;
  while (i < (cm * (15 * multiply))) {
    digitalWrite(richtingmotorlinks, HIGH);
    digitalWrite(richtingmotorrechts, HIGH);
    analogWrite(motorlinks, 245);
    analogWrite(motorrechts, 255);
    i++;
    Serial.println(i);

  }
  motoruit();
}


void motoruit() {
  analogWrite(motorlinks, 0);
  analogWrite(motorrechts, 0);
}

int rotate(int rotation) { // Function to call when u want the robot to drive forward
  double i = 0.0;
  if (rotation > 0) {

    while (i < (rotation * (1.6 * multiply))) {

      digitalWrite(richtingmotorlinks, HIGH);
      digitalWrite(richtingmotorrechts, LOW);
      analogWrite(motorlinks, 255);
      analogWrite(motorrechts, 255);
      i++;
      Serial.println(i);
    }
    motoruit();
  }
  if (rotation <= 0) {

    while (i < (rotation * (1.6 * multiply))) {
      digitalWrite(richtingmotorlinks, LOW);
      digitalWrite(richtingmotorrechts, HIGH);
      analogWrite(motorlinks, 255);
      analogWrite(motorrechts, 255);
      i++;
      Serial.println(i);

    }
    motoruit();
  }
}
void circle() {// Function to call when u want the robot to draw a circle

  int i = 0;
  while (i < (fullCircleTime * multiply)) {
    digitalWrite(richtingmotorlinks, HIGH);
    digitalWrite(richtingmotorrechts, LOW);
    analogWrite(motorlinks, 255);
    analogWrite(motorrechts, 200);
    i++;
    Serial.println(i);
  }
  motoruit();
}

int halfcircle(int degrees) {// Function to call when u want the robot to draw half a circle

  int i = 0;

  if (degrees > 0) {
    while (i < (fullCircleTime / (2 * multiply))) {

      digitalWrite(richtingmotorlinks, HIGH);
      digitalWrite(richtingmotorrechts, LOW);
      analogWrite(motorlinks, 255);
      analogWrite(motorrechts, 200);
      i++;
      Serial.println(i);
    }
    motoruit();
  }
  if (degrees <= 0) {
    while (i < (fullCircleTime / (2 * multiply))) {
      digitalWrite(richtingmotorlinks, LOW);
      digitalWrite(richtingmotorrechts, HIGH);
      analogWrite(motorlinks, 200);
      analogWrite(motorrechts, 255);
      i++;
    }
    motoruit();
  }

}

void displayForward() {
  l = 0;
  m = 0;

  while (l < (10 * (15 * multiply))) {
    refreshDisplay(displayBuf[1], displayBuf[0]); // Refreshes the display with the contents of displayBuf
    displayBuf[0] = k;                    // send the updated count to the display buffer
    displayBuf[1] = m;
    digitalWrite(richtingmotorlinks, HIGH);
    digitalWrite(richtingmotorrechts, HIGH);
    analogWrite(motorlinks, 255);
    analogWrite(motorrechts, 255); // Vooruit 10 cm
    l++;
    Serial.println(l);
  }
  motoruit();
  k++;
  m++;
  digitalWrite(displayPins[0], HIGH);
  digitalWrite(displayPins[1], HIGH);
}

void displayUit() {
  displayBuf[0] = 10;
  displayBuf[1] = 10;
}

void penup() {// Function to call when u want the robot to pull the pen up
  pen.write(45);
}

void pendown() {// Function to call when u want the robot to push the pen down
  pen.write(90);

}

// Line sensor functions ------------------------------------------------------------

void firstLetter() {// Function is used for positioning the robot for the first letter

  penup();
  boolean turnLineFound = false;
  while (!turnLineFound) {

    lijn1_value = analogRead(lijn1);
    lijn2_value = analogRead(lijn2);
    lijn3_value = analogRead(lijn3);

    if (lijn1_value > lijn1_BreakPoint && lijn2_value > lijn2_BreakPoint && lijn3_value > lijn3_BreakPoint) {

      forward(5.0);
      rotate(90);
      displayForward();
      turnLineFound = true;
    }

    else {
      forward(0.015);
    }
  }
}

void afterLetter() {// Function is used for positioning the robot between every letter
  penup();
  boolean lineFound = false;
  boolean turnLineFound = false;
  while (!lineFound) {

    lijn1_value = analogRead(lijn1);
    lijn2_value = analogRead(lijn2);
    lijn3_value = analogRead(lijn3);

    if (lengtewoord == count) {

      lettersDone();

    }

    if (lijn1_value > lijn1_BreakPoint && lijn2_value > lijn2_BreakPoint && lijn3_value > lijn3_BreakPoint) {

      forward(10.0);
      rotate(90);

      while (!turnLineFound) {

        lijn1_value = analogRead(lijn1);
        lijn2_value = analogRead(lijn2);
        lijn3_value = analogRead(lijn3);

        if (lijn1_value > lijn1_BreakPoint && lijn3_value < lijn3_BreakPoint) {
          rotate(-1);
        }
        if (lijn1_value < lijn1_BreakPoint && lijn3_value > lijn3_BreakPoint) {
          rotate(1);
        }
        if (lijn1_value > lijn1_BreakPoint && lijn2_value > lijn2_BreakPoint && lijn3_value > lijn3_BreakPoint) {
          turnLineFound = true;
          lineFound = true;
          rotate(90);
          forward(15);
        }
        else {
          forward(0.015);
        }
      }
    }
    else {
      forward(0.015);
    }
  }
}

void lettersDone() {
  penup();

  Serial.println("YEAH!");

  boolean lineFound = false;
  boolean endFound = false;

  while (!lineFound) {
    forward(1);
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
      forward(2);
      lineFound = true;
    }
  }

  rotate(-90);

  while (!endFound) {
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn3) < lijn3_BreakPoint)) {
      rotate(-1);
    }
    if ((digitalRead(lijn1) < lijn1_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
      rotate(1);
    }
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
      forward(2);
      endFound = true;
      Serial.end();
    }
    else {
      forward(1);
    }
  }
}

// Functions for all letters ------------------------------------------------------------
// They will be called in the function: Word
void letterA() { // 
  penup();
  rotate(45);
  forward(10);
  
  penup();
  rotate(90);
  pendown();

  forward(10);
  penup();
  rotate(360):

  forward(3);
  rotate(-45);
  pendown();

  forward(4);
  penup();
  rotate(90);
  
  afterLetter();
}

void letterB() {

  pendown();
  circle();
  forward(15);

}

void letterC() {

  penup();

  forward(5);
  rotate(180);

  pendown();

  halfcircle(-1);

  penup();

  rotate(90);

  afterLetter();
}

void letterD() {
  pendown();
  forward(7);
  penup();
  
  rotate(90);
  pendown();
  halfcircle(1);

  penup();
  rotate(-90);
  
  afterLetter();
}

void letterE() {

  forward(10);
  rotate(90);
  forward(5);

  penup();

  rotate(180);
  forward(5);
  rotate(-90);
  forward(5);
  rotate(-90);

  pendown();

  forward(2);

  penup();

  rotate(180);
  forward(2);
  rotate(-90);
  forward(5);
  rotate(-90);

  pendown();

  forward(5);

  penup();

  afterLetter();
}

void letterF() {

  forward(10);
  rotate(90);
  forward(5);

  penup();

  rotate(180);
  forward(5);
  rotate(-90);
  forward(5);
  rotate(-90);

  pendown();

  forward(2);

  penup();

  rotate(180);
  forward(2);
  rotate(-90);
  forward(5);
  rotate(-90);

  afterLetter();
}

void letterG() {
  penup();
  rotate(-90);
  pendown();
  halfcircle(1);
  
  penup();
  rotate(90);
  forward(2);

  pendown();
  forward(5);
  penup();
  
  afterLetter();
}

void letterH() {

  forward(10);

  penup();

  rotate(180);
  forward(5);
  rotate(-90);

  pendown();

  forward(5);
  rotate(-90);
  forward(5);
  rotate(180);
  forward(10);

  penup();

  afterLetter();
}

void letterI() {

  penup();

  forward(10);
  rotate(90);

  pendown();

  forward(6);

  penup();

  rotate(180);
  forward(3);
  rotate(-90);

  pendown();

  forward(10);

  rotate(-90);
  forward(3);
  rotate(180);
  forward(6);

  afterLetter();
}

void letterJ() {
  penup();
  forward(10);
  rotate(360);

  pendown();
  forward(7);
  halfcircle(1);

  penup();
  rotate(180);
  
  afterLetter();
}

void letterK() {

  forward(10);

  penup();

  rotate(180);
  forward(5);
  rotate(135);

  pendown();

  forward(7);

  penup();

  rotate(180);
  forward(7);
  rotate(-90);

  pendown();

  forward(7);

  afterLetter();
}

void letterL() {
  forward(10);

  penup();

  rotate(180);
  forward(10);
  rotate(-90);

  pendown();

  forward(5);

  afterLetter();
}

void letterM() {
  forward(10);
  rotate(135);
  forward(12);
  
  rotate(-90);
  forward(12);
  rotate(135);
  
  forward(10);
  
  afterLetter();
}

void letterN() {
  forward(10);
  rotate(135);
  forward(12);
  rotate(-135);
  forward(10);

  penup();

  rotate(180);

  afterLetter();
}

void letterO() {

  circle();

  afterLetter();
}

void letterP() {
  pendown();
  forward(15);
  penup();

  rotate(90);
  pendown();
  halfcircle(1);
  
  afterLetter();
}

void letterQ() {

  penup();

  rotate(90);
  forward(5);
  rotate(-90);

  pendown();

  forward(3);
  rotate(90);
  circle();

  penup();

  rotate(90);

  afterLetter();
}

void letterR() {
  penup();

  forward(100);

  rotate(90);
  forward(5);
  halfcircle(-1);
  forward(5);

  pendown();

  rotate(180);
  forward(5);
  rotate(45);

  penup();

  forward(6);

  penup();
  rotate(-45);

  afterLetter();
}

void letterS() {
  penup();
  rotate(-90);
  halfcircle(-1);
  
  halfcircle(1);
  penup();
  rotate(-90);
  
  afterLetter();
}

void letterT() {

  forward(10);
  penup();
  rotate(-90);
  forward(5);
  rotate(180);
  pendown();
  forward(10);
  penup();
  rotate(90);

  afterLetter();
}

void letterU() {
  penup();
  rotate(360);
  pendown();

  forward(5);
  halfcircle(-1);
  forward(5);

  penup();
  rotate(180);
  
  afterLetter();
}

void letterV() {

  penup();

  forward(10);
  rotate(135);

  pendown();

  forward(12);
  rotate(-90);
  forward(12);

  penup();

  rotate(135);

  afterLetter();
}

void letterW() {

  penup();

  forward(10);
  rotate(180);

  pendown();

  forward(10);
  rotate(-135);
  forward(6);
  rotate(90);
  forward(6);
  rotate(-135);
  forward(10);

  penup();

  rotate(180);

  afterLetter();
}

void letterX() {

  penup();

  rotate(45);

  pendown();

  forward(12);

  penup();

  rotate(-135);
  forward(10);
  rotate(-135);

  pendown();

  forward(12);

  penup();
  rotate(35);

  afterLetter();
}

void letterY() {

  penup();

  rotate(90);
  forward(5);
  rotate(-90);

  pendown();

  forward(7);
  rotate(-45);
  forward(4);

  penup();

  rotate(180);
  forward(4);
  rotate(-90);

  pendown();

  forward(4);

  penup();

  rotate(135);

  afterLetter();
}

void letterZ() {

  penup();

  forward(10);
  rotate(90);

  pendown();

  forward(10);
  rotate(135);
  forward(12);
  rotate(-135);
  forward(10);

  penup();

  afterLetter();
}
