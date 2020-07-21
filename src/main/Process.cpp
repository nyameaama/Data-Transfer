#include"Process.h"

template<typename PACKET_TYPE>
uint32_t P_MAIN::send(PACKET_TYPE data, PACKET_TYPE (*method)(char*)){
    //CHECKSUM
    CHECKSUM *instance = new CHECKSUM();
    auto checksum = instance -> verhoeffChecksum(data);
    delete instance;
    //MERGE TO PACKET
    MISC *util = new MISC();
    auto merged = util -> PACKET_MERGE_2VALUES(data,checksum);
    delete util;
    //OUTPUT METHOD
    (*method)(merged);
    return;
}

template<typename PACKET_TYPE>
PACKET_TYPE P_MAIN::receive(char* (*method)){
    //PARSE PACKET
    MISC *util = new MISC();
    auto *elements = util -> PARSE_PACKET((*method));
    delete util;
    //CHECKSUM FOREIGN DATA
    auto data = elements[0];
    //VALIDATE CHECKSUMS
    CHECKSUM *instance = new CHECKSUM();
    auto validate = instance -> validate_verhoeff(elements[1]);
    delete instance;
    //RETURN 
    return (validate == 0) ? elements[0] : 0;
}
