#include "freq.h"
#include "seven_segment_display.h"

float freq;

void setup() {
  sevenSegmentDisplaySetup();
  
  Serial.begin(9600);
}

void print_frequency(float freq) {
  Serial.print(freq);
  Serial.println(" hz");
}

void loop() {
  freq = 5274.04;//random(100, 500);

  print_frequency(freq);
  note_from_frequency(freq);

  Serial.println();
  delay(1000);
}

