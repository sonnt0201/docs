# API usage

## Abstraction

This page give basic instructions to communicate with the platform, 
mainly for users and external devices to create and read their data.

For details, we'll give instructions about:

- Ways to resister a user and create devices

- **How sensor devices, or other external embedded systems construct a data packet
frame to send to the gateway. Especially explain packet frame format.**

- GraphQL APIs to fetch the recorded data.

## Resister a user and create your own devices (updating, not available yet)

Just use our GUI, available when the platform is published.

## Sensor data - Packet frame format

These data frames will be created by your external devices/MCUs, then sent
using a supported wireless protocol to our gateway.

Actually, we'll develop our own *encoder library* to encode data into packet frame,
you can just call the function to encode, get the pointer to the returned data
packet, then send that packet to gateway.

If you want to encode data to packet frame by yourself, here is the packet frame
format:

| | 1 byte | 16 bytes | 8 bytes | 2 * n bytes | 1 byte | |
| - | - | - | - | - | - | -|
|start frame | packet's length | Device's ID | Timestamp (in millisec) | Array of values (2 byte for each value) | checksum | end frame

If present packet frame in `C struct`, the struct will looks like this:

```c
struct SensorDataFrame {
	uint8_t packet_len
	uint8_t device_id[16]
	uint64_t timestamp
	int16_t values[NUMBER_OF_VAL]
	int8_t checksum
}
```

Packet length is the total length of the packet frame including the 
length byte itself and checksum

With `NUMBER_OF_VAL` is defined as the number of values you want to send in a frame.

The system accepts packet frame with 1 sensor value at least,
and 100 sensor values at most.

This means the size of a packet, as well as the value of packet's length, can be from 28 bytes to 226 bytes.

## Fetch data from server with GraphQL API.

This is still being developed.

***

October 2024 by Thai-Son Nguyen.

 🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻




