#include <stdint.h>
#include <stdio.h>

typedef struct someStruct someStruct;

struct someStruct {

  // Function pointer in struct
  // assign with s->funcName = funcName where funcName is a defined function
  // Functions decay into pointers anyway so &funcName not necessary but works
  void (*funcName)(int param1, int param2);

};

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
    int p = 1 << 31; // shifting into sign bit of a signed integer is UNDEFINED
    int q = -1 << 2; // left-shifting a negative number is UNDEFINED (so use UNSIGNED MASKS)
    int r = 1 << 32; // shifting by offset >= width of type is UNDEFINED

    // Extern for variables outside function (like global in Python)
    extern int i;
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

    // Print to stdout
    printf("%d in hex is %x", 5, 5);

    // Take input from stdin
    int num;
    scanf("%d", &num); // Remember to provide address


    // File I/O

    // Open a file
    FILE* filePointer;
    filePointer = fopen("example.txt", "w+"); // r, w, a, r+, w+, a+

    // Write char to file
    fputc('a', filePointer);

    // Write string to file
    fputs("hello there", filePointer); // OR
    fprintf(filePointer, "hello there");

    // Read char from file
    char c = fgetc(filePointer);

    // Read up to n-1 characters into buffer
    char buff[256];
    fgets(buff, 256, filePointer);

    // Read until first space character encountered
    fscanf(filePointer, "%s", buff);

    // Close file
    fclose(filePointer);

    // For binary I/O (i.e. reading or writing blocks of memory - usually arrays/structures)
    // size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);     
    // size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

    return 0;
  }