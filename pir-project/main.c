/*
    8/2024 by Thai-Son Nguyen
    Encoder and decoder for PIR Array project.
*/
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define FAILURE -1

int encodePIRVols(
    __uint8_t index,
    __uint16_t pir_vol0,
    __uint16_t pir_vol1,
    __uint16_t pir_vol2,
    __uint16_t pir_vol3,
    __uint16_t pir_vol4,
    __uint8_t *encodedData);

int decodePIRVols(
    __uint8_t *encodedData,
    __uint8_t len,
    __uint8_t *index,
    __uint16_t *pir_vol0,
    __uint16_t *pir_vol1,
    __uint16_t *pir_vol2,
    __uint16_t *pir_vol3,
    __uint16_t *pir_vol4

);

int main()
{
    __uint16_t encoded_vols[5] = {1203, 456, 789, 1150, 3500};

    __uint8_t *encodedData = (__uint8_t *)malloc(12);

    __uint8_t len = encodePIRVols(
        99,
        encoded_vols[0],
        encoded_vols[1],
        encoded_vols[2],
        encoded_vols[3],
        encoded_vols[4],
        encodedData);

    __uint16_t decoded_vols[5] = {0, 0, 0, 0, 0};
    __uint8_t decoded_index;
    int rc;
    if (
        (rc = decodePIRVols(
             encodedData,
             len,
             &decoded_index,
             decoded_vols,
             decoded_vols + 1,
             decoded_vols + 2,
             decoded_vols + 3,
             decoded_vols + 4)) == 0)
    {
        printf("index: %d\n Vols: %d %d %d %d %d \n", decoded_index, decoded_vols[0], decoded_vols[1], decoded_vols[2], decoded_vols[3], decoded_vols[4]);
    }
    else
    {
        printf("Error with rc %d, len: %d. Encoded data: \n", rc, len);
        for (int i = 0; i < len; i++)
            printf("%d ", encodedData[i]);
        printf("\n");
    }

    free(encodedData);
    encodedData = NULL;
};

int encodePIRVols(
    __uint8_t index,
    __uint16_t pir_vol0,
    __uint16_t pir_vol1,
    __uint16_t pir_vol2,
    __uint16_t pir_vol3,
    __uint16_t pir_vol4,
    __uint8_t *encodedData)
{

    int sum = 0;
    // index
    encodedData[0] = index;

    // vol0
    encodedData[1] = (__uint8_t)(pir_vol0 >> 8);
    encodedData[2] = (__uint8_t)(pir_vol0);

    // vol1
    encodedData[3] = (__uint8_t)(pir_vol1 >> 8);
    encodedData[4] = (__uint8_t)(pir_vol1);

    // vol2
    encodedData[5] = (__uint8_t)(pir_vol2 >> 8);
    encodedData[6] = (__uint8_t)(pir_vol2);

    // vol3
    encodedData[7] = (__uint8_t)(pir_vol3 >> 8);
    encodedData[8] = (__uint8_t)(pir_vol3);

    // vol4
    encodedData[9] = (__uint8_t)(pir_vol4 >> 8);
    encodedData[10] = (__uint8_t)(pir_vol4);

    for (int i = 0; i <= 10; i++)
        sum += encodedData[i];

    encodedData[11] = (__uint8_t)(sum);

    return 12;
};

int decodePIRVols(
    __uint8_t *encodedData, // in
    __uint8_t len,          // in
    __uint8_t *index,
    __uint16_t *pir_vol0,
    __uint16_t *pir_vol1,
    __uint16_t *pir_vol2,
    __uint16_t *pir_vol3,
    __uint16_t *pir_vol4

)
{
    // printf("Decoding ...\n");

    // check for invalid len
    if (len != 12)
    {
        printf("Decode Error: invalid packet length: %d\n", len);
        return -1;
    }
    int sum = 0;

    // check for invalid checksum
    for (int i = 0; i <= 10; i++)
    {
        sum += encodedData[i];
    }

    __uint8_t bytesum = (__uint8_t)sum;
    if (bytesum != ((__uint8_t)encodedData[11]))
    {
        printf("Decode Error: invalid checksum, received bytesum: %d\n", bytesum);

        return -1;
    }

    *index = (__uint8_t)encodedData[0];

    __uint16_t temp_pir_vol0 = ((encodedData[1] << 8) + encodedData[2]);
    __uint16_t temp_pir_vol1 = ((encodedData[3] << 8) + encodedData[4]);
    __uint16_t temp_pir_vol2 = ((encodedData[5] << 8) + encodedData[6]);
    __uint16_t temp_pir_vol3 = ((encodedData[7] << 8) + encodedData[8]);
    __uint16_t temp_pir_vol4 = ((encodedData[9] << 8) + encodedData[10]);

    *pir_vol0 = temp_pir_vol0;
    *pir_vol1 = temp_pir_vol1;
    *pir_vol2 = temp_pir_vol2;
    *pir_vol3 = temp_pir_vol3;
    *pir_vol4 = temp_pir_vol4;
    return 0;
};