#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "uart.h"
#include "led.h"

int main ()
{
    //BLINKING LED

    // led_setup();
    // while(1)
    // {
    //     led_on();
    //     _delay_ms(1000);
    //     led_off();
    //     _delay_ms(1000);
    // }
    // led_off();

    //UART

    initialize_usart();
    while (1)
    {
        send_data("hello, world\r\n");
        _delay_ms(1000);
    }
    return 0;
}