#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Things to think about from Arm

// Unsigned 8-bit integer
// Minimum: 0
// Maximum: 2^8 - 1 = 255

// 2C 8-bit integer
// Minimum: -2^7 = -128
// Maximum: 2^7 - 1 = 127

// Unsigned 32-bit integer
// Minimum: 0
// Maximum: 2^32-1

// 2C 32-bit integer
// Minimum: -2^31
// Maximum: 2^31 - 1

void luiProblem(int n) {

    // Occurs depending on method of getting bit
    // e.g. get the 26th bit (0-indexed)
    int a = (n >> 26) & 1;
    int b = (n & 0x4000000) >> 26; // This is a problem.
    // The 32-bit mask 0x4000000 will be larger than the space for immediates in the instruction format
    // hence will end up using multiple machine instructions loading the upper immediate, shifting, then lower and doing the mask

    // In assembly, if we wanted to preserve the lower bits when using LUI, we could push the value to the stack
    // and then pop it off of the stack again, OR-ing with the upper immediate

}

// Precomputed counts
int pre[0x80000000]; // ~ 1 byte * 2^32 ~= 4GB

// Counting bits set
uint8_t countBits(int n) {

    // 00000000000000000000000000000000 - Fast because of branch prediction
    // 01010101111100101010101010100100 - Slow
    // 11111111111111111111111111111111 - Fast because of branch prediction

    // Method 1

    uint8_t count = 0;
    for (uint8_t i = 0; i < 32; i++) {
        if ((n >> i) & 1) count++;
        // count += (n >> i) & 1; i.e. remove the if statement branch
    }
    return count;

    // Method 2

    count = 0;
    while (n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;

    // Method 3 (if in a loop, sequential access fast because cache hit always due to sequential prefetch!)
    // Random access depends on if the array fits in the cache.
    return pre[(uint32_t) n];

}

// Print letters used in sentence in order
// If not unique, then print NULL
void uniqueLetters(const char* sentence, int length) {

    // Mark 27th bit for repeat
    int isLetterUsed = 0;

    for (int i = 0; i < length; i++) {

        int idx;
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            idx = sentence[i] - 'A';
        } else if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            idx = sentence[i] - 'a';
        } else {
            continue;
        }

        if ((isLetterUsed >> idx) & 1) {
            // Repeat detected
            isLetterUsed |= 0x8000000;
            break;
        } else {
            isLetterUsed |= 1 << idx;
        }

    }

    if ((isLetterUsed >> 27) & 1) {
        printf("NULL\n");
    } else {
        for (int i = 0; i < 26; i++) {
            if ((isLetterUsed >> i) & 1) {
                printf("%c", i + 'a');
            }
        }
    }

}

int main() {
    char sentence[] = "Blowzy night-frumps vex'd Jack QQ";
    uniqueLetters(sentence, sizeof(sentence) / sizeof(char));
}