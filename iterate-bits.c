#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
Other handy sites used to discover things:
http://bitwisecmd.com/ 
*/

/*
* Iterate over each index value perform and for each value perform bitwise <value> & -<value> operation
* to get just the only trailing bit, until <value> doesn't equal 0.
* 
* Count the trailing zeros using __builtin_ctzl(bitset)
*
* Then callback functions get passed the exact location of the trailing one. This way one get keep a
* count of set bits and their exact location in the bitmap.
*/
void bitmap_count_ctz(uint64_t* bitmap, size_t bitmapsize, void* callback(int)) {
    uint64_t bitset;

    for (size_t k = 0; k < bitmapsize; ++k) {
        bitset = bitmap[k];

        while (bitset != 0) {
            // <value> & -<value> returns just the least significant bit, all others off
            uint64_t t = bitset & -bitset;
            int r = __builtin_ctzl(bitset);
            callback(k * 64 + r);
            bitset ^= t;
        }
    }
}

/**
* And here's a pretty standard version nothing so fancy about this. Notice the difference here
* we are calling the bitwise operations 
*/
void bitmap_count_naive(uint64_t** bitmap, size_t bitmapsize, void* callback(int)) {
    uint64_t bitset;
    for (size_t k = 0; k < bitmapsize; k++) {
        bitset = bitmap[k];
        size_t p = k * 64;
        while (bitset != 0) {
            if (bitset & 0x1) {
                callback(p);
            }
            bitset >>= 1;
            p += 1;
        }
    }
}

void print_bitmap(uint64_t* bitmap) {
    
}

int main(void) {
    print("[bitmap decoding]");             

    int repeat = 5;
    size_t N = 10;
    uint64_t *bitmap = malloc(N * sizeof(uint64_t));

    /* Initialize random number generator */
    srand(time(NULL));

    for(size_t i = 0; i < N; i++) {
        bitmap[i] = (uint64_t)rand();
    }

    print_bitmap(bitmap);

    free(bitmap);

    return (0);
}
