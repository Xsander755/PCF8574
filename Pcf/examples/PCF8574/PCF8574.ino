/* Example sketch showing use of the Pcf Library.
 * Written by James Petersen, 2013.
 * Copyright under the GPL.
 *
 * If you are using an Arduino Uno, connect pin A4 (SDA) to pin 15 on the PCF8574, and
 * pin A5 (SCL) to pin 14 on the PCF8574. If using a different Arduino, look up which
 * pins are used for I2C and connect them according to the instructions.
 *
 * This sketch will demonstrate using the different methods to control specific pins
 * on the I/O port expander. Each pin is addressed by its corresponding binary value.
 * To simplify control of individual pins, an array is defined where each element 
 * corresponds to the binary value of the associated pin. To turn on multiple pins,
 * simply use the sum of the values of pins you would like to control.
 *
 * To use this sketch, connect each of the 8 outputs to the positive lead of an LED.
 * Connect the negative lead through a current-limiting resistor, then to ground.
 */

#include <Pcf.h>
#include <Wire.h>

// Array of 8 elements corresponding to each individual pin on the PCF8574.
const int led[] = {1, 2, 4, 8, 16, 32, 64, 128};

// Declare a new variable pcf at the default address. Check the datasheet for information about addresses for PCF8574 and PCF8574A.
Pcf pcf = Pcf(0x20); // 0x20 is the default address for the PCF8574 with all three input pins tied to ground.

// Use this declaration instead if you are using a PCF8574A.
// Pcf pcf = Pcf(0x70); // 0x70 is the default address for the PCF8574A with all three input pins tied to ground.


void setup(){
  pcf.writeData(255); // turns on all 8 pins
  delay(1000);
  pcf.clearData(); // turns off all 8 pins
}

void loop(){
  
  // turn on pins 0 through 7 one at a time
  for (int i = 0; i < 8; i++){
    pcf.writePin(i, 1);
    delay(500);
  }
  
  // toggle each pin on and off once
  for (int i = 0; i < 8; i++){
    pcf.togglePin(i);
    delay(500);
    pcf.togglePin(i);
    delay(500);
  }
  
  // store the data from the pcf in the byte variable pcfData
  byte pcfData = pcf.readData();
  
  // store the state of each pin in an array of booleans
  boolean pinState[8] = {0};
  for (int i = 0; i < 8; i++){
    pinState[i] = pcf.readPin(i);
  }
  
}
