#ifndef PROCESS_MAIN
#define PROCESS_MAIN

#include<stdint.h>
#include"../Checksum/checksum.h"
#include"../MISC/utility.h"

class P_MAIN {
    private:
        uint8_t createChecksum(uint8_t x);

    public:
        template<typename PACKET_TYPE>
        uint32_t send(PACKET_TYPE data, PACKET_TYPE (*method)(char*));

        template<typename PACKET_TYPE>
        PACKET_TYPE receive(char* (*method)());



};

#endif