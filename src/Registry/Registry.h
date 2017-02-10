#ifndef REGISTRY_H
#define REGISTRY_H

#include <unistd.h>
#include <mhash.h>
#include <fcntl.h>

struct Block {
    const static int address = 0x18040000;
    const static int size    = 0x30;
};

struct Offsets {
    const static int oe    = 0x00;
    const static int in    = 0x01;
    const static int out   = 0x02;
    const static int set   = 0x03;
    const static int clear = 0x04;
};

class Registry {
public:
    Registry();
    Block             block;
    Offsets           offset;
    unsigned long int value;
    unsigned long int *address = nullptr;
protected:
};

#endif //REGISTRY_H
