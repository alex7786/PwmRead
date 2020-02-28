/*
  PwmRead.cpp - Library for reading a pwm signal and get a value.
  Created by Alexander Leiser, February 27, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "PwmRead.h"

PwmRead::PwmRead(int pwmPin)
{
  _pwmPin = pwmPin;
  //initialize values
  time_now = 0;
  pwmReadVal = 0;
}

int PwmRead::ReadVal(int bufferSize, int readPeriod)
{
  int outputValDebounced[bufferSize];
  bool stable = false;
  int sensorValue = 0; 
  int outputValue = 0; 
  int outputValueOut = -1;

  if(millis() >= time_now + readPeriod){
	time_now += readPeriod;
	for(int i = 0; i < bufferSize; i++){
	  // read the analog in value:
	  sensorValue = analogRead(_pwmPin);
	  // map it to the range of the analog out:
	  outputValue = map(sensorValue, 0, 1023, 0, 63);
	  
	  outputValDebounced[i] = outputValue;
	  delay(1);

	  if(i != 0){
		if(outputValDebounced[i] != outputValDebounced[i-1]){
		  stable = false;
		  break;
		}
		else{
		  stable = true;
		}
	  }
	}
	
	if(stable){
	  outputValueOut = outputValue;
	}
  }
  return outputValueOut;
}
