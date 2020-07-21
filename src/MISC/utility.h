#ifndef UTILIY
#define UTILIY

#include<stdint.h>

class MISC {
    public:
        template<typename TYPE_DEF>
        TYPE_DEF PACKET_MERGE_2VALUES(TYPE_DEF x,TYPE_DEF y);

        template<typename TYPE_DEF>
        TYPE_DEF COMPARE_CHECKSUMS(TYPE_DEF CHECKSUM_A,TYPE_DEF CHECKSUM_B);


};

#endif