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
  // Code B decode for digits 7–0
  driver.decodeMode(0xFF);
  
  //driver.testOn();
  //delay(3000);
  //driver.testOff();

  //driver.shutdown(true);

  driver.setCodeDigit(1, B1100, false); // H
  driver.setCodeDigit(2, B1011, false); // E
  driver.setCodeDigit(3, B1101, false); // L
  driver.setCodeDigit(4, 0, false);     // 0
  driver.setCodeDigit(5, B1111, false);
  driver.setCodeDigit(6, B1111, false);
  driver.setCodeDigit(7, B1111, false);
  driver.setCodeDigit(8, B1111, false);
  delay(1000);

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

void loop() {
/*
  driver.setCodeDigit(1, B1100); // H
  driver.setCodeDigit(2, B1011); // E
  driver.setCodeDigit(3, B1101); // L
  driver.setCodeDigit(4, B1110); // P

  driver.setCodeDigit(5, 5);
  driver.setCodeDigit(6, 6);
  driver.setCodeDigit(7, 7);
  driver.setCodeDigit(8, 8);
  */
  
  double temperatureA = thermistor(analogRead(PIN_THERMISTOR_A));
  delay(100); // delay in between reads for stability
  double temperatureB = thermistor(analogRead(PIN_THERMISTOR_B));
  delay(100); // delay in between reads for stability

  char temperatureAstr[6];
  dtostrf(temperatureA, 5, 2, temperatureAstr);
  driver.setCodeDigit(1, temperatureAstr[0], false);
  driver.setCodeDigit(2, temperatureAstr[1], true);
  driver.setCodeDigit(3, temperatureAstr[3], false);
  driver.setCodeDigit(4, temperatureAstr[4], false);

  char temperatureBstr[6];
  dtostrf(temperatureB, 5, 2, temperatureBstr);
  driver.setCodeDigit(5, temperatureBstr[0], false);
  driver.setCodeDigit(6, temperatureBstr[1], true);
  driver.setCodeDigit(7, temperatureBstr[3], false);
  driver.setCodeDigit(8, temperatureBstr[4], false);

  delay(500);
}

