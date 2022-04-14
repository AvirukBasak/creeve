# ifndef HEADERS_H

    # define HEADERS_H             1

    # include <stdio.h>
    # include <string.h>
    # include <stdlib.h>
    # include <ctype.h>
    # include <stdint.h>

    # define true                ( 1 )
    # define false               ( 0 )

    # define BUFFER_SIZE         ( 16 )

    typedef int8_t byte;
    typedef int16_t word;
    typedef int32_t dword;
    typedef int64_t qword;

    typedef uint8_t ubyte;
    typedef uint16_t uword;
    typedef uint32_t udword;
    typedef uint64_t uqword;

    typedef uint8_t bool;

    typedef char *string;

# endif
