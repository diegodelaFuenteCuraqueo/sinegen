#include <iostream>
#include <fstream>
#include <cmath>
#include "WaveFileHandler.h"

using namespace std;

//typedef struct WAV_HEADER {
//  /* RIFF Chunk Descriptor */
//  uint8_t RIFF[4] = {'R', 'I', 'F', 'F'}; // RIFF Header Magic header
//  uint32_t ChunkSize = 16;                     // RIFF Chunk Size
//  uint8_t WAVE[4] = {'W', 'A', 'V', 'E'}; // WAVE Header
//  uint8_t fmt[4] = {'f', 'm', 't', ' '}; // FMT header
//  uint32_t Subchunk1Size = 16;           // Size of the fmt chunk
//  uint16_t AudioFormat = 1; // Audio format 1=PCM
//  uint16_t NumOfChan = 1;   // Number of channels 1=Mono 2=Sterio
//  uint32_t SamplesPerSec = 16000;   // Sampling Frequency in Hz
//  uint32_t bytesPerSec = 16000 * 2; // bytes per second
//  uint16_t blockAlign = 2;          // 2=16-bit mono, 4=16-bit stereo
//  uint16_t bitsPerSample = 24;      // Number of bits per sample
//  uint8_t Subchunk2ID[4] = {'d', 'a', 't', 'a'}; // "data"  string
//  uint32_t Subchunk2Size;                        // Sampled data length
//} wav_hdr;

WaveFileHandler::WaveFileHandler (int sr, double dur) {
  sampleRate = sr;
  duration = dur;
  totalSamples = duration * sampleRate;
  numChannels = 1;
  fileName = "sine_wave";
}

void WaveFileHandler::writeWaveFileHeader() {
  cout << " ~ Wave File : creating... ~" << endl;
  // Open a binary file for writing
  ofstream outFile(fileName + ".wav", ios::binary);
  //wav_hdr wavHeader;

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
  cout << " ~ Wave File : writingSinewave... ~" << endl;
  // Opens a binary file for writing
  ofstream outFile(fileName + ".wav", ios::binary | ios::app);

  // Write the sine wave samples
  for (int i = 0; i < totalSamples; i++) {
    double sample = sin(2 * M_PI * frequency * i / sampleRate);
    int amplitude = (int)(sample * 8388607);
    outFile.write((char*)&amplitude, 3);
  }

  // Close the file
  cout << " ~ Wave File : closing file ~" << endl;
  outFile.close();
}
