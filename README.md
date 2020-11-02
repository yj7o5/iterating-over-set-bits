### Iterating over set bits fast

Reading and analyzing over the following bits of articles posted on by Dr. Lamire on his blog: https://lemire.me/blog/2018/02/21/iterating-over-set-bits-quickly/

Just me experimenting with the code and re-writing and understanding bits and pieces of the puzzles. Also picking over the C skill that has been left in the wild.

It utilizes the builtin function from the standard C library `__builtin_ctlz` to count the trailing zeros and then finding the set bit. This minimizes the amount of bitwise operations needed to perform and thus reducing the number of machine instructions for the processor.

Also utilizing the following website, http://bitwisecmd.com/, a really handy site to perform bitwise operations and visualize the binary representation of the values and operations.
