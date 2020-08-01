#ifndef UTILIY
#define UTILIY

#include<stdint.h>
#include<string.h>

class MISC {
    public:
        char* itoa(int value, char* result, int base); 

        char* PACKET_MERGE_2VALUES(unsigned int x,unsigned int y);

        template<typename TYPE_DEF>
        TYPE_DEF COMPARE_CHECKSUMS(TYPE_DEF CHECKSUM_A,TYPE_DEF CHECKSUM_B);

        char *PARSE_PACKET(char (*func)());

};

#endif