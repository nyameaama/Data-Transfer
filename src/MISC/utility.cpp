#include"utility.h"

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
char* MISC::itoa(int value, char* result, int base) {
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
    //Separate strings with '00'
    //Buffers
    char separateVal[16] = "00";
    char buf1[16];
    char buf2[16];
    //Change buffer ints to char
    itoa(x,buf1,10);
    itoa(y,buf2,10);
    //Merge buffer 1 with separate value
    auto final = strcat(buf1,separateVal);
    //Merge result with buffer 2 to make (buf1 + sep + buf2)
    final = strcat(final,buf2);
    return final;
}

template<typename TYPE_DEF>
TYPE_DEF MISC::COMPARE_CHECKSUMS(TYPE_DEF CHECKSUM_A,TYPE_DEF CHECKSUM_B){

}

char *MISC::PARSE_PACKET(char (*func)()){
    /*char parsed[16];
    uint8_t buf1index,buf2index;
    auto funcResult = (func);
    for(size_t i : funcResult){
        if(funcResult[i] == '0'){
            if(funcResult[i + 1] == '0'){
                buf1index = i;
                buf2index = i + 1;
            }
        }
    }
    uint8_t temp;
    while(temp < buf1index){
        parsed[0] = strcat(parsed[0],funcResult[temp]);
        temp++;
    }
    temp = 0;
    while(temp > buf2index){
        parsed[1] = strcat(parsed[1],funcResult[temp]);
        temp++;
    }
    return parsed;*/
}