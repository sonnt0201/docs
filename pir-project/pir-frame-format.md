# PIR voltages' frame format for sending ADC values via UART

## Abstraction

To remove the noise caused by Socket opening when reading ADC values of PIR circuit. When decided to use 2 ESP32s:

- One for reading ADC, encoding the data and sending via UART.
- The other as listener for UART packets, decode them and send to server using socket.

## PIR voltages' frame format

In each cycle we send 100 packets UART with time interval of 10ms. Each packet includes voltages of 5 PIRs.

The first packet goes with the begin timestamp of the cycle (has `0` as implicit index). The packets coming after go with their index (`1` -> `99`)

### Case 1: Packet with timestamp (16 bytes in total)

|        | timestamp | PIR0's voltage | PIR1's voltage | PIR2's voltage | PIR3's voltage | PIR4's voltage | checksum |         |
| ------ | --------- | -------------- | -------------- | -------------- | -------------- | -------------- | -------- | ------- |
| byte-0 | 5 bytes   | 2 bytes        | 2 bytes        | 2 bytes        | 2 bytes        | 2 bytes        | 1 byte   | byte-15 |

### Case 2: Packet without timestamp (12 bytes in total)

|        | packet index | PIR0's voltage | PIR1's voltage | PIR2's voltage | PIR3's voltage | PIR4's voltage | checksum |         |
| ------ | ------------ | -------------- | -------------- | -------------- | -------------- | -------------- | -------- | ------- |
| byte-0 | 1 byte       | 2 bytes        | 2 bytes        | 2 bytes        | 2 bytes        | 2 bytes        | 1 byte   | byte-11 |

## Encoder and decoder

We design 2 functions for encoding and decoding purposes in `C lang`.

**Encoder:** (for UART sender)

```c
// Return the length of encoded data. Return -1 if input is invalid
int encodePIRVols(
    [in] (uint_8) index, // index of packet in cycle (from 0 to 99)
    [in] (int) timestamp, // timestamp in seconds
    [in] (int) pir_vol0,
    [in] (int) pir_vol1,
    [in] (int) pir_vol2,
    [in] (int) pir_vol3,
    [in] (int) pir_vol4,
    [out] (uint8_t*) encodedData, // pointer to output encoded data
)

```

**Decoder:** (for UART receiver)

```c
// Return 0 if decode successfully, -1 otherwise
int decodePIRVols(
    [in] (uint8_t*) encodedData, // pointer to received packet
    [in] (uint8_t) len, // length of received packet
    [out] (uint8_t*) index,
    [out] (uint8_t*) timestamp, // pointer to timestamp
    [out] (int*) pir_vol0, // poiter to store the value
    [out] (int*) pir_vol1,
    [out] (int*) pir_vol2,
    [out] (int*) pir_vol3,
    [out] (int*) pir_vol4,
)

```

## Encoded PIR's voltage value

PIR's voltage value (also the ADC value) include 4 digits in decimal. We decode it to 2 bytes, the first byte storing 2 former digits, the second byte storing 2 latter digits

Eg: Voltage = 1234

| Byte index | byte 0 | byte 1 |
| - | - | - |
| Demical value | 12 | 34 |