#include <iostream>
#include <fstream>
#include <cmath>
#include "../WaveFileHandler/WaveFileHandler.h"

using namespace std;

void saveWaveInWav(double duration, double frequency) {
    WaveFileHandler waveFileHandler(48000, duration);
    waveFileHandler.writeWaveFileHeader();
    waveFileHandler.writeSinewave(frequency);
}

