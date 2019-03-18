#include "Servo.h"
Servo pen;

String woord = "a"; // Set your word here
int fullCircleTime; //time robot needs to do a full circle

uint8_t vooruit = HIGH;
uint8_t achteruit = LOW;

int segmentA = 2;
int segmentC = 3;
int motorlinks = 4;
int richtingmotorlinks = 5;
int richtingmotorrechts = 6;
int motorrechts = 7;
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
  int i = 0;
  
  if ((buttonState == 1) && (i <= 0)) {
    Word();
    i++;
  } 
}


String Word() {
 
  firstLetter();
  
  for (char& c : woord) {
  
    char i = c;
  
    // If statements to check which functions need to run.
    if (i == 'a') {
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
lettersDone(); // Robot is done writing and goes in to a corner.
}



// Movement functions ------------------------------------------------------------

int forward(int cm) { // Function to call when u want the robot to drive forward

  int i;

  while (i < (cm * 1000)){
    digitalWrite(richtingmotorlinks, vooruit);
    digitalWrite(richtingmotorrechts, vooruit);
    analogWrite(motorlinks, 128);
    analogWrite(motorrechts, 128);
  }
}


int backward(int cm) {// Function to call when u want the robot to drive backwards

  int i;

  while (i < (cm * 1000)){
    digitalWrite(richtingmotorlinks, achteruit);
    digitalWrite(richtingmotorrechts, achteruit);
    analogWrite(motorlinks, 128);
    analogWrite(motorrechts, 128);
  }
}

int rotate(int degrees){// Function to call when u want the robot to drive forward

  if(degrees > 0){

    digitalWrite(richtingmotorlinks, vooruit);
    digitalWrite(richtingmotorrechts, achteruit);
    analogWrite(motorlinks, 255);
    analogWrite(motorrechts, 255);
  
  }
   if(degrees <= 0){

    digitalWrite(richtingmotorlinks, achteruit);
    digitalWrite(richtingmotorrechts, vooruit);
    analogWrite(motorlinks, 255);
    analogWrite(motorrechts, 255);
  
  }
}

void circle() {// Function to call when u want the robot to draw a circle

 int i;
  
  while(i < fullCircleTime){
      digitalWrite(richtingmotorlinks, achteruit);
      digitalWrite(richtingmotorrechts, vooruit);
      analogWrite(motorlinks, 128);
      analogWrite(motorrechts, 255);
      i++;
  }
}
  
int halfcircle(int degrees) {// Function to call when u want the robot to draw half a circle
  
  int i;
  
   if(degrees > 0){
    while(i < (fullCircleTime/2)){
      digitalWrite(richtingmotorlinks, achteruit);
      digitalWrite(richtingmotorrechts, vooruit);
      analogWrite(motorlinks, 128);
      analogWrite(motorrechts, 255);
      i++;
    }
  }
   if(degrees <= 0){
    while(i < (fullCircleTime/2)){
      digitalWrite(richtingmotorlinks, vooruit);
      digitalWrite(richtingmotorrechts, achteruit);
      analogWrite(motorlinks, 255);
      analogWrite(motorrechts, 128);
      i++;
    }
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
  
  while (!lineFound){
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
  
  while (!lineFound){
    forward(1);
      if ((digitalRead(lijn1) == LOW) && (digitalRead(lijn2) == LOW) && (digitalRead(lijn3) == LOW)) {
        forward(2);
        lineFound = true;
      } 
    }
    
   rotate(-90);

   while (!endFound){
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

  pendown();
  
  rotate(45);
  forward(14);
  rotate(45);

  penup();
  
  rotate(90);
  forward(5);
  rotate(90);
  backward(5);

  pendown();

  forward(10);

  penup();

  backward(5);
  rotate(90);
  forward(5);
  rotate(90);
  
  rotate(45);
  forward(14);
  rotate(45);
  
  afterLetter(); // Make sure this is the last function called in each letter function.
}

void letterB() {

  pendown();
  
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

  pendown();

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

  pendown();

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

  pendown();

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

  pendown();

  forward(10);

  penup();

  rotate(180);
  forward(5);
  rotate(135);

  pendown();

  forward(6,5);

  penup();

  rotate(180);
  forward(6,5);
  rotate(-90);
  
  pendown();

  forward(6,5);
  
  afterLetter();
}

void letterL() {

  pendown();

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
  
  pendown();

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

  pendown();

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
  pendown();

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

  forward(10);
  rotate(180);

  pendown();

  forward(10);
  rotate(-135);
  forward(6);
  rotate(90);
  forward(6);
  rotate(-135);
  forward(10)

  penup();

  rotate(180);
  
  afterLetter();
}

void letterX() {

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
