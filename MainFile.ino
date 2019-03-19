#include "Servo.h"
Servo pen;

String woord = "a"; // Set your word here
int fullCircleTime = 1855; //time robot needs to do a full circle
int i = 0;

int lijn1_BreakPoint = 900;
int lijn2_BreakPoint = 900; 
int lijn3_BreakPoint = 900; 


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
  boolean turnLineFound = false;
  
  while (!turnLineFound) {
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) < lijn2_BreakPoint) && (digitalRead(lijn3) < lijn3_BreakPoint)) {
        rotate(-1);
      }
    if ((digitalRead(lijn1) < lijn1_BreakPoint) && (digitalRead(lijn2) < lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
        rotate(1);
      }
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
        forward(2);
        turnLineFound = true;
      }
    else{
        forward(1);
      }
    }
  
  rotate(-90);
  forward(10);
  pendown();
}

void afterLetter() {// Function is used for positioning the robot between every letter
  penup();
  boolean lineFound = false;
  boolean turnLineFound = false;

  while (!lineFound) {
    forward(1);
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
      forward(2);
      lineFound = true;
    }
  }

  rotate(-90);
  
  while (!turnLineFound) {
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) < lijn2_BreakPoint) && (digitalRead(lijn3) < lijn3_BreakPoint)) {
        rotate(-1);
      }
    if ((digitalRead(lijn1) < lijn1_BreakPoint) && (digitalRead(lijn2) < lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
        rotate(1);
      } 
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
        forward(2);
        turnLineFound = true;
      }
    else{
        forward(1);
      }
    }
  
 
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
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
      forward(2);
      lineFound = true;
    }
  }

  rotate(-90);

  while (!endFound) {
    if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) < lijn2_BreakPoint) && (digitalRead(lijn3) < lijn3_BreakPoint)) {
        rotate(-1);
      }
      if ((digitalRead(lijn1) < lijn1_BreakPoint) && (digitalRead(lijn2) < lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
        rotate(1);
      } 
      if ((digitalRead(lijn1) > lijn1_BreakPoint) && (digitalRead(lijn2) > lijn2_BreakPoint) && (digitalRead(lijn3) > lijn3_BreakPoint)) {
        forward(2);
        endFound = true;
        Serial.end();
      }
    else{
        forward(1);
      }
   }
}

// Functions for all letters ------------------------------------------------------------
// They will be called in the function: Word
void letterA() {
  
  rotate(45);
  forward(14);
  rotate(45);

  penup();
  
  rotate(90);
  forward(5);
  rotate(90);
  backward(5);

  pendown();
  
}

void letterB() {

  forward(10);
  rotate(90);
  forward(5);

  halfcircle(1);
  
  rotate(180);
  forward(2);
  halfcircle(1);
  forward(7);

  penup();
  rotate(180);

  forward(10);
  
  afterLetter();
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
  Serial.print("De robot schrijft letter G \n");
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
  Serial.print("De robot schrijft letter J \n");
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

  rotate(45);

  forward(5);

  pendown();
  circle();

  penup();
  forward(5);
  afterLetter();
}

void letterP() {
  Serial.print("De robot schrijft letter P \n");
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

  forward(10);
  
  rotate(90);
  forward(5);
  halfcircle(1);
  forward(5);

  penup();

  rotate(180);
  forward(5);
  rotate(45);
  
  pendown();

  forward(6);  

  penup();
  rotate(-45);
  
  afterLetter();
}

void letterS() {
  Serial.print("De robot schrijft letter S \n");
  afterLetter();
}

void letterT() {
  
  penup();

  rotate(90);
  forward(5);
  rotate(-90);

  pendown();

  forward(10);
  rotate(-90);

  forward(5);
  rotate(180);
  forward(10);

  penup();

  rotate(90);
  
  afterLetter();
}

void letterU() {
  Serial.print("De robot schrijft letter U \n");
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
