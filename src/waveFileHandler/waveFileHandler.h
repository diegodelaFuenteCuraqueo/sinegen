#include <iostream>

class WaveFileHandler
{
private:
    int sampleRate;
    double duration;
    int totalSamples;
    int numChannels;
    std::string fileName;

public:
  WaveFileHandler(int sr, double dur);
  // ~WaveFileHandler();
  void writeWaveFileHeader();
  void writeSinewave(double frequency);
};