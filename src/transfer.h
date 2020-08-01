#ifndef TRANSFER_
#define TRANSFER_

#include"main/Process.h"
#include<stdint.h>

class Transfer {
    public:
        void shiftX(uint8_t data,void (*func)(char*)){P_MAIN sX; return sX.transmit(data,(func));}

        char collectX(char (*func)()){P_MAIN cX;return cX.get((func));}

};


#endif