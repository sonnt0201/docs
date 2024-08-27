#include <stdio.h>

int encodePIRVols(
    __uint8_t index,
    int timestamp,
    int pir_vol0,
    int pir_vol1,
    int pir_vol2,
    int pir_vol3,
    int pir_vol4,
    __uint8_t *encodedData
);

int decodePIRVols(
    __uint8_t *encodedData,
    __uint8_t len,
    __uint8_t *index,
    int *timestamp,
    int *pir_vol0,
    int *pir_vol1,
    int *pir_vol2,
    int *pir_vol3,
    int *pir_vol4

);

int main()
{
   
}


int encodePIRVols(
    __uint8_t index,
    int timestamp,
    int pir_vol0,
    int pir_vol1,
    int pir_vol2,
    int pir_vol3,
    int pir_vol4,
    __uint8_t *encodedData
);
