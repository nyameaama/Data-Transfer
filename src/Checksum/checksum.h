#ifndef CHECK_SUM
#define CHECK_SUM

#include<stdint.h>
#include<stddef.h>
#include<string.h>

class CHECKSUM {
    private:
        //For a given number generates a Verhoeff digit
        int generate_verhoeff(const char* num);
    public:
        //Implementation of CRC32
        uint32_t crc32c_checksum( char data);

        //Validates that an entered number is Verhoeff compliant.
        //The check digit must be the last one.
        int validate_verhoeff(char* num);

        //Verhoeff Driver
        int verhoeffChecksum(const char* num);

};


#endif