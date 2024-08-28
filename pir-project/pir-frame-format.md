# PIR voltages' frame format for sending ADC values via UART

## Abstraction

To remove the noise caused by Socket opening when reading ADC values of PIR circuit. We decided to use 2 ESP32s:

- One for reading ADC, encoding the data and sending via UART.
- The other as listener for UART packets, decode them and send to server using socket.

## PIR voltages' frame format

In each cycle we send 100 packets UART with time interval of 10ms. Each packet includes voltages of 5 PIRs. Packet index goes from 0 to 99.


**Size: 12 bytes in total**

|        | packet index | PIR0 voltage | PIR1 voltage | PIR2 voltage | PIR3 voltage | PIR4 voltage | checksum |         |
| ------ | ------------ | -------------- | -------------- | -------------- | -------------- | -------------- | -------- | ------- |
| byte-0 | 1 byte       | 2 bytes        | 2 bytes        | 2 bytes        | 2 bytes        | 2 bytes        | 1 byte   | byte-11 |

## Encoder and decoder

We design 2 functions for encoding and decoding purposes in `C lang`.

**Encoder:** (for UART sender)

```c
// Return the length of encoded data. Return -1 if input is invalid
int encodePIRVols(
    [in] (uint8_t) index, // index of packet in cycle (from 0 to 99)
    [in] (uint16_t) pir_vol0,
    [in] (uint16_t) pir_vol1,
    [in] (uint16_t) pir_vol2,
    [in] (uint16_t) pir_vol3,
    [in] (uint16_t) pir_vol4,
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
    [out] (uint16_t*) pir_vol0, // poiter to store the decoded value
    [out] (uint16_t*) pir_vol1,
    [out] (uint16_t*) pir_vol2,
    [out] (uint16_t*) pir_vol3,
    [out] (uint16_t*) pir_vol4,
)

```

## Encoded PIR's voltage value

We use 2 bytes to store each voltage value. 

Eg: Voltage = 1234 => 0x2322

| Byte index | byte 0 | byte 1 |
| - | - | - |
| Demical value | 0x23 | 0x22 |