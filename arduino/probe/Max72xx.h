
#ifndef Max72xx_h
#define Max72xx_h

#include "Arduino.h"

class Max72xx {
    private :

        // Data is shifted out of this pin
        byte _din;
        // The clock is signaled on this pin
        byte _clk;
        // Driven LOW to latch the data
        byte _load;

    public:
      /**
       * Constructor
       * dataPin    shifts the data out
       * clockPin   the clock
       * latchPin   the data latch
       */
      Max72xx(int dataPin, int clkPin, int latchPin);

      /**
       * Sends the 16 bit serial packet to the driver
       */
      void sendPacket(int8_t address, int8_t data);

      /**
       * Set the number of digits (or rows) to be displayed.
       * See datasheet for sideeffects of the scanlimit on the brightness
       * of the display.
       * @param limit  The number of digits to be displayed (1..8)
       */
      void setScanLimit(byte limit);

      void setIntensity(byte intensity);

      void testOn();

      void testOff();

      void shutdown(bool b);


};

#endif

