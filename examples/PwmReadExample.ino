#include <PwmRead.h>

//set analog pin to read the low passed pwm value
const int pwmReadPin = A6;
//setup PwmRead object with analog pin
PwmRead pwmRead(pwmReadPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //read value every 1000ms and make sure it is consistent within 10ms
  int readValue = pwmRead.ReadVal(10, 1000);

  //ReadVal will return -1 if value was not consistent in given timeframe
  if(readValue != -1) 
  {
    Serial.println(readValue);
  }
}