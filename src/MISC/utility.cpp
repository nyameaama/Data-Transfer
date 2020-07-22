#include"utility.h"

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

/* Custom Functions
    Nyameaama Gambrah
*/

char *MISC::PACKET_MERGE_2VALUES(unsigned int x,unsigned int y){
    //Separate strings with '_'
    char buf1[16];
    char buf2[16];
    itoa(x,buf1,10);
    itoa(y,buf2,10);
    auto final = strcat(buf1,buf2);
    return final;
}

template<typename TYPE_DEF>
TYPE_DEF MISC::COMPARE_CHECKSUMS(TYPE_DEF CHECKSUM_A,TYPE_DEF CHECKSUM_B){

}

template<typename TYPE_DEF>
TYPE_DEF *MISC::PARSE_PACKET(TYPE_DEF(*method)()){

}