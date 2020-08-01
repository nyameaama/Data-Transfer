#include"Process.h"

void P_MAIN::transmit(uint8_t data, void (*func)(char*)){
    CHECKSUM *instance = new CHECKSUM();
    MISC *util = new MISC();
    //CHECKSUM
    char* convertedData;
    util->itoa(data,convertedData,10);
    auto checksum = instance -> verhoeffChecksum(convertedData);
    delete instance;
    //MERGE TO PACKET
    auto merged = util -> PACKET_MERGE_2VALUES(data,checksum);
    delete util;
    //OUTPUT METHOD
    (*func)(merged);
    return;
}

char P_MAIN::get(char (*func)()){
    //PARSE PACKET
    MISC *util = new MISC();
    auto *elements = util -> PARSE_PACKET(func);
    delete util;
    //CHECKSUM FOREIGN DATA
    auto data = elements[0];
    char checkDigit[1];
    checkDigit[0] = elements[1];
    //VALIDATE CHECKSUMS
    CHECKSUM *instance = new CHECKSUM();
    auto validate = instance -> validate_verhoeff(checkDigit);
    delete instance;
    //RETURN 
    return (validate == 0) ? elements[0] : 0;
}