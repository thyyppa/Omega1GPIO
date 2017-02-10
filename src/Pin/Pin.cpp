#include "Pin.h"

Pin::Pin( int pin )
{
    this->pin = pin;
}

void Pin::on()
{
    this->setToOutput();

    *( registry.address + registry.offset.set ) = 0x1 << this->pin;
}

void Pin::high()
{
    return this->on();
}

void Pin::off()
{
    this->setToOutput();

    *( registry.address + registry.offset.clear ) = 0x1 << this->pin;
}

void Pin::low()
{
    return this->off();
}

void Pin::setToOutput()
{
    unsigned long int oe = *( registry.address + registry.offset.oe );
    oe ^= ( -1 ^ oe ) & ( 1 << this->pin );
    *( registry.address + registry.offset.oe ) = oe;
}

void Pin::setToInput()
{
    unsigned long int oe = *( registry.address + registry.offset.oe );
    oe ^= ( 0 ^ oe ) & ( 1 << this->pin );
    *( registry.address + registry.offset.oe ) = oe;
}
