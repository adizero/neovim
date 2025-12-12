#include <stdint.h>

// Define a macro for the endianness of the host system.
// x86/x64 systems are typically Little Endian (1).
// This is used for conditional compilation.
#define __BYTE_ORDER __LITTLE_ENDIAN
#define __LITTLE_ENDIAN 1
#define __BIG_ENDIAN 2


// The missing functions (le16toh and be16toh) convert 16-bit integers
// from a specific endianness (Little or Big) to the Host's endianness.

// If the host is Little Endian (__LITTLE_ENDIAN), le16toh is a no-op.
uint16_t le16toh(uint16_t x) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    return x;
#else
    // If we were on a Big Endian host, we would need to byte-swap.
    // This part is included for completeness, though unlikely to be hit on CentOS 7.
    return (x << 8) | (x >> 8);
#endif
}

// If the host is Little Endian, be16toh must perform a byte-swap.
uint16_t be16toh(uint16_t x) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    // Byte swap: (0xABCD becomes 0xCDAB)
    return (x << 8) | (x >> 8);
#else
    // If we were on a Big Endian host, it would be a no-op.
    return x;
#endif
}
