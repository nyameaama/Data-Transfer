#ifndef PROCESS_MAIN
#define PROCESS_MAIN

#include<stdint.h>
#include"../Checksum/checksum.h"
#include"../MISC/utility.h"

class P_MAIN {
    private:
        uint8_t createChecksum(uint8_t x);

    public:
        void transmit(uint8_t data, void (*func)(char*));

        char get(char (*func)());


};

#endif