#include "Pin.h"

Pin::Pin( int pin )
{
    this->pin = pin;
}

void Pin::on()
{
    this->setToOutput();

    *( registry.address() + Registry::SET_OFFSET ) = 0x1 << this->pin;
}

void Pin::off()
{
    this->setToOutput();

    *( registry.address() + Registry::CLEAR_OFFSET ) = 0x1 << this->pin;
}

void Pin::setToOutput()
{
    registry.value ^= ( -1 ^ registry.value ) & ( 1 << this->pin );
    *( registry.address()) = registry.value;
}

void Pin::high()
{
    return this->on();
}

void Pin::low()
{
    return this->off();
}
