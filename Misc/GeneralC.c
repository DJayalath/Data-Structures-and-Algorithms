#include <stdint.h>

// Static makes i inaccessible to files outside this one
static int i;

int main() {
    
    // Zero-initialised array
    char my_array[20] = {0};

    // sizeof(my_array) = 20 -> will give array size in bytes UNLESS passed into function
    // sizeof(my_array) = sizeof(char*) = 1 -> If passed into function as array is DOWNGRADED TO RAW POINTER
    size_t my_array_size_bytes = sizeof(my_array);
    // BUT it does not decay if undowngraded array is target of &, e.g. &my_array will not give the full pointer (not downgraded)
    // In the case of dynamically allocated arrays, it is obviously always a RAW POINTER

    // 0 is false, anything else is true in evaluation
    // Comparison always yields 0 (false) or 1 (true)
    int a;
    int b = a < 0 < 2; // = (a < 0) < 2 = (0 or 1) < 2 = True

    // Be careful when shifting signed integers - the following are undefined:
    int a = 1 << 31; // shifting into sign bit of a signed integer is UNDEFINED
    int a = -1 << 2; // left-shifting a negative number is UNDEFINED
    int a = 1 << 32; // shifting by offset >= width of type is UNDEFINED

    // Extern for variables outside function (like global in Python)
    extern i;
    i += 1;

    ///////////////////////////////////////
    // Order of Evaluation
    ///////////////////////////////////////

    //---------------------------------------------------//
    //        Operators                  | Associativity //
    //---------------------------------------------------//
    // () [] -> .                        | left to right //
    // ! ~ ++ -- + = *(type)sizeof       | right to left //
    // * / %                             | left to right //
    // + -                               | left to right //
    // << >>                             | left to right //
    // < <= > >=                         | left to right //
    // == !=                             | left to right //
    // &                                 | left to right //
    // ^                                 | left to right //
    // |                                 | left to right //
    // &&                                | left to right //
    // ||                                | left to right //
    // ?:                                | right to left //
    // = += -= *= /= %= &= ^= |= <<= >>= | right to left //
    // ,                                 | left to right //
    //---------------------------------------------------//


    return 0;
  }