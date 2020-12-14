#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int insertMintoN(int N, int M, uint8_t i, uint8_t j) {
    // TODO: Check j >= i and M not erroneous

    // 1. Clear bits j through i in N
    // 2. Insert M

    // M bits all set to 1 (rest 0)
    int MBits = ~(-1 << (j - i + 1));

    // Clear masks is all 1s with bits j-i set to 0
    int clearMask = ~(MBits << i);

    // Clear bits j-i in N
    int clearedN = N & clearMask;

    // Put M into position
    return clearedN | (M << i);

    // return (N & ~(~(-1 << (j - i + 1)) << i)) | (M << i); // Single line version
}

// Print n in [0,1] passed as double in binary format
void binaryToString(double n) {

    // Handle corner cases 0 and 1
    if (n == 0 | n == 1) {
        printf("%d", n);
    }

    printf("0.");

    double v = 1.0;

    int chars = 1;
    do {

        v /= 2;

        if (n - v >= 0) {
            n -= v;
            printf("1");
        } else {
            printf("0");
        }

        chars++;

        if (n == 0) break;

    } while (chars < 32);

}

// Find length of longest sequence of 1s made by possibly flipping one bit from 0 to 1
uint8_t flipBitToWin(int n) {

    if (n == -1) return 32; // If n is all 1s no need to flip anything!

    uint8_t longest = 0;
    uint8_t current = 0;
    uint8_t rightHalf = 0;
    for (uint8_t i = 0; i < 32; i++) {
        // Current bit is a 1
        if ((n >> i) & 1) {
            current++;
            rightHalf++;
            if (current > longest) {
                longest = current;
            }
        } else {
            current = rightHalf + 1;
            rightHalf = 0;
        }
    }

    return longest;
}

// Print next smallest and next largest number with same number of 1 bits in their representation
// Given n is a positive integer
void nextNumber(uint32_t n) {
    // Largest: 0001 -> 0010, 0011 -> 0101, 0111 -> 1011, 1111 -> NULL
    // 1 -> 2, 3 -> 5, 7 -> 11
    // +1 , + 2, + 4
    // + largest 2^i for ith bit which is largest 1 in movement group
    // i.e. Move smallest 1 a space to the left (if left space is a 1 move that instead (recursively))
    // Smallest: 0001 -> NULL, 0010 -> 0001, 0101 -> 0011, 1011 -> 0111
    // i.e. Move largest 1 a space to the right (if right space is a 1 move that instead (recursively))
    // 2 -> 1, 5 -> 3, 11 -> 7
    // -1, -2, -4

    // 1011 -> 1101 (11 -> 13) YES
    // 1011 -> 0111 (11 -> 7) NO

    if (n == 0) {
        printf("No 1s in number");
        return;
    }

    // Find largest position 1 in smallest 1's movement group
    uint8_t posL = 0;
    bool found = false;
    for (uint8_t i = 0; i < 32; i++) {
        if ((n >> i) & 1) {
            found = true;
        } else {
            if (found) {
                posL = i - 1;
                break;
            }
        }
    }

    printf("Next largest with same number of 1s is %i", n + (1 << posL));

    // Find smallest position 1 in largest 1's movement group
    uint8_t posR = 31;
    found = false;
    for (uint8_t i = 31; i >= 0; i--) {
        if ((n >> i) & 1) {
            found = true;
        } else {
            if (found) {
                posR = i + 1;
                break;
            }
        }
    }

    printf("\nNext smallest with same number of 1s is %i", n - (1 << (posR-1)));


    // Improvements:
    // Should've noticed we can reduce this to saying "flip the leftmost non-trailing zero and the bit to the right"
    // And vice versa
    // can reduce arithmetically

}

// ((n & (n - 1)) == 0)
// 0101 & 0100 == 0
// 0110 & 0101 == 0
// 1000 & 0111 == 0
// n & (n - 1) clears the rightmost bit
// n & (n - 1) == 0 Checks if n is a power of 2.

// Compute number of bits to flip to convert A to B
uint8_t numBitsToFlip(int A, int B) {

    int C = A ^ B; // If mismatch = 1

    uint8_t count = 0;
    while (C != 0) {
        C = C & (C - 1); // Clear next rightmost bit
        count++;
    }

    return count;

}

// Swap pairwise even and odd bits in the number
// Target: as few instructions as possible
int pairwiseSwap(int n) {
    // If n = 1101
    // nShiftL = 1010
    // nShiftR = 0110

    // 1001
    // 0010
    // 0100

    // Mask odds and shift, mask evens and shift, or together
    return ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
}

// Swap the values of two distinct numbers without a temporary variable
void XORSwap(int* a, int* b) {
    (*a) = (*a)^(*b); // Sets all mismatching bits to 1 : A = A xor B = C
    (*b) = (*a)^(*b); // Derives a : (A xor B) xor B = C xor B = A
    (*a) = (*b)^(*a); // Derives b : (new B) xor (A xor B) = A xor C = B
}

// Swap values of two numbers without temporary variable
void AddSwap(int* a, int* b) {
    if (a != b) {
        (*a) = (*a) + (*b); // a = a + b = c
        (*b) = (*a) - (*b); // c - b = a
        (*a) = (*a) - (*b); // c - a = b
    }
}

// // Draw horizontal line from x1 to x2 in monochrome screen buffer
// void drawLine(uint8_t* screen, int width, int height, int x1, int x2, int y) {

//     int i = y * width + x1;

//     for (int j = 0; j < x2 - x1; j++) {
//         screen[i + j] = 1;
//     }

// }

int main() {
    // printf("%i",insertMintoN(0,0b0110, 4, 7));
    // binaryToString(0.56123615);
    // printf("%i", flipBitToWin(1775));
    // nextNumber(13);
    printf("%i", numBitsToFlip(29, 15));
}