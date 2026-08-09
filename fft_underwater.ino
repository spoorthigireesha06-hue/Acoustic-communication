#include <arduinoFFT.h>

#define SIGNAL_PIN A1

// ─── Configuration ───────────────────────────
#define SAMPLES        128     // Must be power of 2
#define SAMPLING_FREQ  10000    // Hz — must be > 2x your max freq
                                // Your max is 6kHz so 15kHz safe margin

//#define FREQ_0         2000     // Hz — represents binary 0
#define FREQ_1         4000     // Hz — represents binary 1
#define TOLERANCE      500      // ±400Hz window around each frequency

// ─── FFT Setup ───────────────────────────────
double vReal[SAMPLES];
double vImag[SAMPLES];

arduinoFFT FFT  = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);

// ─── Setup ───────────────────────────────────
void setup() {
  Serial.begin(115200);
  Serial.println("FFT Receiver Ready");
  Serial.println("Listening for 3kHz (0) and 6kHz (1)...");

}

// ─── Main Loop ───────────────────────────────
void loop() {


  // Step 1 — Sample signal from piezo RX
  unsigned long samplingPeriod = 1000000UL / SAMPLING_FREQ;

  for (int i = 0; i < SAMPLES; i++) {
    unsigned long t = micros();
    vReal[i] = analogRead(SIGNAL_PIN);
    vImag[i] = 0;
    while (micros() - t < samplingPeriod);
  }

  // Step 2 — Run FFT
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(FFT_FORWARD);
  FFT.ComplexToMagnitude();


  // Step 3 — Find dominant frequency
  double peakFreq = FFT.MajorPeak();

  // Step 4 — Classify frequency
  String result = classifyFrequency(peakFreq);
  Serial.println(peakFreq);
  delay(500);

  // Step 5 — Output results
 // Serial.print("Peak Frequency: ");
  //Serial.print(peakFreq, 1);
 

  // Step 6 — Plot spectrum on serial plotter
  // Uncomment below to visualize full spectrum
  // plotSpectrum();
  
}

// ─── Frequency Classifier ────────────────────
String classifyFrequency(double freq){

  
  //if (freq >= (FREQ_0 - TOLERANCE) && freq <= (FREQ_0 + TOLERANCE)) {
   // delay(2000);
    //return "BIT = 0  (2kHz detected)";}//
   if (freq >= (FREQ_1 - TOLERANCE) && freq <= (FREQ_1 + TOLERANCE)) {
    delay(2000);
  
    return "BIT = 1  (4kHz detected)";
    
  }
  else {
    delay(100);
   return "UNKNOWN  (noise or no signal)";
  }
}

// ─── Optional Spectrum Plotter ───────────────
void plotSpectrum() {
  // Plots FFT magnitude spectrum on serial plotter
  // Each value = magnitude at that frequency bin
  // Frequency of bin i = i * (SAMPLING_FREQ / SAMPLES)
  // Bin resolution = 15000 / 128 = 117 Hz per bin

  for (int i = 2; i < (SAMPLES / 2); i++) {
    Serial.println(vReal[i]);
  }
}



