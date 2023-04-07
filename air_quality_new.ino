/*
    Grove_Air_Quality_Sensor.ino
    Demo for Grove - Air Quality Sensor.
    Copyright (c) 2019 seeed technology inc.
    Author    : Lets Blu
    Created Time : Jan 2019
    Modified Time:
    The MIT License (MIT)
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
#include "Air_Quality_Sensor.h"

AirQualitySensor sensor(A0);
const int green = 7;
const int red = 4;
const int yellow = 8;
//int timer;
const int FIVE_MINUTES = 300;

//int prevButtonState = 0;
const int twoSeconds = 2;
static unsigned int time = 0;


void setup() {

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  Serial.begin(9600);
  Serial.println("inside setup");
  while (!Serial)
    ;
  // initialize led as off
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
}


void loop() {
  //const unsigned long fiveMinutes = 2 * 1000UL;
  //static unsigned long lastSampleTime = 0;  // initialize such that a reading is due the first time through loop()
  Serial.println("Time");
  Serial.println(time);




  //if (on && (now - lastSampleTime >= fiveMinutes)) {
  if (time > twoSeconds) {
    Serial.print("Sensor value: ");
    int quality = sensor.slope();
    Serial.println("sensor.getValue()");
    Serial.println(sensor.getValue());
    Serial.println("quality");
    Serial.println(quality);

    if (quality == AirQualitySensor::FORCE_SIGNAL) {
      Serial.println("High pollution! Force signal active.");
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
      Serial.println("HIGH");
      digitalWrite(green, LOW);   // torn off green
      digitalWrite(yellow, LOW);  // turn on yellow
      digitalWrite(red, HIGH);
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
      Serial.println("LOW");
      digitalWrite(green, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);


    } else if (quality == AirQualitySensor::FRESH_AIR) {
      Serial.println("Fresh air");
      digitalWrite(green, HIGH);  // torn off green
      digitalWrite(yellow, LOW);  // turn on yellow
      digitalWrite(red, LOW);
    }
    time = 0;
  }
  /*
    if (on && timer > 2) {
      digitalWrite(transPin, HIGH);
      Serial.println("Reading");
      Serial.println("Waiting sensor to init...");

      int quality = sensor.slope();
      if (quality == AirQualitySensor::FORCE_SIGNAL) {
        Serial.println("High pollution! Force signal active.");
      } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        Serial.println("HIGH");
        /*
          digitalWrite(vibratorPin, HIGH);
          digitalWrite(vibratorPin, LOW);
          delay(1000);
          digitalWrite(vibratorPin, HIGH);
          digitalWrite(vibratorPin, LOW);
          delay(1000);
          digitalWrite(vibratorPin, HIGH);
          digitalWrite(vibratorPin, LOW);
      } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        Serial.println("LOW");
        /*
          digitalWrite(vibratorPin, HIGH);
          digitalWrite(vibratorPin, LOW);
          delay(1000);
          digitalWrite(vibratorPin, HIGH);
          digitalWrite(vibratorPin, LOW);
          delay(1000);
      } else if (quality == AirQualitySensor::FRESH_AIR) {
        Serial.println("Fresh air");
        digitalWrite(vibratorPin, HIGH);
        /*
          delay(1000);
          digitalWrite(vibratorPin, LOW);
      }
        Serial.println(btnState);
        int quality = sensor.slope();
        digitalWrite(vibrator, LOW);
        Serial.print("Sensor value: ");
        Serial.println(sensor.getValue());
        if (quality == AirQualitySensor::FORCE_SIGNAL) {
          Serial.println("High pollution! Force signal active.");
        } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
          Serial.println("High pollution!");
        } else if (quality == AirQualitySensor::LOW_POLLUTION) {
          Serial.println("Low pollution!");
        } else if (quality == AirQualitySensor::FRESH_AIR) {
          Serial.println("Fresh air.");
          digitalWrite(vibrator, HIGH);
          delay(10000);
        }
    }*/
  delay(2000);
  time += 1;
  Serial.println();
}