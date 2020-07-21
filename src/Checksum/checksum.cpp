#include"checksum.h"

// The multiplication table
int verhoeff_d[][]  = {
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
  {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
  {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
  {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
  {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
  {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
  {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
  {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
  {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
  {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
};

// The permutation table
int verhoeff_p[][]= {
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
  {1, 5, 7, 6, 2, 8, 3, 0, 9, 4},
  {5, 8, 0, 3, 7, 9, 6, 1, 4, 2},
  {8, 9, 1, 6, 0, 4, 3, 5, 2, 7},
  {9, 4, 5, 3, 1, 2, 6, 8, 7, 0},
  {4, 2, 8, 6, 5, 7, 3, 9, 0, 1},
  {2, 7, 9, 3, 8, 0, 6, 4, 1, 5},
  {7, 0, 4, 6, 9, 1, 3, 2, 5, 8}
};

//The inverse table
static int verhoeff_inv[] = {0, 4, 3, 2, 1, 5, 6, 7, 8, 9};

//For a given number generates a Verhoeff digit
int CHECKSUM::generate_verhoeff(const char* num){
  int c;
  int len;
  c = 0;
  len = strlen(num);

  for(int i = 0; i < len; i++)
    c = verhoeff_d[c][verhoeff_p[((i + 1) % 8)][num[len - i - 1] - '0']];

  return verhoeff_inv[c];
}

//Validates that an entered number is Verhoeff compliant.
//The check digit must be the last one.
int CHECKSUM::validate_verhoeff(char* num){
  int c;
  int len;
  c = 0;
  len = strlen(num);

  for (int i = 0; i < len; i++)
    c = verhoeff_d[c][verhoeff_p[(i % 8)][num[len - i - 1] - '0']];

  return (c == 0);
}

int CHECKSUM::verhoeffChecksum(const char* num){
   return generate_verhoeff(num);
}

uint32_t CHECKSUM::crc32c_checksum(char data){
    const char *message;// = data.c_str();
    int i, j;
    unsigned int byte, crc, mask;
    static unsigned int table[256];

    /* Set up the table, if necessary. */

    if (table[1] == 0) {
        for (byte = 0; byte <= 255; byte++) {
            crc = byte;
            for (j = 7; j >= 0; j--) {    // Do eight times.
                mask = -(crc & 1);
                crc = (crc >> 1) ^ (0xEDB88320 & mask);
            }
            table[byte] = crc;
        }
   }

   /* Through with table setup, now calculate the CRC. */

   i = 0;
   crc = 0xFFFFFFFF;
   while ((byte = message[i]) != 0) {
      crc = (crc >> 8) ^ table[(crc ^ byte) & 0xFF];
      i = i + 1;
   }
   return ~crc;

}