#define BigLittleSwap32(A)                         ((((uint32)(A) & 0xff000000) >> 24) | /
                                                   (((uint32)(A) & 0x00ff0000) >> 8) | /
                                                   (((uint32)(A) & 0x0000ff00) << 8) | /
                                                   (((uint32)(A) & 0x000000ff) << 24))
