#include <iostream>
#include "saveWaveInWav/saveWaveInWav.h"
#include "CLI/CLI.h"

using namespace std;

int main () {

  CLI cli;

  double duration = cli.askForDuration();
  double frequency = cli.askForFrequency();

  // the function that creates an audio wave file with pure sinusoidal sound.
  saveWaveInWav(duration, frequency);

  cli.end();
  return 0;
}
