#include <IRremote.hpp>

#include <Servo.h>

//0 degrees is arm straight down
//90 is straight forawrd
//180 is straight up
//Pin 10 is ENA
//Pin 11 is In1
//Pin 12 is In2
int enA = 10;
int in1 = 11;
int in2 = 12;


Servo rightShoulder1;


Servo rightShoulder2;

Servo rightElbow;


//0 degrees is arm straight up
//90 is straight forawrd
//180 is straight down
Servo leftShoulder1;
Servo leftShoulder2;

Servo leftElbow;





void setup() {
  // put your setup code here, to run once:

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(enA, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);



  IrReceiver.begin(41, ENABLE_LED_FEEDBACK);

  rightShoulder1.attach(8);

  leftShoulder1.attach(3);

  leftElbow.attach(5);
  rightShoulder2.attach(9);

  leftShoulder2.attach(2);
  rightElbow.attach(4);

  rightShoulder1.write(90);
  leftShoulder1.write(90); // down is 180
  leftShoulder2.write(20); //0 is reset
  rightShoulder2.write(160); //180 is reset
  //  leftElbow.write(0);
  //  rightElbow.write(180);
  //leftElbow all the way up is 0
  //rightElbow all the way up is 180
  leftElbow.write(90);
  rightElbow.write(90);


  //
  //  //




}


bool startSignalReceived = false;
bool showDone = false;
void loop() {

  if (IrReceiver.decode()) {


    int code = IrReceiver.decodedIRData.command;
    IrReceiver.resume();




    if (code == 101) {
      startSignalReceived = true;
    }
    delay(500);
  }


  if (startSignalReceived == false) {
    return;
  }
  if (showDone == false) {


    owoone();
    delay(500);
    owosecond();
    delay(500);
    RARARA();
    delay(500);
    RARARA();
    delay(500);
    RARARA();
    delay(500);
    RARARA();
    delay(200);//before was 3000 without third rarara
    iWantYourUgly();
    delay(1000);
    iWantYourDisease();
    //and line after I want disease^^
    delay(1000);
    iWantYourLove();
    delay(1000);
    loveLoveLove();
    delay(1000);
    secondIwantYourLove();
    delay(1000);
    iWantYourDrama();
    delay(1000);
    theStrokeOfYourHair();
    delay(200);
    theStrokeOfYourHair();
    delay(1000);
    loveLoveLove();
    delay(500);
    secondIwantYourLove();
    delay(500);
    leftElbow.write(90);
    leftShoulder2.write(90);
    rightElbow.write(90);
    rightShoulder2.write(90);
    delay(500);
    loudSongPart();//you might wanna repeat this (NO DELAY REQUIRED BETWEEN METHODS FOR LOUDSOUNDPART!!!!!!!)
    //spam e section OLD STUFF
    //    delay(1000);
    //    RARARA();
    //    delay(500);
    //    RARARA();
    //    delay(1000);
    loudSongPart();
    loudSongPart();
    loudSongPart();
    iWantYourDisease();
    iWantYourDisease();
    iWantYourDisease();
    waveHand();
    showDone = true;
  }









}



//IMPORTANT FOR MOVEMENT CODE
// SHOULDER 1.) Respobonsible for movemnt on radial direction for movement in up down with the foam plate of the robot
//Shoulder2.) Responsible for movement left and right against the foam plate of the robot

void movearmsup(int turningFactor)
{

  for (int Continue = 90; Continue >= 0; Continue -= 10)
  {
    leftShoulder1.write(Continue);
    rightShoulder1.write(180 - Continue);
    delay(turningFactor);

  }

}

void movearmsdown(int turningFactor)
{
  for (int Continue = 0; Continue <= 90; Continue += 1)
  {
    leftShoulder1.write(Continue);
    rightShoulder1.write(180 - Continue);
    delay(turningFactor);

  }
}

void movearmsinward(int turningFactor)
{
  for (int Continue = 90; Continue >= 20; Continue -= 1)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(180 - Continue);
    delay(turningFactor);
  }
}

void movearmsoutward(int turningFactor)
{
  for (int Continue = 20; Continue <= 90; Continue += 10)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(180 - Continue);
    delay(turningFactor);

  }
}

void movearmsallthewayback(int turningFactor)
{
  for (int Continue = 90; Continue <= 180; Continue += 10)
  {
    leftShoulder1.write(Continue);
    rightShoulder1.write(180 - Continue);
    delay(turningFactor);
  }
}

