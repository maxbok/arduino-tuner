#include "freq.h"

float freq;

void setup() {
  Serial.begin(9600);
}

void print_frequency(float freq) {
  Serial.print(freq);
  Serial.println(" hz");
}

void display_note(char note) {
  Serial.print(note);
}

void display_alteration(int alt) {
  if (alt == -1) {
    Serial.println("b");
  } else if (alt == 1) {
    Serial.println("#");
  } else {
      Serial.println();
  }
}

void display_decimal_part(float decimal_part) {
  Serial.print(decimal_part);
  Serial.println();
}

void loop() {
  freq = random(100, 500);

  print_frequency(freq);
  note_from_frequency(freq);

  Serial.println();
  delay(1000);
}

