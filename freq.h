/*
 *  fn = A4 * (a)^n
 *  a = (2)^(1/12) = 1.059463094
 *  n = half steps between the note and A4
 *
 *  n = log(fn/A4)/log(a)
 */

#ifdef __cplusplus
extern "C" {
#endif

const float A4_note = 440;
const float loga = 0.02508583282; //log(1.059463094)
const int notes_count = 12;
const char notes[12] = {'A', 'x', 'B', 'C', 'x', 'D', 'x', 'E', 'F', 'x', 'G', 'x'};

void note_from_frequency(float freq);
char note_from_index(int index);
float half_steps_from_frequency(float freq);

#ifdef __cplusplus
}
#endif

