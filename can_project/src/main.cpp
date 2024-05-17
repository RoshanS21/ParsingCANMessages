#include "can_utils.h"
#include <iostream>
#include <unistd.h>

int main() {
    std::string interface = "can0";

    int can_socket = CANUtils::setupCANSocket(interface);
    if (can_socket < 0) {
        std::cerr << "Failed to setup CAN socket" << std::endl;
        return 1;
    }

    struct can_frame send_frame;
    send_frame.can_id = 0x123;
    send_frame.can_dlc = 8;
    for (int i = 0; i < send_frame.can_dlc; i++) {
        send_frame.data[i] = i;
    }

    CANUtils::sendCANMessage(can_socket, send_frame);

    struct can_frame recv_frame = CANUtils::receiveCANMessage(can_socket);
    CANUtils::printCANMessage(recv_frame);

    close(can_socket);
    return 0;
}
