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

        for(char& c : letters){
        
      }

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
