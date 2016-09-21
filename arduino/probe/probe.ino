/**
 * Two temperature probes with an ATTINY 85 & a MAX7219 to two 7 segment displays.
 */

#if defined( __AVR_ATtiny85__ )
  #define PIN_THERMISTOR_A PB3
  #define PIN_THERMISTOR_B PB4
  #define DRIVER_DIN  PB0
  #define DRIVER_SCK  PB2
  #define DRIVER_LOAD PB1
#else
  #define PIN_THERMISTOR_A A0
  #define PIN_THERMISTOR_B A1
  #define DRIVER_DIN  12
  #define DRIVER_SCK  11
  #define DRIVER_LOAD 10
#endif

#include "Max72xx.h"

Max72xx driver = Max72xx(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

void setup() {

  driver.shutdown(false);
  driver.testOn();
  delay(3000);
  driver.testOff();

  driver.shutdown(true);

  /*
  pinMode(DRIVER_DIN, OUTPUT);
  pinMode(DRIVER_SCK, OUTPUT);
  pinMode(DRIVER_LOAD, OUTPUT);

  digitalWrite(DRIVER_LOAD,HIGH);
  max72xxDisplayTestOn();

  delay(3000);
  max72xxDisplayTestOff();
  max72xxShutdown();
  */
}

/**
 * Do a bunch of mathmatics on the voltage reading from the sensor.
 * 
 * @see http://playground.arduino.cc/ComponentLib/Thermistor2
 */
double thermistor(int raw_adc) {   
 double temp;
 temp = log(10000.0 * ((1024.0/raw_adc-1))); 
 temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
 temp = temp - 273.15;            // Convert Kelvin to Celcius
 
 return temp;
}

/**
 * Sends the 16 bit serial packet to the driver
 */
void max72xxSendPacket(int8_t address, int8_t data) {
  digitalWrite(DRIVER_LOAD,LOW);
  // shift out highbyte
  shiftOut(DRIVER_DIN, DRIVER_SCK, MSBFIRST, address);
  // shift out lowbyte
  shiftOut(DRIVER_DIN, DRIVER_SCK, MSBFIRST, data);
  digitalWrite(DRIVER_LOAD,HIGH);
}

/**
 * Set the display mode on.
 */
void max72xxDisplayTestOn() {
  max72xxSendPacket(B00001111, B00000001);
}

/**
 * Set the display mode off.
 */
void max72xxDisplayTestOff() {
  max72xxSendPacket(B00001111, B00000000);
}

void max72xxShutdown() {
  max72xxSendPacket(B00001100, B00000000);
}

void loop() {
  double temperatureA = thermistor(analogRead(PIN_THERMISTOR_A));
  delay(100); // delay in between reads for stability
  double temperatureB = thermistor(analogRead(PIN_THERMISTOR_B));
  delay(100); // delay in between reads for stability
}

