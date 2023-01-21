#include <iostream>

class CLI
{
  private:
    double validateDouble();

  public:
    CLI();
    double askForDuration();
    double askForFrequency();
    void end();
};