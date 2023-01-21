#include <iostream>
#include "saveWaveInWav/saveWaveInWav.h"

using namespace std;

int main () {
  double duration = 5.0; // 5 seconds
  double frequency = 440.0; // 440 Hz

  cout << "Enter duration (seconds): <5seconds by default>" << endl;
  cin >> duration;
  cout << "Enter frequency (Hz): <440hz by default>" << endl;
  cin >> frequency;

  saveWaveInWav(duration, frequency);

  cout << "Sine wave file created!" << endl;
  return 0;
}
