byte lasers[] = {22,24,26,28};
bool laser_status[] = {false, false, false, false};

const int laser_count (sizeof(lasers)/sizeof(lasers[0]));

byte photos[] = {A0, A1, A2, A3};
const int photo_count (sizeof(photos)/sizeof(photos[0]));

#define SAMPLES 10

int photo_on_samples [photo_count][SAMPLES];
int photo_off_samples[photo_count][SAMPLES];
int photo_on_index = 0;
int photo_on_sum[photo_count];
int photo_on_prom[photo_count];
int photo_off_index = 0;
int photo_off_sum[photo_count];
int photo_off_prom[photo_count];
int photo_on_sample_count = 0;
int photo_off_sample_count = 0;

inline void laser_on(byte laser) {
  digitalWrite(lasers[laser], HIGH);
}

inline void laser_off(byte laser) {
  digitalWrite(lasers[laser], LOW);
}

void photo_add_measure(int ph, int measure, bool laser_status) {
  if (laser_status) {
    photo_on_sum[ph] -= photo_on_samples[ph][photo_on_index];
    photo_on_samples[ph][photo_on_index] = measure;
    photo_on_sum[ph] += measure;
    if(++photo_on_index > SAMPLES) photo_on_index = 0;
    if(photo_on_sample_count < SAMPLES) photo_on_sample_count++;
  } else {
    photo_off_sum[ph] -= photo_off_samples[ph][photo_off_index];
    photo_off_samples[ph][photo_off_index] = measure;
    photo_off_sum[ph] += measure;
    if(++photo_off_index > SAMPLES) photo_off_index = 0;
    if(photo_off_sample_count < SAMPLES) photo_off_sample_count++;
  }  
}

int photo_get_measure(int ph) {
  long total = 0;
  const int count = 10;
  for(int ii = 0; ii<count; ii++) {
    total += analogRead(photos[ph]);
    delay(1);
  }
  /*
  Serial.print("  total: ");
  Serial.print(total);
  Serial.print("  count: ");
  Serial.println(count);
  */
  
  return (int)(total/count);
}

void photo_setup() {
  for(int ii=0; ii < laser_count; ii++)
    pinMode(lasers[ii], OUTPUT);

  for(int ii=0; ii < photo_count; ii++)
    pinMode(photos[ii], INPUT);
  
  for(int ph=0; ph < photo_count; ph++) {
    for(int s=0; s < SAMPLES; s++) {
      photo_on_samples[ph][s] = 0;
      photo_off_samples[ph][s] = 0;
    }
    photo_on_sum[ph] = 0;
    photo_on_prom[ph] = 0;
    photo_off_sum[ph] = 0;
    photo_off_prom[ph] = 0;
  }
  
  photo_on_index = 0;
  photo_off_index = 0;
  photo_on_sample_count = 0;
  photo_off_sample_count = 0;
}

inline int photo_get_prom_on(byte ph) {
  return photo_on_prom[ph];
}

inline int photo_get_prom_off(byte ph) {
  return photo_off_prom[ph];
}

void photo_adjust() {

  // Inicializo
  photo_setup();
  
  // Promedio de SAMPLES mediciones todas las fotoresitores con el laser prendido y apagado
  for(int ph=0; ph<photo_count; ph++) {
    laser_on(ph);
  }
  
  delay(10);
  
  for (int s=0; s<10; s++) {
    for(int ph=0; ph<photo_count; ph++) {
      photo_add_measure(ph, photo_get_measure(ph), true);
      delay(2);
    }
  }

  for(int ph=0; ph<photo_count; ph++) {
    laser_off(ph);
  }

  delay(1000);

  for (int s=0; s<10; s++) {
    for(int ph=0; ph<photo_count; ph++) {
      photo_add_measure(ph, photo_get_measure(ph), false);
    }
  }

  for(int ph=0; ph<photo_count; ph++) {
    photo_on_prom[ph] = photo_on_sum[ph] / photo_on_sample_count;
    photo_off_prom[ph] = photo_off_sum[ph] / photo_off_sample_count;
  }
}


