#include <IRremote.hpp>


#include <Wire.h>

#include <MPU6050.h>

#include <Servo.h>


#define straightRickshawMan 95
#define straightRickshawWoman 95
int enA = 3;//3;
int in1 = 4;//4;
int in2 = 5;//5;

Servo rickshaw;


//GYRO VARIABLES
MPU6050 mpu;
// Timers
unsigned long timer = 0;
float timeStep = 0.01;
// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;
//END OF GYRO VARIABLES



String role = "woman"; //or man or woman



bool startSignalRecieved = false;
void setup() {
  Wire.begin();
  Serial.begin(9600);
  // put your setup code here, to run once:



  //Check pin
  IrReceiver.begin(9, ENABLE_LED_FEEDBACK);



  Serial.print("REset");
  //GYRO INIT

  // Initialize MPU6050
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);

  //END OF GYRO INIT



  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  rickshaw.attach(8);


  if (role == "man") {
    rickshaw.write(straightRickshawMan);
  }
  else if (role == "woman") {
    rickshaw.write(straightRickshawWoman);
  }


  Serial.println("done with Setup. GYRO connected");
  //turnRight90();
  //  moveForward();
  //  delay(2000);
  //  stopMotors();









  //YOU ONLY HAVE A FEW SECONDS TO START THE SHOW AND RECEIVE THE SIGNAL
  while (!startSignalRecieved) {
    if (IrReceiver.decode()) {
      int code = IrReceiver.decodedIRData.command;

      IrReceiver.resume();
      //play button
      if (code == 101) {
        startSignalRecieved = true;
      } else {

      }


      delay(500);


    }


  }
  Serial.println("Started");





  moveForwardForTime(2500);


  delay(14750); // wait till running
  //delay(4500); //  make sure to subtract 2000 when adding this to 15000


  //around 3 sec
  if (role == "woman") {
    turnRight90();
  }
  else if (role == "man") {
    turnLeft90();
  }




  delay(1000); // time till next move

  //analogWrite(enA, 170);


  sideToSideShuffleGyroFemale(); //does it 5 times
  delay(1000);
  sideToSideShuffleGyroFemale(); //does it 5 times
  delay(1000);
  sideToSideShuffleGyroFemale(); //does it 5 times
  delay(1000);


  analogWrite(enA, 140);
  while (getYRotation() < 0) {
    rickshaw.write(170);

    analogWrite(enA, 140);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }

  stopMotors();
  delay(500);

  if (role == "man") {
    rickshaw.write(straightRickshawMan);
  }
  else if (role == "woman") {
    rickshaw.write(straightRickshawWoman);
  }



  delay(2000);




  moveForward();

  delay(2000);
  stopMotors();





  delay(2500); // time till next move
  //
  //
  //

  if (role == "woman") {
    turnLeft90();
  }
  else if (role == "man") {
    turnRight90();
  }


  delay(2000); // time till next move


  moveForward();

  delay(2500);
  stopMotors();


  delay(2000); // time till next move
  //
  //

  //180
  turnLeft90();
  delay(2000);
  turnLeft90();


  //
  delay(2000); // time till next move

  moveForward();

  delay(2500);
  stopMotors();


  delay(2000); // time till next move


  //180
  turnLeft90();
  delay(2000);
  turnLeft90();



  delay(4750); // time till next move

  //right rickshaw.write(170);
  //left rickshaw.write(20);


  if (role == "man") {
    rickshaw.write(straightRickshawMan - 20);
  }

  else if (role == "woman") {
    rickshaw.write(straightRickshawWoman + 20);
  }

  for (int i = 0; i < 5; i++) {
    moveForward();
    delay(2000);
    stopMotors();

    delay(500);
    moveBackward();
    delay(2000);
    stopMotors();
    delay(500);
  }

  delay(1000);
  rickshaw.write(170);
  moveForward();
  delay(7000);
  stopMotors();


  return;
  for (int i = 0; i < 100; i++) {


    turnRight90();
    delay(2000);

    moveForward();
    delay(4000);
    stopMotors();

    delay(2000);


    turnRight90();

    delay(2000);
    moveForward();
    delay(2500);
    stopMotors();


    delay(2000);
  }



  //SQUARE MOVE
  //  if (role == "woman") {
  //
  //    delay(5000);
  //    turnRight90();
  //
  //
  //    //Time to go to mans intital pos
  //    moveForwardForTime(2500);
  //  }






  turnRight90();
  delay(1000);
  moveForwardForTime(2500);
  delay(1000);
  turnRight90();
  delay(1000);
  moveForwardForTime(7500);
  delay(1000);





  //FINAL

  //
  //  if (role == "woman") {
  //
  //    turnLeft90();
  //    delay(2000);
  //    turnLeft90();
  //
  //  }
  //
  //  if (role == "man") {
  //
  //    delay(5000); //time for woman to do 180
  //  }





  //  for (int i = 0; i < 10; i++) {
  //    moveForwardForTime(2500);
  //
  //    delay(2000);
  //
  //    turnLeft90();
  //
  //    delay(2000);
  //
  //  }



}
void loop() {
  // put your main code here, to run repeatedly:
  //  Serial.println(getYRotation());
  //  delay(1000);

  if (IrReceiver.decode()) {


    //THIS would be unique to each robot or our robots as a group
    //Serial.println(IrReceiver.decodedIRData.address);


    // Serial.println(IrReceiver.decodedIRData.command);



    /*
       !!!Important!!! Enable receiving of the next value,
       since receiving has stopped after the end of the current received data packet.
    */


    /*
       Finally, check the received data and perform actions according to the received command
    */




    int code = IrReceiver.decodedIRData.command;

    Serial.println(code);
    //fastforward btn
    if (code == 64) {
      Serial.println("Forward");
      moveForward();
    }
    else if (code == 68) {
      Serial.println("Back");
      moveBackward();
    }
    //pause button
    else if (code == 67) {
      Serial.println("Stop");
      stopMotors();
    }
    //+ button (turn 90
    else if (code == 21) {
      Serial.println("TURNED");
      turnRight90();


    }

    //- button
    else if (code == 7) {
      Serial.println("TURNED");
      turnLeft90();


    }

    //button 1
    else if (code == 12) {
      Serial.println("Shuffling");
      sideToSideShuffleGyroFemale();


    }

    //btn 2
    else if (code == 24) {
      Serial.println("Shuffling");
      //      leftNRight();


    }
    else {

    }


    IrReceiver.resume(); // Enable receiving of the next value
    //doing this after seems to stop double 90?

  }

}


