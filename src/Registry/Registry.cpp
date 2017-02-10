#include "Registry.h"

Registry::Registry()
{
    int memory = open( "/dev/mem", O_RDWR );
    this->regAddress = (unsigned long *) mmap(
            NULL,
            this->BLOCK_SIZE,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            memory,
            this->BLOCK_ADDR
    );
    close( memory );
}

unsigned long int *Registry::address()
{
    return this->regAddress;
}
