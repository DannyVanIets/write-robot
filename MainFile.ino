#include "Servo.h"
String letters;
String status;
String buttonState;
Servo pen;


int motorlinks = 13;
int motorrechts = 13;
int servomotor = 13;
int segmentA = 5;
int segmentB = 6;
int segmentC = 7;
int segmentD = 8;
int segmentE = 9;
int segmentF = 10;
int segmentG = 11;
int button = 12; // Read only
int lijn1 = 5; // Read only
int lijn2 = 4; // Read only
int lijn3 = 3; // Read only
void setup() {

  pen.attach(2);
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

String Word() {
  Serial.print("Welk woord moet er geschreven worden? \n");
  boolean input;
  input = true;

  // read the incoming byte:
  while (input) { // Loops until word is given.

    if (Serial.available() > 0) { // If word is given
      input = false; // Makes input false and stops the loop (Prevents multiple words)
      letters = Serial.readString(); // Input variable
    }
  }
  // say what you got:
  Serial.print("Het volgende woord wordt geschreven: \n");
  Serial.print(letters); // Prints the chosen word.
  firstLetter();
  for (char& c : letters) {
    
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
    afterLetter();
  }

  lettersDone(); // Robot is done writing and goes in to a corner.
  
}

String buttonPressed() {

  // read the state of the pushbutton value:
  String buttonState = "HIGH";
  String status;
  // buttonState = digitalRead(button);
  buttonState = "HIGH";

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == "HIGH") {
    Word();
    delay(250);
    exit(0);
  }
}

void loop() {
  buttonPressed(); // Keeps running the function to check if the button is pressed.
}
// Movement functions ------------------------------------------------------------

int straightforward(int cm){
  
}

int straightbackward(int cm){
  
}

int leftturn(int tr){ //tr is turning radius
  
}

int rightturn (int tr) {
  
}

void circle() {
  
}

void halfcircle() {
  
}

// Line sensor functions ------------------------------------------------------------

void firstLetter() {
   Serial.print("De robot begint met eerste letter \n");
   straightforward(5);
   leftturn(90);
   straightforward(10);
}
 
void afterLetter() {
  Serial.print("De robot rijdt weer naar referentielijn \n");
}

void lettersDone() {
  Serial.print("Robot is klaar! \n");
}
// Functions for all letters ------------------------------------------------------------

void letterA() {
  Serial.print("De robot schrijft letter A \n");
}

void letterB() {
  Serial.print("De robot schrijft letter B \n");
}

void letterC() {
  Serial.print("De robot schrijft letter C \n");
}

void letterD() {
  Serial.print("De robot schrijft letter D \n");
}

void letterE() {
  Serial.print("De robot schrijft letter E \n");
}

void letterF() {
  Serial.print("De robot schrijft letter F \n");
}

void letterG() {
  Serial.print("De robot schrijft letter G \n");
}

void letterH() {
  Serial.print("De robot schrijft letter H \n");
}

void letterI() {
  Serial.print("De robot schrijft letter I \n");
}

void letterJ() {
  Serial.print("De robot schrijft letter J \n");
}

void letterK() {
  Serial.print("De robot schrijft letter K \n");
}

void letterL() {
  Serial.print("De robot schrijft letter L \n");
}

void letterM() {
  Serial.print("De robot schrijft letter M \n");
}

void letterN() {
  Serial.print("De robot schrijft letter N \n");
}

void letterO() {
  Serial.print("De robot schrijft letter O \n");
}

void letterP() {
  Serial.print("De robot schrijft letter P \n");
}

void letterQ() {
  Serial.print("De robot schrijft letter Q \n");
}

void letterR() {
  Serial.print("De robot schrijft letter R \n");
}

void letterS() {
  Serial.print("De robot schrijft letter S \n");
}

void letterT() {
  Serial.print("De robot schrijft letter T \n");
}

void letterU() {
  Serial.print("De robot schrijft letter U \n");
}

void letterV() {
  Serial.print("De robot schrijft letter V \n");
}

void letterW() {
  Serial.print("De robot schrijft letter W \n");
}

void letterX() {
  Serial.print("De robot schrijft letter X \n");
}

void letterY() {
  Serial.print("De robot schrijft letter Y \n");
}

void letterZ() {
  Serial.print("De robot schrijft letter Z \n");
}
