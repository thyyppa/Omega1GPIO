#include "Pin.h"

Pin::Pin( int pin )
{
    this->pin = pin;
}

void Pin::on()
{
    this->setToOutput();

    *( registry.address + registry.offset.set ) = this->bit();
}

void Pin::high()
{
    return this->on();
}

void Pin::off()
{
    this->setToOutput();

    *( registry.address + registry.offset.clear ) = this->bit();
}

void Pin::low()
{
    return this->off();
}

void Pin::setToOutput()
{
    unsigned long int oe = *( registry.address + registry.offset.oe );
    oe ^= ( -1 ^ oe ) & ( this->bit());
    *( registry.address + registry.offset.oe ) = oe;
}

void Pin::setToInput()
{
    unsigned long int oe = *( registry.address + registry.offset.oe );
    oe ^= ( 0 ^ oe ) & ( this->bit());
    *( registry.address + registry.offset.oe ) = oe;
}

/**
 * Untested
 * todo: test!
 */
unsigned long int Pin::read()
{
    unsigned long int reading;
    reading = *( registry.address + registry.offset.in );
    return (( reading >> this->pin ) & 0x01 );
}

unsigned long int Pin::bit()
{
    return ( 0x01 << this->pin );
}
