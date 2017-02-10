#include "Registry.h"

Registry::Registry()
{
    int memory = open( "/dev/mem", O_RDWR );
    this->address = (unsigned long *) mmap(
            NULL,
            this->BLOCK_SIZE,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            memory,
            this->BLOCK_ADDR
    );
    close( memory );
}