void movearmsupfromallthewayback(int turningFactor)
{
  for (int Continue = 180; Continue >= 90; Continue -= 10)
  {
    leftShoulder1.write(Continue);
    rightShoulder1.write(180 - Continue);
    delay(turningFactor);
  }
  leftElbow.write(0);
  rightElbow.write(180);
}


void movearmsallthewayoutward(int turningFactor)
{
  for (int Continue = 20; Continue <= 180; Continue += 10)
  {
    leftShoulder2.write(Continue);
    leftElbow.write(-10 + Continue);
    rightShoulder2.write(180 - Continue);
    rightElbow.write(190 - Continue);
    delay(turningFactor);


  }


}

void movearmsallthewayoutwardslowlyforrahrah(int turningFactor)
{
  for (int Continue = 20; Continue <= 180; Continue += 15)
  {
    leftShoulder2.write(Continue);
    leftElbow.write(180);
    rightShoulder2.write(180 - Continue);
    rightElbow.write(0);
    delay(turningFactor);
  }
}

void movearmsinwardfromallthewayoutward(int turningFactor)
{
  for (int Continue = 180; Continue >= 20; Continue -= 1)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(180 - Continue);
    delay(turningFactor);
  }
  leftElbow.write(180);
  rightElbow.write(0);

}

void movearmsinwardfromallthewayoutwardforrahrah(int turningFactor)
{
  for (int Continue = 180; Continue >= 20; Continue -= 7)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(180 - Continue);
    delay(turningFactor);
  }

}

void movearmsoutwardfromallthewayinwardforrahrah(int turningFactor)
{
  for (int Continue = 20; Continue <= 180; Continue += 7)
  {
    leftShoulder2.write(Continue);
    leftElbow.write(180);
    rightShoulder2.write(180 - Continue);
    rightElbow.write(0);
    delay(turningFactor);
  }
}



void movearmsupinstantlyforiwantyourdisease() {

  leftShoulder1.write(0);
  leftElbow.write(90);
  rightShoulder1.write(0);
  rightElbow.write(0);


}

void movearmsdowninstantlyforiwantyourdisease() {

  leftShoulder1.write(180);
  leftElbow.write(180);
  rightShoulder1.write(180);
  rightElbow.write(90);

}

void iWantYourLove()
//they also look towards audience kind of a resetting position.
{
  leftShoulder1.write(90);
  leftShoulder2.write(20);
  leftElbow.write(90);
  rightShoulder1.write(90);
  rightShoulder2.write(10);
  rightElbow.write(90);
}

void loveLoveLove () {
  leftShoulder2.write(180);
  rightShoulder2.write(0);
  delay(500);//delay subject to change
  leftShoulder2.write(90);
  rightShoulder2.write(90);
  leftElbow.write(180);
  rightElbow.write(0);
  delay(500);//delay subject to change
  leftShoulder2.write(20);
  leftElbow.write(90);
  rightShoulder2.write(160);
  rightElbow.write(90);
}

void secondIwantYourLove() {
  //I
  leftShoulder1.write(0);
  leftElbow.write(70);
  rightShoulder1.write(180);
  leftElbow.write(110);
  delay(500);
  //Want (move leftShoulder2 up)
  leftShoulder1.write(90);
  leftShoulder2.write(180);
  rightShoulder1.write(90);
  rightShoulder2.write(0);
  delay(500);
  //Want
  leftElbow.write(180);
  for (int Continue = 180; Continue >= 20; Continue -= 10)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(180 - Continue);
    delay(5);
  }
  delay(500);
  //Your
  for (int Continue = 180; Continue >= 0; Continue -= 10)
  {
    leftShoulder1.write(Continue);
    leftElbow.write(180 - Continue);
    rightShoulder1.write(180 - Continue);
    rightElbow.write(Continue);
  }
  delay(500);
  //Love
  leftShoulder1.write(90);
  leftElbow.write(180);
  rightShoulder1.write(90);
  rightElbow.write(0);
  for (int Continue = 180; Continue >= 20; Continue -= 10)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(180 - Continue);
    delay(5);
  }
  delay(2000);
}

//Next major section

