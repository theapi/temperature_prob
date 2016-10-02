/**
 * Two temperature probes with an ATTINY 85 & a MAX7219 to two 7 segment displays.
 * 
   [Ground] ---- [Thermistor] -------|------- [10k-Resistor] ---- [+5v]
                                     |
                                  Analog Pin
 */

#if defined( __AVR_ATtiny85__ )
  #define PIN_THERMISTOR_A A3
  #define PIN_THERMISTOR_B A2
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

// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 8

// Thermistor datasheet http://uk.farnell.com/vishay-bc-components/ntcle100e3103jb0/thermistor-10k-5-ntc-rad/dp/1187031
// resistance at 25 degrees C
#define THERMISTOR_NOMINAL 10000      
// temp. for nominal resistance (almost always 25 C)
#define THERMISTER_TEMPERATURE_NOMINAL 25  

// The beta coefficient of the thermistor (usually 3000-4000)
#define THERMISTOR_BCOEFFICIENT 3977
// the value of the 'other' resistor
#define THERMISTOR_SERIES_RESISTOR 10000   

Max72xx driver = Max72xx(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

void setup() {

  // Initialise the driver.
  driver.setup();
  
  // Code B decode for digits 7–0
  driver.decodeMode(0xFF);
  
  driver.setDigit(1, driver.H, false); // H
  driver.setDigit(2, driver.E, false); // E
  driver.setDigit(3, driver.L, false); // L
  driver.setDigit(4, 0, false);        // 0
  
  driver.setDigit(5, driver.Blank, false);
  driver.setDigit(6, driver.Blank, false);
  driver.setDigit(7, driver.Blank, false);
  driver.setDigit(8, driver.Blank, false);

  // Turn the display on.
  driver.displayOn();
  delay(1000);

  driver.setDigit(1, driver.Blank, false);
  driver.setDigit(2, driver.Blank, false);
  driver.setDigit(3, driver.Blank, false);
  driver.setDigit(4, driver.Blank, false);

}

/**
 * Get the temperature from the thermistor
 */
int readTemperature(byte pin)
{
  int count = 0;
  int sum = 0;
  double value;
  int rounded;

  // Junk the first reading as the analog pin mux just changed.
  analogRead(pin);
  
  while (count < NUMSAMPLES) {
    sum += analogRead(pin);
    count++;
  }
  value = (int)sum / NUMSAMPLES;

  // convert the value to resistance
  value = 1023 / value - 1;
  value = THERMISTOR_SERIES_RESISTOR / value;


  double steinhart;
  steinhart = value / THERMISTOR_NOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= THERMISTOR_BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (THERMISTER_TEMPERATURE_NOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;   

  rounded = steinhart * 10.0;
  return rounded;
}

void loop() {

  int temperatureA = readTemperature(PIN_THERMISTOR_A);
  char temperatureAstr[4];
  itoa(temperatureA, temperatureAstr, 10);
  
  driver.setDigit(2, temperatureAstr[0], false);
  driver.setDigit(3, temperatureAstr[1], true);
  driver.setDigit(4, temperatureAstr[2], false);

  int temperatureB = readTemperature(PIN_THERMISTOR_B);
  char temperatureBstr[4];
  itoa(temperatureB, temperatureBstr, 10);
  driver.setDigit(6, temperatureBstr[0], false);
  driver.setDigit(7, temperatureBstr[1], true);
  driver.setDigit(8, temperatureBstr[2], false);

  delay(500);
}

