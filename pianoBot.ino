

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int enB = 11;
int in3 = 12;
int in4 = 13;

int position1 = 3;
int defaultPosition = 5;
int position3 = 7;

//for default, if moving away, move away then move closer

String currentState = "close";

int emitterPin = 9;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //  pinMode(position1, INPUT);
  //  pinMode(defaultPosition, INPUT);
  //  pinMode(position3, INPUT);

  //  IrSender.begin(emitterPin);


  Serial.println("Started Code");
  servo1.attach(2);
  servo2.attach(4);
  servo3.attach(6);
  servo4.attach(8);
  servo5.attach(10);
  //Active note, just default + 10
  //F default 70
  //G default 130  ||   100
  //G# default 120 || 100
  //A default 40 || 20
  //C default 120 || 100





  //  for (int i = 0; i < 10; i++) {
  //    servo1.write(70);
  //    delay(500);
  //    servo1.write(90);
  //    delay(500);
  //  }





  servo1.write(145);
  servo2.write(120);
  servo3.write(120);
  servo4.write(35);
  servo5.write(130);
  
  while(analogRead(A5) > 200){
    Serial.println("Waiting");
  }
  playSong();
}
void playSong() {

  Serial.println("PlaySong Started");
  play1(1800);

  play2(1800);
  //
  play4(1800);
  //
  play5(1800);



  play1(1800);

  play2(1800);

  play3(1800);

  play4(1600);

  delay(20);

  Serial.println("Start of the main melody");

  play4(800);

  delay(2850);
  play4(800);

  raiseUp();
  delay(500);

  while (analogRead(A3) > 800) {
    Serial.println("Shifting");
    moveAway();
  }
  Serial.println("Shifting Done!");

  stopMoving();
  defaultServoPositions();

  delay(1300);
  //need to figure out the time imbalance
  play1(900);

  play5(900);

  delay(900);

  play5(900);

  play1(900);

  raiseUp();
  delay(20);

  while(analogRead(A2) > 800){
    Serial.println("Shifting");
    moveCloser();
  }
  Serial.println("Stop Moving");
  stopMoving();
  defaultServoPositions();

  delay(200);
  play2(1600);

  Serial.println("Start of another new section");

  play4(1900);

  play5(900);

  play1(900);

  play4(1900); 

  play5(900);

  play1(900);

  play4(1900);

  play5(1900);

  play4(1900);

  play5(1900);

  play4(1900);

  play5(900);

  play1(900);

  play4(1900);

  play5(900);

  play2(900);

  play4(1900);

  play5(1900);

  play4(1900);

  play4(1900);

  

  

  

  
  




}
//void fingerTest(int pressDuration) {
//  Serial.println("Starting: FINGER TEST");
//  for (int i = 0; i < 10; i++) {
//    servo1.write(70);
//    servo2.write(100);
//    servo3.write(100);
//    servo4.write(20);
//    servo5.write(100);
//    delay(pressDuration);
//    servo1.write(100);
//    servo2.write(130);
//    servo3.write(130);
//    servo4.write(60);
//    servo5.write(130);
//    delay(pressDuration);
//  }
//  Serial.println("FINGER TEST DONE");
//}

void scaleTest(int pressDuration) {
  Serial.println("Starting: SCALE TEST");
  play1(pressDuration);
  play2(pressDuration);
  play3(pressDuration);
  play4(pressDuration);
  play5(pressDuration);
  Serial.println("SCALE TEST DONE");

  
}

void play1(int timeToPlay) {
  servo1.write(155);
  delay(timeToPlay);
  servo1.write(145);
}
void play2(int timeToPlay) {
  servo2.write(130);
  delay(timeToPlay);
  servo2.write(120);
}
void play3(int timeToPlay) {
  servo3.write(130);
  delay(timeToPlay);
  servo3.write(120);
}
void play4(int timeToPlay) {
  servo4.write(45);
  delay(timeToPlay);
  servo4.write(35);
}
void play5(int timeToPlay) {
  servo5.write(140);
  delay(timeToPlay);
  servo5.write(130);
}

void defaultServoPositions() {
  servo1.write(145);
  servo2.write(120);
  servo3.write(120);
  servo4.write(35);
  servo5.write(130);
}
void loop() {
  //  if (digitalRead(position1) == LOW) {
  //    Serial.println("position 1");
  //  }
  //  else if (digitalRead(defaultPosition) == LOW) {
  //    Serial.println("pos 2");
  //  }
  //  else if (digitalRead(position3) == LOW) {
  //    Serial.println("pos 3");
  //  }
  //






}


