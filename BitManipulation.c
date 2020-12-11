#include <stdbool.h>
#include <stdint.h>

// Return the ith bit in num
bool getBit(int num, uint8_t i) {
    return num & (1 << i);
}

// Set the ith bit in num
int setBit(int num, uint8_t i) {
    return num | (1 << i);
}

// Clear ith bit in num
int clearBit(int num, uint8_t i) {
    return num & ~(1 << i); // Mask sets ith bit to zero, rest to ones by negation
}

int clearBitsMSBthroughI(int num, uint8_t i) {
    return num & ((1 << i) - 1); // 00100000 - 00000001 = 00011111 (hence clears MSB through i)
}

int clearBitsIthrough0(int num, uint8_t i) {
    return num & (-1 << (i + 1)); // -1 = 11111111 so shifting left 3x gives 11111000 (clears bit 2 through 0)
}

int updateBit(int num, uint8_t i, uint8_t v) {
    return (num & ~(1 << i)) | (v << i);
    // 00110111 & 11101111 = 00100111
    // 00100111 | 00010000 = 001100111
    // Clear the ith bit then set it to v
}

int main() {
    return 0;
}