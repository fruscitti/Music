int spkPin = 11;

int notes[] = {
31    ,4032,
33    ,3788,
35    ,3571,
37    ,3378,
39    ,3205,
41    ,3049,
44    ,2841,
46    ,2717,
49    ,2551,
52    ,2404,
55    ,2273,
58    ,2155,
62    ,2016,
65    ,1923,
69    ,1812,
73    ,1712,
78    ,1603,
82    ,1524,
87    ,1437,
93    ,1344,
98    ,1276,
104   ,1202,
110   ,1136,
117   ,1068,
123   ,1016,
131   ,954,
139   ,899,
147   ,850,
156   ,801,
165   ,758,
175   ,714,
185   ,676,
196   ,638,
208   ,601,
220   ,568,
233   ,536,
247   ,506,
262   ,477,
277   ,451,
294   ,425,
311   ,402,
330   ,379,
349   ,358,
370   ,338,
392   ,319,
415   ,301,
440   ,284,
466   ,268,
494   ,253,
523   ,239,
554   ,226,
587   ,213,
622   ,201,
659   ,190,
698   ,179,
740   ,169,
784   ,159,
831   ,150,
880   ,142,
932   ,134,
988   ,127,
1047  ,119,
1109  ,113,
1175  ,106,
1245  ,100,
1319  ,95,
1397  ,89,
1480  ,84,
1568  ,80,
1661  ,75,
1760  ,71,
1865  ,67,
1976  ,63,
2093  ,60,
2217  ,56,
2349  ,53,
2489  ,50,
2637  ,47,
2794  ,45,
2960  ,42,
3136  ,40,
3322  ,38,
3520  ,36,
3729  ,34,
3951  ,32,
4186  ,30,
4435  ,28,
4699  ,27,
4978  ,25 };



#define NOTE_B0  0
#define NOTE_C1  1
#define NOTE_CS1 2
#define NOTE_D1  3
#define NOTE_DS1 4
#define NOTE_E1  5
#define NOTE_F1  6
#define NOTE_FS1 7
#define NOTE_G1  8
#define NOTE_GS1 9
#define NOTE_A1  10
#define NOTE_AS1 11
#define NOTE_B1  12
#define NOTE_C2  13
#define NOTE_CS2 14
#define NOTE_D2  15
#define NOTE_DS2 16
#define NOTE_E2  17
#define NOTE_F2  18
#define NOTE_FS2 19
#define NOTE_G2  20
#define NOTE_GS2 21
#define NOTE_A2  22
#define NOTE_AS2 23
#define NOTE_B2  24
#define NOTE_C3  25
#define NOTE_CS3 26
#define NOTE_D3  27
#define NOTE_DS3 28
#define NOTE_E3  29
#define NOTE_F3  30
#define NOTE_FS3 31
#define NOTE_G3  32
#define NOTE_GS3 33
#define NOTE_A3  34
#define NOTE_AS3 35
#define NOTE_B3  36
#define NOTE_C4  37
#define NOTE_CS4 38
#define NOTE_D4  39
#define NOTE_DS4 40
#define NOTE_E4  41
#define NOTE_F4  42
#define NOTE_FS4 43
#define NOTE_G4  44
#define NOTE_GS4 45
#define NOTE_A4  46
#define NOTE_AS4 47
#define NOTE_B4  48
#define NOTE_C5  49
#define NOTE_CS5 50
#define NOTE_D5  51
#define NOTE_DS5 52
#define NOTE_E5  53
#define NOTE_F5  54
#define NOTE_FS5 55
#define NOTE_G5  56
#define NOTE_GS5 57
#define NOTE_A5  58
#define NOTE_AS5 59
#define NOTE_B5  60
#define NOTE_C6  61
#define NOTE_CS6 62
#define NOTE_D6  63
#define NOTE_DS6 64
#define NOTE_E6  65
#define NOTE_F6  66
#define NOTE_FS6 67
#define NOTE_G6  68
#define NOTE_GS6 69
#define NOTE_A6  70
#define NOTE_AS6 71
#define NOTE_B6  72
#define NOTE_C7  73
#define NOTE_CS7 74
#define NOTE_D7  75
#define NOTE_DS7 76
#define NOTE_E7  77
#define NOTE_F7  78
#define NOTE_FS7 79
#define NOTE_G7  80
#define NOTE_GS7 81
#define NOTE_A7  82
#define NOTE_AS7 83
#define NOTE_B7  84
#define NOTE_C8  85
#define NOTE_CS8 86
#define NOTE_D8  87
#define NOTE_DS8 88


int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

   NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
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
int new_note = true;
int time_cut = 0;
int space_cut;
int time_count;
int space_count;
bool up_wave = false;
bool spacing = false;
int ns, ne;
int music_playing = true;

/*
 * La idea: Se llama esto cuando cae el counter. El counter es 1/2 de la frecuencia. Mitad On / Mitad Off / 1/3 Off espacio (Tiempo aca)
 * Se repite times veces segun el tempo.
 */
ISR(TIMER1_COMPA_vect) {          // timer compare interrupt service routine

  if (!music_playing) return;

  if (new_note) {
    //Serial.println("New Note");
    note_index++;
    if (note_index >= max_notes) note_index = 0;
    new_note = false;
    time_cut = notes[melody[note_index] * 2] / tempo[note_index];
    time_cut = (time_cut * 3) / 2; //time_cut % 2;
    space_cut = time_cut / 3;

    /*
    Serial.print("Tempo: ");
    Serial.println(notes[melody[note_index] * 2  + 1]);
    Serial.print("TimeCut: ");
    Serial.println(time_cut);
    */

    spacing = false;
    time_count = 0;
    up_wave = false;

    /*
    digitalWrite(spkPin, HIGH);
    digitalWrite(13, HIGH);
    */

    OCR1A = notes[melody[note_index] * 2 + 1] * 2; // freq    

    /*
    Serial.print("Freq: ");
    Serial.println(OCR1A);
    */

    if (melody[note_index] != 0)
      digitalWrite(13, HIGH);
    ns = millis();
  }

  if (spacing) {
    if(++space_count >= space_cut) {
      spacing = false;
      new_note = true;
    }
    return;
  }

  if (time_count++ >= time_cut) {
    digitalWrite(spkPin, LOW);
    digitalWrite(13, LOW);
    spacing = true;
    space_count = 0;
    //Serial.println(millis() - ns);
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

  //OCR1A = 15625; // 1 seg ?? ponele
  OCR1A = 100; // TICKS_BASE;   // 0.1 segs
  TCCR1B |= ((1<<CS11) | (1<<CS10)); // 1024 prescaler
  TCCR1B |= (1<<WGM12);              // CTC Mode 1

  TIMSK1 |= (1 << OCIE1A);

  interrupts();

  spkPin = sp;
  pinMode(spkPin, OUTPUT);
  digitalWrite(spkPin, LOW);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);

  timer_setup();

  Serial.begin(9600);
}


void loop() {
 
}
