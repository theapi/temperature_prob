
#include "Max72xx.h"

Max72xx::Max72xx(int dataPin, int clkPin, int latchPin) {
  _din = dataPin;
  _clk = clkPin;
  _load = latchPin;

  pinMode(_din, OUTPUT);
  pinMode(_clk, OUTPUT);
  pinMode(_load, OUTPUT);

  shutdown(1);
  setScanLimit(7);
  setIntensity(10);
}

/**
 * Sends the 16 bit serial packet to the driver
 */
void Max72xx::sendPacket(int8_t address, int8_t data) {
  digitalWrite(_load, LOW);
  // shift out highbyte
  shiftOut(_din, _clk, MSBFIRST, address);
  // shift out lowbyte
  shiftOut(_din, _clk, MSBFIRST, data);
  digitalWrite(_load, HIGH);
}

void Max72xx::setScanLimit(byte limit) {
  sendPacket(0x0B, limit);
}

void Max72xx::setIntensity(byte intensity) {
  sendPacket(0x0A, intensity);
}

/**
 * Set the display mode on.
 */
void Max72xx::testOn() {
  sendPacket(0x0F, B00000001);
}

/**
 * Set the display mode off.
 */
void Max72xx::testOff() {
  sendPacket(0x0F, B00000000);
}

void Max72xx::shutdown(bool b) {
  if (b) {
    sendPacket(0x0C, 0);
  } else {
    sendPacket(0x0C, 1);
  }
}

