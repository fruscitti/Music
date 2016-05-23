byte lasers[] = {5,4,3,2};
bool laser_status[] = {false, false, false, false};

#define laser_count (sizeof(lasers)/sizeof(lasers[0]))

byte photos[] = {A0, A1, A2, A3};
#define photo_count (sizeof(photos)/sizeof(photos[0]))

#define SAMPLES 10

int photo_on_samples [photo_count][SAMPLE_SIZE];
int photo_off_samples[photo_count][SAMPLE_SIZE];
int photo_on_index = 0;
int photo_on_sum[photo_count];
int photo_on_prom[photo_count];
int photo_off_index = 0;
int photo_off_sum[photo_count];
int photo_off_prom[photo_count];
int photo_on_samples = 0;
int photo_off_samples = 0;

void photo_add_measure(int ph, int measure, bool laser_status) {
  if (laser_status) {
    photo_on_sum[ph] -= photo_on_samples[ph][photo_on_index];
    photo_on_samples[ph][photo_on_index] = measure;
    photo_on_sum[ph] += measure;
    if(++photo_on_index > SAMPLES) photo_on_index = 0;
    if(photo_on_samples < SAMPLES) photo_on_samples++;
  } else {
    photo_off_sum[ph] -= photo_off_samples[ph][photo_off_index];
    photo_off_samples[ph][photo_off_index] = measure;
    photo_off_sum[ph] += measure;
    if(++photo_off_index > SAMPLES) photo_off_index = 0;
    if(photo_off_samples < SAMPLES) photo_off_samples++;
  }  
}

void photo_setup() {
  for(int ph=0; ph < photo_count; ph++) {
    for(int s=0; s < SAMPLES; s++) {
      photo_on_samples[ph][s] = 0;
      photo_off_samples[ph][s] = 0;
    }
    photo_on_sum[ph] = 0;
    photo_on_prom[ph] = 0
    photo_off_sum[ph] = 0
    photo_off_prom[ph] = 0
  }
  
  photo_on_index = 0;
  photo_off_index = 0;
  photo_on_samples = 0;
  photo_off_samples = 0;
}

void laser_adjust() {

  // Inicializo
  for(int ph=0; jj<photo_count; jj++) {
    for(int s=0; ii<SAMPLES; ii++) {
      photo_on_stats[ph][s] = 0;
      photo_off_stats[ph][s] = 0;
    }
    total[jj] = 0;
    promedio[jj] = 0;
  }
  sampleIndex = 0;

  
  // Promedio de SAMPLES mediciones todas las fotoresitores con el laser prendido y apagado
  for (int ii=0; ii<40; ii++) {
    for(int jj=0; jj<3; jj++) {
      total[jj] -= samples[jj][sampleIndex];
      samples[jj][sampleIndex] = analogRead(aPins[jj]);
      total[jj] += samples[jj][sampleIndex];
      sampleIndex++;
      if (sampleIndex >= SAMPLES)
        sampleIndex = 0;
    }
    if (ii%5)
      fled_blink(1, 50);
  }

  for(int jj=0; jj<3; jj++) {
    promedio[jj] = total[jj] / SAMPLES;
  }

  fled_blink(1, 500);
}

// Lee n veces los valores y los promedia
//
void faccel_read(int n, int * results) {
  long totals[3] = {0L, 0L, 0L};

  for(int ii=0; ii<n; ii++) {
    for(int jj=0; jj<3; jj++) 
      totals[jj] += analogRead(aPins[jj]);
    delay(1);
  }

  for(int jj=0; jj<3; jj++) {
    results[jj] = (int)(totals[jj] / (long)n);
  }
}