//75, 120, 120 30, 125
/*
  void play1() {
  servo1.write(100);

  servo2.write(100);

  servo3.write(100);

  servo4.write(20);

  servo5.write(100);

  }

  void play2() {
  servo1.write(70);

  servo2.write(130);
  servo3.write(100);

  servo4.write(20);

  servo5.write(100);

  }
  //75, 120, 120 30, 125
  void play3() {
  servo1.write(70);

  servo2.write(100);

  servo3.write(130);

  servo4.write(20);

  servo5.write(100);

  }

  void play4() {
  servo1.write(70);
  servo2.write(100);
  servo3.write(100);
  servo4.write(60);
  servo5.write(100);
  }
  //75, 120, 120 30, 125
  void play5() {
  servo1.write(70);
  servo2.write(100);
  servo3.write(100);
  servo4.write(20);
  servo5.write(130);
  }
*/
void playNone() {
  servo1.write(70);
  servo2.write(100);
  servo3.write(100);
  servo4.write(20);
  servo5.write(100);
}

void raiseUp() {
  servo1.write(50);
  servo2.write(100);
  servo3.write(100);
  servo4.write(10);
  servo5.write(105);
}
/*
  void playStuff() {
  play1();
  delay(1900);


  play2();
  delay(1900);


  play4();
  delay(1900);


  play5();
  delay(1900);


  play1();
  delay(1900);


  play2();
  delay(1900);


  play3();
  delay(1900);


  play4();
  delay(1000);


  playNone();
  delay(800);


  play4();
  delay(750);



  delay(250);
  delay(2750);


  play4();
  delay(750);

  delay(250);

  playNone();
  while (digitalRead(position3) == HIGH) {
    moveAway();
  }
  stopMoving();
  playNone();

  delay(1750);
  play1();
  delay(750);
  playNone();
  delay(250);


  play5();
  delay(750);
  playNone();
  delay(250);

  //28:22 mark is up till above
  delay(750);
  play5();
  delay(750);
  playNone();
  delay(275);


  //above ends the 32:04 mark
  play1();
  delay(750);
  playNone();
  delay(275);

  play5();
  delay(750);
  playNone();
  delay(250);

  raiseUp();
  while (digitalRead(defaultPosition) == HIGH) {
    moveCloser();
  }
  stopMoving();
  playNone();
  delay(750);

  //the above part is the G. I'm not playing anything, just using it as a break
  play4();
  delay(1650);
  playNone();
  delay(175);

  play5();
  delay(750);
  playNone();
  delay(175);

  play1();
  delay(750);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(175);

  play5();
  delay(750);
  playNone();
  delay(175);

  play1();
  delay(750);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(175);

  //the above part is before the quick sequence of notes that come after(starts with C)
  play5();
  delay(1650);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(175);

  play5();
  delay(750);
  playNone();
  delay(175);

  play1();
  delay(750);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(175);

  //prelude to the C and A repeating pattern
  play5();
  delay(1650);
  playNone();
  delay(175);

  //start of aforementioned pattern
  play4();
  delay(1650);
  playNone();
  delay(175);

  play5();
  delay(750);
  playNone();
  delay(200);

  play1();
  delay(750);
  playNone();
  delay(200);

  play4();
  delay(1650);
  playNone();
  delay(175);

  play5();
  delay(750);
  playNone();
  delay(200);

  play2();
  delay(750);
  playNone();
  delay(200);

  play4();
  delay(1650);
  playNone();
  delay(175);

  //below starts the other set of rapid notes, starting with C
  play5();
  delay(1650);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(175);

  play4();
  delay(1650);
  playNone();
  delay(200);

  play4();
  delay(1650);
  playNone();
  delay(200);

  //new part starts here:
  play1();
  delay(1650);
  playNone();
  delay(175);

  play2();
  delay(1600);
  playNone();
  delay(175);

  play4();
  delay(1600);
  playNone();
  delay(175);

  play5();
  delay(1600);
  playNone();
  delay(175);

  play1();
  delay(1600);
  playNone();
  delay(175);

  play2();
  delay(1600);
  playNone();
  delay(175);

  play3();
  delay(1600);
  playNone();
  delay(175);

  play4();
  delay(1600);
  playNone();
  delay(175);

  //recap section
  play1();
  delay(1900);
  play2();
  delay(1900);
  play4();
  delay(1900);
  play5();
  delay(1900);

  play1();
  delay(1900);
  play2();
  delay(1900);
  play3();
  delay(1900);
  play4();
  delay(1000);
  playNone();
  delay(1000);





  }
*/

void moveCloser() {
  analogWrite(enB, 175);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  currentState = "close";
}

void moveAway() {
  analogWrite(enB, 175);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  currentState = "away";
}

void stopMoving() {
  if (currentState == "close") {
    moveAway();
    delay(100);
    analogWrite(enB, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

  else if (currentState == "away") {
    moveCloser();
    delay(100);
    analogWrite(enB, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

}
