Dictionary Library
---
This library is a simple hashmap implementation written in pure standard C for fun. Currently only a `char *` to `char *` hashmap is implemented, although the intention is to implement a version that works with most datatypes.

### Hashing function
The current choice of hashing function is just simply expressed as, `sum([ord(x) for x in string]) % hashTableLength`. Yes, this is terrible. Yes, I'm planning on changing it.

### Installation instructions
The library can be imported with just a simple, `#include "cdictlib.h"`. It requires no dependencies besides the standard C library.

### Example
A working example can be found in `examples/example.c` and can be compiled and ran with, `make && ./example`. For the lazy, here's an succinct example to show off the functionality:

```
#include <stdio.h>
#include "cdictlib.h"

int main(int argc, char ** argv) {
    Dictionary * myDict = newDictionary();
    setContents(myDict, "My key", "My value");

    // Output is: "My key contains: My Value."
    printf("My key contains: %s.\n", getContents(myDict, "My key"));

    freeDictionary(myDict);
    return 0;
}
```