/*
    Air_Quality_Sensor.h
    Header file for Grove - Air Quality Sensor.
    Copyright (c) 2019 seeed technology inc.
    Author		: Lets Blu
    Created Time	: Jan 2019
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
#ifndef __AIR_QUALITY_SENSOR_H__
#define __AIR_QUALITY_SENSOR_H__

#include "Arduino.h"

class AirQualitySensor {
  public:
    AirQualitySensor(int pin);

    bool init(void);
    int  slope(void);
    int  getValue(void);

    static const int FORCE_SIGNAL;
    static const int HIGH_POLLUTION;
    static const int LOW_POLLUTION;
    static const int FRESH_AIR;

  protected:
    int  _pin;

    int  _lastVoltage;
    int  _currentVoltage;
    int  _standardVoltage;

    long _voltageSum;
    int  _volSumCount;
    long _lastStdVolUpdated;

    void updateStandardVoltage(void);
};

#endif // __AIR_QUALITY_SENSOR_H__