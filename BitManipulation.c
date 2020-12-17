#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void getBit(int n, uint8_t i) {
    printf("%d\n", (n >> i) & 1); // Okay. Avoids large immediate.
}

void setBit(int n, uint8_t i) {
    printf("%d\n", n | (1 << i));
}

void clearBit(int n, uint8_t i) {
    printf("%d\n", n & ~(1 << i));
}

// Clear MSB to i
void clearMSBtoi(int n, uint8_t i) {
    printf("%d\n", n & ((1 << i) - 1));
}

// Clear i to zero
void clearItoZero(int n, uint8_t i) {
    printf("%d\n", n & (-1 << (i + 1))); // This is okay, but technically undefined behaviour to left-shift negatives
    printf("%d\n", n & ~((1 << (i + 1)) - 1)); // This is better for that reason.
}

void updateBit(int n, uint8_t i, uint8_t v) {
    // Update bit i in n with value v
    // Need to clear i and then set with v
    printf("%d\n", (n & ~(1 << i)) | (v << i));
}

// insert n into m s.t. m starts at bit j and ends at bit i
void insert(int n, int m, uint8_t j, uint8_t i) {

    // Word of warning, +/- binds tighter than shifts so use brackets!

    // Clear bits j to i in n
    int clearMaskPart1 = ((1 << (j + 1)) - 1); // Set bits j to 0 to 1
    int clearMaskPart2 = ~((1 << i) - 1); // Set bits i - 1 to 0 to 0 and everything else 1
    int clearMask = ~(clearMaskPart1 & clearMaskPart2);

    // Clear bits j to i in n
    n &= clearMask;

    // Insert m into n
    n |= (m << i);

    printf("%x\n", n);
}

// print r as a 32-bit binary number, print ERROR if it can't be accurately represented
// r is in range [0, 1]
void printBinary(double r) {

    printf("0.");
    uint8_t count = 1;
    double div = 1;
    while (r != 0 && count < 32) {
        
        div /= 2;
        double rem = r - div;

        if (rem >= 0) {
            r = rem;
            printf("1");
        } else {
            printf("0");
        }

        count++;
    }
    printf("\n");

}

// Find length of longest sequence of 1s made by flipping a bit
void flipBit(int n) {

    uint8_t maxLen = 0;
    uint8_t counter = 0;
    uint8_t counterLeft = 0;
    for (uint8_t i = 0; i < 32; i++) {
        if ((n >> i) & 1) {
            if (++counter + counterLeft > maxLen) {
                maxLen = counter + counterLeft;
            }
        } else {
            counterLeft = counter + 1; // Remember to count flipped bit
            counter = 0;
        }
    }

    printf("%d\n", maxLen);

}

// Print next smallest and next largest number with same number of 1 bits
void nextNumber(int n) {

    // (next largest) 01110110 <-- 01101110 --> 01101101 (next smallest)

}

void isPower2(int n) {
    printf("%d\n", (n & (n - 1)) == 0);
}

// How many bits to flip to get same numbers
void bitsToFlip(int a, int b) {
    a = a ^ b; // Sets mismatching bits to 1 all else 0
    uint8_t count = 0;
    while (a != 0) {
        a &= a - 1; // Sets right-most 1 to 0
        count++;
    }
    printf("%d\n", count);
}

// Swap odd and even bits
void pairwiseSwap(int n) {
    n = ((n & 0xaaaaaaaa) >> 1) | (n & 0x55555555 << 1);
    printf("%d\n", n);
}

// Sum a and b without +/-
void sum(int a, int b) {

    // 0110 + 0101 = 1011
    // 0110 ^ 0101 = 0011
    // 0110 & 0101 = 0100

    while (b != 0) {

        int c = a & b;
        a = a ^ b;
        b = c << 1;

    }

    printf("%d\n", a);

}

// Use memorized counts (DP)
void count1sInRange(int max) {
    printf("[0");
    uint8_t* count = calloc(max + 1, sizeof(uint8_t));
    for (int i = 1; i <= max; i++) {
        count[i] = count[i & (i - 1)] + 1;
        printf(", %d", count[i]);
    }
    printf("]\n");
}

// Find only number missing in array from 0 to n
void missingNumber(int* data, int n) {

    int xor = 0, i = 0;
    for (i = 0; i < n; i++) {
        xor = xor ^ i ^ data[i];
    }
    printf("%d\n", xor ^ i); // Recover missing number

    int sum = n;
    for (int j = 0; j < n; j++) {
        sum += j - data[j];
    }
    printf("%d\n", sum); // Alternative method
}

void reverseBits(int n) {

    // Unrolled recursive swaps
    n = (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16;
    n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
    n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
    n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
    n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;

    printf("%d", n);

}

void XORSwap(int a, int b) {

    // Do this with pointers if returning.

    a = a ^ b; // c
    b = a ^ b; // (a ^ b) ^ b = a
    a = b ^ a; // a ^ (a ^ b) = b

}

void addSwap(int a, int b) {

    // Again, do it with pointers if need be.

    a = a + b;
    b = a - b; // (a + b) - b = a
    a = a - b; // (a + b) - a = b

}

int main() {

    getBit(0xf, 0);
    setBit(0xf0, 0);
    clearBit(0xffffffff, 31);
    clearMSBtoi(0xf0000000, 28);
    clearItoZero(0xf, 3);
    updateBit(0xf, 3, 0);
    insert(0xef, 0xa, 7, 4);
    printBinary(0.72);
    flipBit(1775);
    isPower2(16);
    bitsToFlip(29, 15);
    sum(-5, 10);
    count1sInRange(5);
    int input[] = {9,6,4,2,3,5,7,0,1};
    missingNumber(input, 9);
    reverseBits(43261596);

}

