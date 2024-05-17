# ParsingCANMessages

# Configure the CAN interface:
sudo ip link set can0 up type can bitrate 500000
sudo ip link set up can0

# Bring the CAN interface down (when done testing):
sudo ip link set down can0