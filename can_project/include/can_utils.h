#ifndef CAN_UTILS_H
#define CAN_UTILS_H

#include <linux/can.h>
#include <linux/can/raw.h>
#include <string>

class CANUtils {
public:
    static int setupCANSocket(const std::string &interface);
    static void sendCANMessage(int socket, struct can_frame &frame);
    static struct can_frame receiveCANMessage(int socket);
    static void printCANMessage(const struct can_frame &frame);
};

#endif // CAN_UTILS_H
