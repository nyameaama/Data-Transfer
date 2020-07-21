#include"Process.h"

template<typename PACKET_TYPE>
uint8_t P_MAIN::send(PACKET_TYPE data, PACKET_TYPE (*method)(PACKET_TYPE)){
    //CHECKSUM
    CHECKSUM *instance = new CHECKSUM();
    auto checksum = instance -> crc32c_checksum(data);
    delete instance;
    //MERGE TO PACKET
    MISC *util = new MISC();
    auto merged = util -> PACKET_MERGE_2VALUES(data,checksum);
    delete util;
    //OUTPUT METHOD
    (*method)(merged);
}

template<typename PACKET_TYPE>
uint8_t P_MAIN::receive(PACKET_TYPE (*method)){
    //PARSE PACKET
    MISC *util = new MISC();
    auto *elements = util -> PARSE_PACKET((*method));
    delete util;
    //CHECKSUM FOREIGN DATA

    //COMPARE CHECKSUMS

    //RETURN 

}
