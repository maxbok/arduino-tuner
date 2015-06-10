/*
 *  fn = A4 * (a)^n
 *  a = (2)^(1/12) = 1.059463094
 *  n = half steps between the note and A4
 *
 *  n = log(fn/A4)/log(a)
 */

const float A4_note = 440;
const float loga = log10(1.059463094);
const int notes_count = 12;
const char notes[12] = {'A', 'x', 'B', 'C', 'x', 'D', 'x', 'E', 'F', 'x', 'G', 'x'};
float freq;

void setup() {
  Serial.begin(9600);
}

void print_frequency(float freq) {
  Serial.print(freq);
  Serial.println(" hz");
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

char note_from_index(int index) {
  index = fmod(round(index), notes_count);
  if (index < 0) {
    index += notes_count;
  }
  
  return notes[index];
}

float half_steps_from_frequency(float freq) {
  return log10(freq / A4_note) / loga;
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

