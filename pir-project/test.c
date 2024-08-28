#include <stdio.h>
#include <stdlib.h>

int main()
{
    __uint8_t first = 0x4F;
    __uint8_t second = 0x80;

    __uint16_t val = (first << 8) + second;
    printf("val: %x\n", val);
}