#ifndef REGISTRY_H
#define REGISTRY_H

#include <unistd.h>
#include <mhash.h>
#include <fcntl.h>

class Registry {
public:
    const static int  BLOCK_ADDR   = 0x18040000;
    const static int  BLOCK_SIZE   = 0x30;
    const static int  OE_OFFSET    = 0x00;
    const static int  IN_OFFSET    = 0x01;
    const static int  OUT_OFFSET   = 0x02;
    const static int  SET_OFFSET   = 0x03;
    const static int  CLEAR_OFFSET = 0x04;

    Registry();
    unsigned long int *address();
    unsigned long int value;
protected:
    unsigned long int *regAddress = nullptr;
};


#endif //REGISTRY_H
