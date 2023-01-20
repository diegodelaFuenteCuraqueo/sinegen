#include <iostream>
#include "saveWaveInWav.h"

using namespace std;

int main () {
  double duration = 5.0; // 5 seconds
  double frequency = 440.0; // 440 Hz
  saveWaveInWav(duration, frequency);
  cout << "Sine wave file created!" << endl;
  return 0;
}
