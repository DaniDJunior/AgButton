#ifndef AgButton_h
#define AgButton_h

#include "Arduino.h"

class AgButton {
  public:
    AgButton(byte pin, bool pullDown = false);
    void setUP(long timeUp);
    void setDOWN(long timeDown); 
    void loop();
    bool Status;
    bool PulseUp;
    bool PulseDown;
    void onClick( void (*)(bool) );
  private:
    long previousMillis;
    long intervalUp;
    long intervalDown;
    long intervalDebounce;
    byte pino;
    void (*fun_onClick)(bool);
};

#endif
