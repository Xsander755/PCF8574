/*
  Pcf.h - Library for controlling a PCF8574 I/O port expander.

    Created by James Petersen, 2013.

    Released under the GPL.

*/



#ifndef Pcf_h

#define Pcf_h

#include "Arduino.h"

#include "Wire.h"



class Pcf

{

  public:

    Pcf(byte address);

    void togglePin(byte pin);

    void writePin(byte pin, boolean value);

    boolean readPin(byte pin);

    void writeData(byte data);

    int readData();

    void clearData();

  private:

    int _address;
};



#endif
