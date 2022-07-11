/*
   SimpleSender.cpp

    Demonstrates sending IR codes in standard format with address and command
    An extended example for sending can be found as SendDemo.

    Copyright (C) 2020-2021  Armin Joachimsmeyer
    armin.joachimsmeyer@gmail.com

    This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.

    MIT License
*/
#include <Arduino.h>


#include <IRremote.hpp>

void setup() {


  Serial.begin(9600);


  /*
     The IR library setup. That's all!
  */
  IrSender.begin(8); // Start with IR_SEND_PIN as send pin and if NO_LED_FEEDBACK_CODE is NOT defined, enable feedback LED at default feedback LED pin

  Serial.println("started");
}



bool emit = false;
void loop() {


  //A0 is broken?
  if (analogRead(A1) < 200) {
    emit = true;

    Serial.println("Detected");
  }

  if (emit == false) {
    return;
  }

  Serial.println("Sending");
  // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
  IrSender.sendNEC(0, 101, 5);



  delay(1000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal


}
