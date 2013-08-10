/*  Pcf.cpp - Library for controlling a PCF8574 I/O port expander.
    Created by James Petersen, 2013.
    Released under the GPL.
*/

#include "Arduino.h"
#include "Pcf.h"
#include "Wire.h"

Pcf::Pcf(byte address)
{
  Wire.begin();
  _address = address;
  Wire.beginTransmission(_address);
  Wire.write((byte)0x00);
  Wire.endTransmission(_address);
}

void Pcf::togglePin(byte pin) {
  Wire.requestFrom(_address,1);
  byte _data = 0;
  if(Wire.available()) {
    _data = Wire.read();
  }
  boolean _bit = bitRead(_data, pin);
  bitWrite(_data, pin, ~_bit);
  Wire.beginTransmission(_address);
  Wire.write((byte)_data);
  Wire.endTransmission(_address);
}

void Pcf::clearData() {
  Wire.beginTransmission(_address);
  Wire.write((byte)0x00);
  Wire.endTransmission(_address);
}

void Pcf::writePin(byte pin, boolean value) {
  Wire.requestFrom(_address,1);
  byte _data = 0;
  if(Wire.available()) {
    _data = Wire.read();
  }
  bitWrite(_data, pin, value);
  Wire.beginTransmission(_address);
  Wire.write((byte)_data);
  Wire.endTransmission(_address);
}  

void Pcf::writeData(byte data) {
  Wire.beginTransmission(_address);
  Wire.write((byte)data);
  Wire.endTransmission(_address);
}

int Pcf::readData() {
  Wire.requestFrom(_address,1);
  int _data = 0;
  if(Wire.available()) {
    _data = Wire.read();
  }
  return _data;
}

boolean Pcf::readPin(byte pin) {
  Wire.requestFrom(_address,1);
  byte _data = 0;
  if(Wire.available()) {
    _data = Wire.read();
  }
  return bitRead(_data, pin);
}