#include "seven_segment_display.h"
#include "global.h"
#include "Arduino.h"


void sevenSegmentDisplaySetup() {
  bitSet(SSD_LATCH_DDR, SSD_LATCH_BIT);
  bitSet(SSD_CLOCK_DDR, SSD_CLOCK_BIT);
  bitSet(SSD_DATA_DDR, SSD_DATA_BIT);
}

int dataForLetter(char letter) {
  if (letter == 0)
    return 0;
  if (letter == 'A')
    return 119;
  if (letter == 'B')
    return 124;
  if (letter == 'C')
    return 57;
  if (letter == 'D')
    return 94;
  if (letter == 'E')
    return 121;
  if (letter == 'F')
    return 113;
  if (letter == 'G')
    return 125;
    
  // Error
  return 128;
}

void displayLetter(char letter) {
  int data = dataForLetter(letter);

  bitSet(SSD_LATCH_PORT, SSD_LATCH_BIT);
  fastShiftOut(MSBFIRST, data);
  bitClear(SSD_LATCH_PORT, SSD_LATCH_BIT);
}

void fastShiftOut(uint8_t bitOrder, byte value) {
  int i;
  for (i = 0; i < 8; i++) {
    if (bitOrder == LSBFIRST) {
      bitWrite(SSD_DATA_PORT, SSD_DATA_BIT, !!(value & (1 << i)));
    } else {
      bitWrite(SSD_DATA_PORT, SSD_DATA_BIT, !!(value & (1 << (7 - i))));
    }
    
    bitSet(SSD_CLOCK_PORT, SSD_CLOCK_BIT);
    bitClear(SSD_CLOCK_PORT, SSD_CLOCK_BIT);
  }
}

