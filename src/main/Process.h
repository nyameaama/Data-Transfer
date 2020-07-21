#ifndef PROCESS_MAIN
#define PROCESS_MAIN

#include<stdint.h>
#include"../checksum.h"

class P_MAIN {
    private:
        uint8_t createChecksum(uint8_t x);
        
    public:
        template<typename PACKET_TYPE>
        uint8_t send(PACKET_TYPE data, PACKET_TYPE (*method)(PACKET_TYPE));

        template<typename PACKET_TYPE>
        uint8_t receive(PACKET_TYPE (*method));



};

#endif