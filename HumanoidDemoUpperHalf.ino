#include <IRremote.hpp>

#include <Servo.h>

//0 degrees is arm straight down
//90 is straight forawrd
//180 is straight up
Servo rightShoulder1;


Servo rightShoulder2;


//0 degrees is arm straight up
//90 is straight forawrd
//180 is straight down
Servo leftShoulder1;
Servo leftShoulder2;



Servo leftElbow;
Servo rightElbow;

int enA = 10;
int in1 = 11;
int in2 = 12;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(43, ENABLE_LED_FEEDBACK);
  delay(1000);
  rightShoulder1.attach(8);
  //
  leftShoulder1.attach(3);
  //
  //
  rightShoulder2.attach(9);
  //
  leftShoulder2.attach(2);


  leftElbow.attach(5);
  rightElbow.attach(4);

  //
  rightShoulder1.write(90);
  leftShoulder1.write(90);
  leftShoulder2.write(20); //0 is reset
  rightShoulder2.write(180); //180 is reset
  leftElbow.write(90);
  rightElbow.write(90);


  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //  for (int i = 0; i < 5; i++) {
  //    sideToSideWaist();
  //  }
  //  waistStop();
  //  delay(1000);
  //  waistReset();
  //

delay(2000);
  iWantYourDrama();
   iWantYourDrama();
    iWantYourDrama();
     iWantYourDrama();
      iWantYourDrama();
}

void waistClockwise() {
  digitalWrite(enA, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void waistCounterClockwise() {
  digitalWrite(enA, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void waistStop() {
  digitalWrite(enA, LOW);
}
String dir = "clockwise";



void loop() {




}


void sideToSideWaist() {
  //right IR sensor
  while (analogRead(A14) > 200) {
    waistClockwise();
  }


  //left side IR sensor
  while (analogRead(A15) > 200) {
    waistCounterClockwise();
  }


}

//makes robot look forward
void waistReset() {

  //make it all the way right, then center
  //right IR sensor
  while (analogRead(A14) > 200) {
    waistClockwise();
  }

  while (analogRead(A13) > 200) {
    waistCounterClockwise();
  }
  waistClockwise();
  delay(200);
  waistStop();
}


void sideToSideWaistLoop() {
  if (dir == "clockwise") {
    waistClockwise();
  }
  else if (dir == "counterclockwise") {
    waistCounterClockwise();
  }
  //right side IR
  if (analogRead(A14) < 200) {
    dir = "counterclockwise";
  }

  if (analogRead(A15) < 200) {
    dir = "clockwise";
  }
}
//void loop() {
//  // put your main code here, to run repeatedly:
//
//  if (IrReceiver.decode()) {
//
//
//    //THIS would be unique to each robot or our robots as a group
//    //Serial.println(IrReceiver.decodedIRData.address);
//
//
//    // Serial.println(IrReceiver.decodedIRData.command);
//
//
//
//    /*
//       !!!Important!!! Enable receiving of the next value,
//       since receiving has stopped after the end of the current received data packet.
//    */
//    IrReceiver.resume(); // Enable receiving of the next value
//
//    /*
//       Finally, check the received data and perform actions according to the received command
//    */
//
//
//
//
//    int code = IrReceiver.decodedIRData.command;
//    Serial.println(code);
//
//
//    //btn 1
//    if (code == 12) {
//      playArmMovement1();
//      delay(1000);
//    }
//
//
//  }
//
//}




void iWantYourDrama() {



  for (int Continue = 90; Continue < 170; Continue += 10) {
    leftShoulder2.write(Continue);
    delay(100);
  }
  delay(500);
  for (int Continue = 170; Continue > 90; Continue -= 10) {
    leftShoulder2.write(Continue);
    delay(100);
  }
  delay(500);
}
void playArmMovement1() {


  for (int rotation = 90; rotation < 180; rotation += 1) {

    rightShoulder1.write(rotation);
    leftShoulder1.write(180 - rotation);
    rightShoulder2.write(rotation);
    leftShoulder2.write(180 - rotation);
    delay(20);
  }
  for (int rotation = 180; rotation > 90; rotation -= 1) {

    rightShoulder1.write(rotation);
    leftShoulder1.write(180 - rotation);
    rightShoulder2.write(rotation);
    leftShoulder2.write(180 - rotation);
    delay(20);
  }
}
