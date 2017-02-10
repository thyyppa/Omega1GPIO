#include "main.h"

Pin  white_led( LED_WHITE );
char in;

int main( int argc, char *argv[] )
{
    while ( true )
    {
        std::cin >> in;
        switch ( in )
        {
            case '1':
                white_led.on();
                break;
            default:
                white_led.off();
        }
    }
}
