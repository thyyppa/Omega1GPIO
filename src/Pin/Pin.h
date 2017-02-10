#ifndef PIN_H
#define PIN_H

#include "Registry/Registry.h"

class Pin {
public:
    Pin( int pin );
    void on();
    void off();
    void setToOutput();
protected:
    int      pin;
    Registry registry;
};


#endif //PIN_H
