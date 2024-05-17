# ParsingCANMessages

# Prerequisites
A Linux machine with CAN interface support.
can-utils package installed (sudo apt install can-utils).
Basic understanding of C++ programming.

# Configure the CAN interface:
sudo ip link set can0 up type can bitrate 500000
sudo ip link set up can0

# Bring the CAN interface down (when done testing):
sudo ip link set down can0

# Building and running the project
cd can_project

# Create a build directory and navigate to it
mkdir build && cd build

# Run CMake to generate the Makefile
cmake ..

# Build the project
make

# Run the executable
sudo ./can_project
