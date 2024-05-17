#include "can_utils.h"
#include <cstring>
#include <iostream>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>

int CANUtils::setupCANSocket(const std::string &interface) {
    int socket_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socket_fd < 0) {
        perror("Error while opening socket");
        return -1;
    }

    struct ifreq ifr;
    std::strcpy(ifr.ifr_name, interface.c_str());
    ioctl(socket_fd, SIOCGIFINDEX, &ifr);

    struct sockaddr_can addr;
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error in socket bind");
        return -2;
    }

    return socket_fd;
}

void CANUtils::sendCANMessage(int socket, struct can_frame &frame) {
    int bytes_sent = write(socket, &frame, sizeof(struct can_frame));
    if (bytes_sent != sizeof(struct can_frame)) {
        perror("Error sending CAN message");
    }
}

struct can_frame CANUtils::receiveCANMessage(int socket) {
    struct can_frame frame;
    int bytes_read = read(socket, &frame, sizeof(struct can_frame));
    if (bytes_read < 0) {
        perror("Error reading CAN message");
    }
    return frame;
}

void CANUtils::printCANMessage(const struct can_frame &frame) {
    std::cout << "CAN ID: " << std::hex << frame.can_id << " DLC: " << std::dec << (int)frame.can_dlc << " Data: ";
    for (int i = 0; i < frame.can_dlc; i++) {
        std::cout << std::hex << (int)frame.data[i] << " ";
    }
    std::cout << std::dec << std::endl;
}
