#include "global.h"
#include "freq.h"
#include "seven_segment_display.h"
#include <Math.h>


char note_from_index(int index) {
  index = fmod(round(index), notes_count);
  if (index < 0) {
    index += notes_count;
  }

  return notes[index];
}

void display_note(char note) {
  displayLetter(note);
}

void display_alteration(int alt) {
  if (alt == -1) {
    //Serial.println("b");
  } else if (alt == 1) {
    //Serial.println("#");
  } else {
    //Serial.println();
  }
}

void display_decimal_part(float decimal_part) {
  //Serial.print(decimal_part);
  //Serial.println();
}

void note_from_frequency(float freq) {
  float n = half_steps_from_frequency(freq);
  int index = round(n);
  char note = note_from_index(index);
  int alteration = 0;

  float decimal_part = abs(modf(n, NULL));
  if (decimal_part > 0.5) {
    decimal_part = decimal_part - 1;
  }
  decimal_part = decimal_part * 2;

  if (note == 'x') {
    if (decimal_part > 0) {
      alteration = index > 0 ? 1 : -1;
    } else {
      alteration = index > 0 ? -1 : 1;
    }
  }
  note = note_from_index(index - alteration);

  display_note(note);
  display_alteration(alteration);
  display_decimal_part(decimal_part);
}

float half_steps_from_frequency(float freq) {
  return log10(freq / A4_note) / loga;
}
