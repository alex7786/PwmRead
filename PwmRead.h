/*
  PwmRead.h - Library for reading a pwm signal and get a value.
  Created by Alexander Leiser, February 27, 2020.
  Released into the public domain.
*/

#ifndef PwmRead_h
#define PwmRead_h

#include "Arduino.h"

class PwmRead
{
  public:
    PwmRead(int pwmPin);
    int ReadVal(int arraySize, int readPeriod);
  private:
	int _pwmPin;
    int pwmReadVal;
	unsigned long time_now;	//to not use delay function
};

#endif