void iWantYourDrama()
{
  leftShoulder2.write(90);
  leftElbow.write(90);
  leftShoulder1.write(90);
  rightShoulder2.write(90);
  rightElbow.write(90);
  rightShoulder1.write(90);
}

void theStrokeOfYourHair()
{
  leftShoulder2.write(120);
  rightShoulder2.write(60);
  delay(500);
  leftShoulder2.write(90);
  rightShoulder2.write(90);
  delay(500);
  leftShoulder2.write(120);
  rightShoulder2.write(60);
  delay(500);
  leftShoulder2.write(90);
  rightShoulder2.write(90);
  delay(500);
  leftShoulder2.write(120);
  rightShoulder2.write(60);
  delay(500);
  leftShoulder2.write(90);
  rightShoulder2.write(90);
  delay(500);
  leftShoulder2.write(120);
  rightShoulder2.write(60);
  delay(500);
  leftShoulder2.write(90);
  rightShoulder2.write(90);
  delay(500);

}
//MajorDanceCode
void owoone()
{
  movearmsup(5);
  delay(250);
  movearmsoutward(5);
  delay(250);
  movearmsinward(50);
  delay(250);
  movearmsdown(40);
}
void owosecond()
{
  movearmsallthewayback(5);
  delay(1000);
  movearmsallthewayoutward(5);
  delay(1000);
  movearmsinwardfromallthewayoutward(30);
  delay(1000);
  movearmsupfromallthewayback(5);


}
void RARARA()
{
  //  movearmsallthewayoutward(5);
  //  delay(100);
  //  movearmsinwardfromallthewayoutward(5);
  //  delay(100);
  //  movearmsallthewayoutward(5);
  //  delay(100);
  //  movearmsinwardfromallthewayoutward(5);
  //  delay(2000);
  //  movearmsallthewayoutward(5);
  //  delay(100);d
  //  movearmsinwardfromallthewayoutward(5);
  //  delay(100);
  //  movearmsallthewayoutward(5);
  //  delay(100);
  //  movearmsinwardfromallthewayoutward(5);
  //  delay(2000);
  movearmsallthewayoutwardslowlyforrahrah(125);
  movearmsinwardfromallthewayoutwardforrahrah(125);
}
void iWantYourUgly()
{
  rightShoulder1.write(90);
  leftShoulder1.write(90);
  leftShoulder2.write(20);
  rightShoulder2.write(160);
  leftElbow.write(180);
  rightElbow.write(180);
  delay(2000);
}
void iWantYourDisease()
{
  movearmsupinstantlyforiwantyourdisease();
  delay(1000);
  movearmsdowninstantlyforiwantyourdisease();
  delay(1000);
  movearmsupinstantlyforiwantyourdisease();
  delay(1000);
  movearmsdowninstantlyforiwantyourdisease();
  delay(1000);



}

void loudSongPart() //Arms move do one side, then do the other
{
  //Big arms move out
  for (int Continue = 90; Continue <= 135; Continue += 10)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(Continue);
    delay(5);
  }
  delay(500);
  //Elbows move in and out twice
  for (int Continue = 90; Continue <= 180; Continue += 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  for (int Continue = 180; Continue >= 90; Continue -= 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  for (int Continue = 90; Continue <= 180; Continue += 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  for (int Continue = 180; Continue >= 90; Continue -= 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  //Big Arms move out to other direction
  for (int Continue = 135; Continue >= 45; Continue -= 10)
  {
    leftShoulder2.write(Continue);
    rightShoulder2.write(Continue);
    delay(5);
  }
  //Elbows move in and out twice
  for (int Continue = 90; Continue <= 180; Continue += 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  for (int Continue = 180; Continue >= 90; Continue -= 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  for (int Continue = 90; Continue <= 180; Continue += 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);
  for (int Continue = 180; Continue >= 90; Continue -= 10)
  {
    leftElbow.write(Continue);
    rightElbow.write(180 - Continue);
    delay(5);
  }
  delay(500);

}

void waveHand()
{
  rightShoulder1.write(180);
  rightShoulder2.write(90);
  rightElbow.write(90);
  delay(1000);
  rightElbow.write(65);
  delay(1000);
  rightElbow.write(90);
  delay(1000);
  rightElbow.write(65);
  delay(1000);
  rightElbow.write(90);
  delay(1000);
  rightElbow.write(65);
  delay(1000);
  rightShoulder1.write(90);
  rightShoulder2.write(160);


}
