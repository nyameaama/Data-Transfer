#ifndef CHECK_SUM
#define CHECK_SUM

#include<stdint.h>
#include<stddef.h>
#include<string.h>

class CHECKSUM {
    private:
        int generate_verhoeff(const char* num);
    public:
        uint32_t crc32c_checksum( char data);

        int validate_verhoeff(const char* num);

        int verhoeffChecksum(const char* num);

};


#endif