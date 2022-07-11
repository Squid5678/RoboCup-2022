#include <IRremote.hpp>


#include <Wire.h>

#include <MPU6050.h>

#include <Servo.h>


#define straightRickshaw 95

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



String role = "man"; //or man or woman

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

  rickshaw.write(straightRickshaw);


  Serial.println("done with Setup. GYRO connected");
  //turnRight90();
  //  moveForward();
  //  delay(2000);
  //  stopMotors();


  
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
      sideToSideShuffleGyro();


    }

    //btn 2
    else if (code == 24) {
      Serial.println("Shuffling");
      leftNRight();


    }
    else {

    }


    IrReceiver.resume(); // Enable receiving of the next value
    //doing this after seems to stop double 90?

  }

}


void turnRight90() {
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
  rickshaw.write(straightRickshaw);

  yaw = 0; //Reset Gyro
}
void turnLeft90() {
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
  rickshaw.write(straightRickshaw);

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



void sideToSideShuffle() {
  rickshaw.write(170);

  for (int i = 0; i <= 5; i++) {
    moveForward();
    delay(500);
    stopMotors();
    delay(100);
    moveBackward();
    delay(500);
  }
  rickshaw.write(straightRickshaw);

}


void sideToSideShuffleGyro() {

  yaw = 0;

  rickshaw.write(170);



  for (int i = 0 ; i < 5; i++) {
    while (getYRotation() > -10) {
      moveForward();
    }
    delay(100);
    while (getYRotation() < 0) {
      moveBackward();
    }
    delay(100);

  }

  rickshaw.write(straightRickshaw);
  stopMotors();

}
void leftNRight() {
  yaw = 0;




  for (int i = 0; i < 5; i++) {
    rickshaw.write(20);
    while (getYRotation() < 15) {
      moveForward();
    }
    stopMotors();
    delay(200);

    while (getYRotation() > -15) {
      moveBackward();
    }
    delay(500);
  }

  rickshaw.write(straightRickshaw);
}


void moveForwardForTime(int timeToMove) {
  yaw = 0;


  moveForward();

  int oldTime = millis();
  while (millis() - oldTime < timeToMove) {
    Serial.println(getYRotation());
    if (getYRotation() > 0) {
      rickshaw.write(105); //110
      Serial.println("Correcting by going Right");
    }
    else if (getYRotation() < 0) {
      rickshaw.write(90); // 90
      Serial.println("Correcting by going Left");
    }

  }

  rickshaw.write(straightRickshaw);
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
