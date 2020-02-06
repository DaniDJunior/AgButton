#include "AgButton.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

AgButton::AgButton(byte pin, bool pullDown) {
  pinMode(pin, INPUT_PULLUP);
  pino = pin;
  Status = pullDown;
  intervalUp = 0;
  intervalDown = 0;
  intervalDebounce = 200;
}

void AgButton::setUP(long timeUp) {
  intervalUp = timeUp;
}

void AgButton::setDOWN(long timeDown) {
  intervalDown = timeDown;
}

void AgButton::loop() {
  long currentMillis = millis();
  
  // put your main code here, to run repeatedly:
  int btn = digitalRead(pino);

  if(Status)
  {
     PulseUp = false;
     if(!btn && (previousMillis == 0))
     {
          previousMillis = currentMillis;
     }
     if(btn && (currentMillis - previousMillis > intervalDebounce)) {
          previousMillis = 0;
     }
     if(!btn && (currentMillis - previousMillis > intervalDebounce + intervalDown)) {
          previousMillis = 0;
          Status = false;
          PulseDown = true;
          if(fun_onClick)
               (*fun_onClick)(Status);
     }
  }
  else
  {
     PulseDown = false;
     if(btn && (previousMillis == 0))
     {
          previousMillis = currentMillis;
     }
     if(!btn && (currentMillis - previousMillis > intervalDebounce)) {
          previousMillis = 0;
     }
     if(btn && (currentMillis - previousMillis > intervalDebounce + intervalUp)) {
          previousMillis = 0;
          Status = true;
          PulseUp = true;
          if(fun_onClick)
               (*fun_onClick)(Status); 
     }    
  }
}

void A2a::onClick( void (*function)(bool) )
{
     fun_onClick = function;
}