void turnRight90() {

  yaw = 0;
  rickshaw.write(170);

  float rot = getYRotation();

  Serial.print("initial Y Rot: " );
  Serial.println(rot);




  while (rot > -37) {
    moveForward();
    rot = getYRotation();
    Serial.print("current Y Rot: " );
    Serial.println(rot);
  }
  stopMotors();


  if (role == "man") {
    rickshaw.write(straightRickshawMan);
  }
  else if (role == "woman") {
    rickshaw.write(straightRickshawWoman);
  }


  yaw = 0; //Reset Gyro
}
void turnLeft90() {
  yaw = 0;
  rickshaw.write(20);

  float rot = getYRotation();

  Serial.print("initial Y Rot: " );
  Serial.println(rot);




  while (rot < 37) {
    moveForward();
    rot = getYRotation();
    Serial.print("current Y Rot: " );
    Serial.println(rot);
  }
  stopMotors();


  if (role == "man") {
    rickshaw.write(straightRickshawMan);
  }
  else if (role == "woman") {
    rickshaw.write(straightRickshawWoman);
  }

  yaw = 0; //Reset Gyro
}


int currentRot = 0;
//void turnRight90() {
//  rickshaw.write(150);
//
//  float rot = getYRotation();
//
//  Serial.print("initial Y Rot: " );
//  Serial.println(rot);
//

//
//
//
//  while (rot > currentRot - 37) {
//    moveForward();
//    rot = getYRotation();
//    Serial.print("current Y Rot: " );
//    Serial.println(rot);
//  }
//  stopMotors();
//  rickshaw.write(97);
//
//  currentRot = getYRotation();
//}

void moveForward() {
  digitalWrite(enA, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

}
void moveBackward() {
  digitalWrite(enA, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

}
void stopMotors() {
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}



//void sideToSideShuffle() {
//  rickshaw.write(170);
//
//  for (int i = 0; i <= 5; i++) {
//    moveForward();
//    delay(500);
//    stopMotors();
//    delay(100);
//    moveBackward();
//    delay(500);
//  }
//  rickshaw.write(straightRickshaw);
//
//}




void sideToSideShuffleGyroFemale() {


  analogWrite(enA, 150);


  rickshaw.write(10);




  while (getYRotation() < 10) {
    moveForward();
  }
  stopMotors();
  delay(500);
  while (getYRotation() > 0) {
    moveBackward();
  }
  stopMotors();
  delay(500);




  // rickshaw.write(straightRickshawWoman);



  //  while (getYRotation() < 0) {
  //    rickshaw.write(170);
  //    moveForward();
  //  }
  //  stopMotors();
  //  delay(500);
  //  rickshaw.write(straightRickshawWoman);

}
//void leftNRight() {
//  yaw = 0;
//
//
//
//
//  for (int i = 0; i < 5; i++) {
//    rickshaw.write(20);
//    while (getYRotation() < 15) {
//      moveForward();
//    }
//    stopMotors();
//    delay(200);
//
//    while (getYRotation() > -15) {
//      moveBackward();
//    }
//    delay(500);
//  }
//
//  rickshaw.write(straightRickshaw);
//}


void moveForwardForTime(int timeToMove) {


  if (role == "woman") {
    rickshaw.write(60);
  }

  else {
    rickshaw.write(120);
  }


  Serial.println("Moving Forward");
  yaw = 0;
  delay(200);

  moveForward();
  analogWrite(enA, 150);

  int oldTime = millis();
  while (millis() - oldTime < timeToMove) {


    Serial.println(getYRotation());
    if (getYRotation() > 0) {

      if (role == "man") {
        rickshaw.write(straightRickshawMan + 10); //110
      }
      else {
        //rickshaw.write(96); //110
        rickshaw.write(straightRickshawWoman + 10);

      }
      Serial.println("Correcting by going Right");
    }
    else if (getYRotation() < 0) {


      if (role == "man") {
        rickshaw.write(straightRickshawMan - 10); // 90
      }


      else {
        //rickshaw.write(86); // 90

        rickshaw.write(straightRickshawWoman - 10);
      }

      Serial.println("Correcting by going Left");
    }

  }


  stopMotors();
  delay(500);
  //  moveForward();
  //  //correct left
  //  if (getYRotation() < 0) {
  //
  //    rickshaw.write(20);
  //  }
  //  //correct Right
  //  else if (getYRotation() > 0) {
  //
  //    rickshaw.write(170);
  //  }

  //  stopMotors();
  //  delay(500);

  if (role == "man") {
    rickshaw.write(straightRickshawMan);
  }
  else if (role == "woman") {
    rickshaw.write(straightRickshawWoman);
  }


  stopMotors();

}


//left is negative, right is positive
float getYRotation() {
  timer = millis();

  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();

  // Calculate Pitch, Roll and Yaw
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;



  // Wait to full timeStep period
  delay((timeStep * 1000) - (millis() - timer));

  return yaw;
}
