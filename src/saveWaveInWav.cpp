#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void saveWaveInWav(double duration, double frequency) {
    // Set sample rate and calculate number of samples
    int sampleRate = 44100;
    int numSamples = duration * sampleRate;

    // Open a binary file for writing
    ofstream outFile("sine_wave.wav", ios::binary);

    // Write the wave file header
    outFile.write("RIFF", 4);
    int fileSize = 36 + numSamples * 2;
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
    int byteRate = sampleRate * numChannels * 2;
    outFile.write((char*)&byteRate, 4);
    short blockAlign = numChannels * 2;
    outFile.write((char*)&blockAlign, 2);
    short bitsPerSample = 16;
    outFile.write((char*)&bitsPerSample, 2);

    // Write the data chunk
    outFile.write("data", 4);
    int dataChunkSize = numSamples * 2;
    outFile.write((char*)&dataChunkSize, 4);

    // Write the sine wave samples
    for (int i = 0; i < numSamples; i++) {
        double sample = sin(2 * M_PI * frequency * i / sampleRate);
        short amplitude = (short)(sample * 32767);
        outFile.write((char*)&amplitude, 2);
    }

    // Close the file
    outFile.close();
}

