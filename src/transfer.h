#ifndef TRANSFER_
#define TRANSFER_

#include"main/Process.h"
#include<stdint.h>

class Transfer {
    public:
        template<typename PACKET_TYPE>
        uint8_t shift(PACKET_TYPE data, PACKET_TYPE (*method)(PACKET_TYPE));

        template<typename PACKET_TYPE>
        uint8_t collect(PACKET_TYPE (*method));

};


#endif