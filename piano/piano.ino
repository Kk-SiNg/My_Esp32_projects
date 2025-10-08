// Define musical note frequencies
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A5 440
#define NOTE_B5 494
#define NOTE_C5 523

int threshold = 30;
int TONE_CHANNEL = 0;
int passive_buzzer_pin = 4;

void setup() {
 ledcAttachPin(4, TONE_CHANNEL);
}

void loop() {

  int c_4 = touchRead(T0);
  int d_4 = touchRead(T1);
  int e_4 = touchRead(T2);
  int f_4 = touchRead(T3);
  int g_4 = touchRead(T4);
  int a_5 = touchRead(T5);
  int b_5 = touchRead(T6);
  int c_5 = touchRead(T7);

  if (c_4 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_C4);
  } 
  else if (d_4 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_D4);
  } 
  else if (e_4 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_E4);
  } 
  else if (f_4 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_F4);
  } 
  else if (g_4 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_G4);
  } 
  else if (a_5 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_A5);
  } 
  else if (b_5 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_B5);
  } 
  else if (c_5 < threshold) {
    play_frequency(TONE_CHANNEL, NOTE_C5);
  } 
  else {
    // If no key is being touched, turn the sound off.
    play_frequency(TONE_CHANNEL, 0);
  }
}

void play_frequency(int TONE_CHANNEL, int frequency){

  ledcSetup(TONE_CHANNEL, frequency, 8);
  ledcWriteTone(TONE_CHANNEL, frequency);

  for(int i = 255; i >= 50; i -= 5){
    ledcWrite(TONE_CHANNEL, i);
    delay(5);
  }
  ledcWrite(TONE_CHANNEL, 0);

}

