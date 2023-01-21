echo "building app"
g++ src/main.cpp src/saveWaveInWav/saveWaveInWav.cpp src/waveFileHandler/waveFileHandler.cpp src/CLI/CLI.cpp -o bin/sinegen && echo "Binary Build complete!"
echo "DONE"

