#include "Servo.h"
Servo pen;

String woord = "a"; // Set your word here
int fullCircleTime = 1855; //time robot needs to do a full circle
int i = 0;


uint8_t vooruit = HIGH;
uint8_t achteruit = LOW;

int segmentA = 2;
int segmentC = 3;
int motorlinks = 5;
int richtingmotorlinks = 4;
int richtingmotorrechts = 7;
int motorrechts = 6;
int segmentB = 8;
int segmentD = 9;
int segmentE = 10;
int segmentF = 11;
int segmentG = 12;
int button = 13; // Read only
uint8_t lijn1 = A4; // Read only
uint8_t lijn2 = A3; // Read only
uint8_t lijn3 = A2; // Read only
uint8_t servomotor = A5;

void setup() {
  pen.attach(A2);
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

}

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

  // firstLetter();

  for (char& c : woord) {
    Serial.print(c);
    char i = c;


    // If statements to check which functions need to run.
    if (c == 'a') {
      Serial.print(c);
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
  
  Serial.print("Klaar");
  // lettersDone(); // Robot is done writing and goes in to a corner.
}



// Movement functions ------------------------------------------------------------

int forward(int cm) { // Function to call when u want the robot to drive forward

  int i = 0;
  while (i < (cm * 10)) {
    digitalWrite(richtingmotorlinks, HIGH);
    digitalWrite(richtingmotorrechts, HIGH);
    analogWrite(motorlinks, 255);
    analogWrite(motorrechts, 255);
    i++;
    Serial.println(i);
  }
  motoruit();
}


int backward(int cm) {// Function to call when u want the robot to drive backwards

  int i = 0;

  while (i < (cm * 10)) {
    digitalWrite(richtingmotorlinks, LOW);
    digitalWrite(richtingmotorrechts, LOW);
    analogWrite(motorlinks, 255);
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
  int i = 0;
  if (rotation > 0) {

    while (i < (rotation * 5)) {

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

    while (i < (rotation * 5)) {
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
  while (i < fullCircleTime) {
    digitalWrite(richtingmotorlinks, HIGH);
    analogWrite(motorlinks, 255);
    i++;
    Serial.println(i);
  }
  motoruit();
}

int halfcircle(int degrees) {// Function to call when u want the robot to draw half a circle

  int i = 0;

  if (degrees > 0) {
    while (i < (fullCircleTime / 2)) {

      digitalWrite(richtingmotorlinks, HIGH);
      analogWrite(motorlinks, 255);
      i++;
      Serial.println(i);
    }
    motoruit();
  }
  if (degrees <= 0) {
    while (i < (fullCircleTime / 2)) {
      digitalWrite(richtingmotorrechts, HIGH);
      analogWrite(motorrechts, 255);
      i++;
      Serial.println(i);
    }
    motoruit();
  }

}

void penup() {// Function to call when u want the robot to pull the pen up
  pen.write(90);
}

void pendown() {// Function to call when u want the robot to push the pen down
  pen.write(45);
}

// Line sensor functions ------------------------------------------------------------

void firstLetter() {// Function is used for positioning the robot for the first letter
  // robot starts with this function
  forward(5);
  rotate(-90);
  forward(10);
  pendown();
}

void afterLetter() {// Function is used for positioning the robot between every letter
  penup();
  boolean lineFound = false;

  while (!lineFound) {
    forward(1);
    if ((digitalRead(lijn1) == LOW) && (digitalRead(lijn2) == LOW) && (digitalRead(lijn3) == LOW)) {
      forward(2);
      lineFound = true;
    }
  }

  rotate(-90);
  forward(5);
  rotate(-90);
  forward(10);
  pendown();

}

void lettersDone() {
  penup();
  boolean lineFound = false;
  boolean endFound = false;

  while (!lineFound) {
    forward(1);
    if ((digitalRead(lijn1) == LOW) && (digitalRead(lijn2) == LOW) && (digitalRead(lijn3) == LOW)) {
      forward(2);
      lineFound = true;
    }
  }

  rotate(-90);

  while (!endFound) {
    forward(1);
    if ((digitalRead(lijn1) == LOW) && (digitalRead(lijn2) == LOW) && (digitalRead(lijn3) == LOW)) {
      forward(2);
      endFound = true;
      Serial.end();
    }
  }
}

// Functions for all letters ------------------------------------------------------------
// They will be called in the function: Word
void letterA() {
  circle();
  halfcircle(90);
  halfcircle(-180);
  forward(10);
  
}

void letterB() {
  forward(10);
  rotate(90);
  forward(5);

  afterLetter();
}

void letterC() {
  Serial.print("De robot schrijft letter C \n");
  afterLetter();
}

void letterD() {
  Serial.print("De robot schrijft letter D \n");
  afterLetter();
}

void letterE() {
  Serial.print("De robot schrijft letter E \n");
  afterLetter();
}

void letterF() {
  Serial.print("De robot schrijft letter F \n");
  afterLetter();
}

void letterG() {
  Serial.print("De robot schrijft letter G \n");
  afterLetter();
}

void letterH() {
  Serial.print("De robot schrijft letter H \n");
  afterLetter();
}

void letterI() {
  Serial.print("De robot schrijft letter I \n");
  afterLetter();
}

void letterJ() {
  Serial.print("De robot schrijft letter J \n");
  afterLetter();
}

void letterK() {
  Serial.print("De robot schrijft letter K \n");
  afterLetter();
}

void letterL() {
  Serial.print("De robot schrijft letter L \n");
  afterLetter();
}

void letterM() {
  Serial.print("De robot schrijft letter M \n");
  afterLetter();
}

void letterN() {
  Serial.print("De robot schrijft letter N \n");
  afterLetter();
}

void letterO() {
  Serial.print("De robot schrijft letter O \n");
  afterLetter();
}

void letterP() {
  Serial.print("De robot schrijft letter P \n");
  afterLetter();
}

void letterQ() {
  Serial.print("De robot schrijft letter Q \n");
  afterLetter();
}

void letterR() {
  Serial.print("De robot schrijft letter R \n");
  afterLetter();
}

void letterS() {
  Serial.print("De robot schrijft letter S \n");
  afterLetter();
}

void letterT() {
  Serial.print("De robot schrijft letter T \n");
  afterLetter();
}

void letterU() {
  Serial.print("De robot schrijft letter U \n");
  afterLetter();
}

void letterV() {
  Serial.print("De robot schrijft letter V \n");
  afterLetter();
}

void letterW() {
  Serial.print("De robot schrijft letter W \n");
  afterLetter();
}

void letterX() {
  Serial.print("De robot schrijft letter X \n");
  afterLetter();
}

void letterY() {
  Serial.print("De robot schrijft letter Y \n");
  afterLetter();
}

void letterZ() {
  Serial.print("De robot schrijft letter Z \n");
  afterLetter();
}
