int spkPin = 11;
int sirPin = 30;

extern const int laser_count;
extern const int photo_count;

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int melody3[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5  
};

int melody2[] = {
  0, NOTE_CS7, 0, 0, NOTE_E6, NOTE_A6, NOTE_B6,
  NOTE_AS6, NOTE_A7, NOTE_F7, NOTE_D7, NOTE_B6, 0
};

int tempo2[] = { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12  };

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_CS7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

   NOTE_CS7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_CS7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_CS7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_CS7,
  NOTE_D7, NOTE_B6, 0, 0
};

#define max_notes (sizeof(melody) / sizeof(melody[0]))

int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


int note_index = -1;
bool new_note = true;
bool up_wave = false;
bool spacing = false;
int play_ticks;
int space_ticks;
int music_playing = true;

/*
 * La idea: Se llama esto cuando cae el counter. El counter es 1/2 de la frecuencia. Mitad On / Mitad Off / 1/3 Off espacio (Tiempo aca)
 * Se repite times veces segun el tempo.
 */

long d = 0;

ISR(TIMER1_COMPA_vect) {          // timer compare interrupt service routine

  if (!music_playing) return;

  if (new_note) {
    noInterrupts();
    note_index++;
    if (note_index >= max_notes) note_index = 0;
    new_note = false;

    // Frecuencia del clock. Recordar que 2000000 (2M) es 1 seg.
    int f = melody[note_index] * 2; // Calculo el doble por el on - off, de a 1/2 ciclo
    if (!f) f = 200; // Lo filtro luego
    int cnt = (int)(2000000l / f);
    OCR1A = cnt;

    play_ticks =  f  / (2 * tempo[note_index]);
    space_ticks = f / 5; // 0.3 segs
    spacing = false;
    up_wave = false;
    interrupts();

/*
    Serial.print(note_index);
    Serial.print(" - ");
    Serial.print(melody[note_index]);
    Serial.print(" - ");
    Serial.print(f);
    Serial.print(" - ");
    Serial.print(cnt);
    Serial.print(" - ");
    Serial.print(play_ticks);
    Serial.print(" - ");
    Serial.println(millis() - d);
    d = millis();
*/
    if (melody[note_index] != 0)
      digitalWrite(13, HIGH);
  }

  if (spacing) {
    if(space_ticks-- <= 0) {
      spacing = false;
      new_note = true;
    }
    return;
  }

  if (play_ticks-- <= 0) {
    digitalWrite(spkPin, LOW);
    digitalWrite(13, LOW);
    spacing = true;
    return;
  }

  if (up_wave) {
    up_wave = !up_wave;
    if (melody[note_index] != 0)
      digitalWrite(spkPin, HIGH);
  } else {
    up_wave = !up_wave;
    digitalWrite(spkPin, LOW);
  }
}

void music_start() {
  music_playing = true;
}

void music_stop() {
  music_playing = false;
  digitalWrite(spkPin, LOW);
}

void music_setup(int sp) {
  noInterrupts();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 100; 
  TCCR1B |= (1<<CS11); // 8 prescaler
  TCCR1B |= (1<<WGM12);              // CTC Mode 1

  TIMSK1 |= (1 << OCIE1A);

  interrupts();

  spkPin = sp;
  pinMode(spkPin, OUTPUT);
  digitalWrite(spkPin, LOW);
}

int sens = 10;

inline void sir_on() {
  digitalWrite(sirPin, LOW);
}

inline void sir_off() {
  digitalWrite(sirPin, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(13, OUTPUT);
  pinMode(sirPin, OUTPUT);
  sir_off();

  photo_setup();
  photo_adjust();

  music_setup(spkPin);

  sens = 20;

  Serial.print("On: ");
  Serial.println(photo_get_prom_on(0));

  Serial.print("Off: ");
  Serial.println(photo_get_prom_off(0));

  Serial.print("Sens: ");
  Serial.println(sens);

  for(int ii=0; ii<laser_count; ii++)
    laser_on(ii);

  music_start();
}


void loop() {
  //tone(11, 2000, 500);
  for(int ii=0; ii<photo_count; ii++) {
    int v1 = photo_get_measure(ii);
    /*
    Serial.print(ii);
    Serial.print(": ");
    Serial.println(v1);
    */
    if (v1 < photo_get_prom_on(ii) - sens) {
      Serial.print("Cortado: "); 
      Serial.println(ii);
      sir_on();
      delay(300);
      sir_off();
      delay(1000);
      return;
    }
  }
  //delay(500);
}
