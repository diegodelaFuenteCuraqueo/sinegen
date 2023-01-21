#include <iostream>
#include <fstream>
#include <cmath>
#include "waveFileHandler.h"

using namespace std;

WaveFileHandler::WaveFileHandler (int sr, double dur) {
  cout << "WaveFileHandler constructor called" << endl;
  sampleRate = sr;
  duration = dur;
  totalSamples = duration * sampleRate;
  numChannels = 1;
  fileName = "sine_wave";
}

void WaveFileHandler::writeWaveFileHeader() {
  cout << "WaveFileHandler::writeWaveFileHeader called" << endl;
  // Open a binary file for writing
  ofstream outFile(fileName + ".wav", ios::binary);

  // Write the wave file header
  outFile.write("RIFF", 4);
  int fileSize = 36 + totalSamples * 3;
  outFile.write((char*)&fileSize, 4);
  outFile.write("WAVE", 4);

  // Write the format chunk
  outFile.write("fmt ", 4);
  int formatChunkSize = 16;
  outFile.write((char*)&formatChunkSize, 4);
  short audioFormat = 1;
  outFile.write((char*)&audioFormat, 2);
  short numChannels = 1;
  outFile.write((char*)&numChannels, 2);
  outFile.write((char*)&sampleRate, 4);
  int byteRate = sampleRate * numChannels * 3;
  outFile.write((char*)&byteRate, 4);
  short blockAlign = numChannels * 3;
  outFile.write((char*)&blockAlign, 2);
  short bitsPerSample = 24;
  outFile.write((char*)&bitsPerSample, 2);

  // Write the data chunk
  outFile.write("data", 4);
  int dataChunkSize = totalSamples * 3;
  outFile.write((char*)&dataChunkSize, 4);
}

void WaveFileHandler::writeSinewave(double frequency) {
  cout << "WaveFileHandler::writeSinewave called" << endl;
  // Opens a binary file for writing
  ofstream outFile(fileName + ".wav", ios::binary | ios::app);

  // Write the sine wave samples
  for (int i = 0; i < totalSamples; i++) {
    double sample = sin(2 * M_PI * frequency * i / sampleRate);
    int amplitude = (int)(sample * 8388607);
    outFile.write((char*)&amplitude, 3);
  }

  // Close the file
  outFile.close();
}
