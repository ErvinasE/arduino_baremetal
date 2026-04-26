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

    // while (1)
    // {
    //     send_data("hello, world\r\n");
    //     _delay_ms(1000);
    // }

    initialize_usart();
    flush_buffer();
    send_data("Successfull init\r\n");
    char buffer[32];
    while(1)
    {
        receive_string(buffer);
        if (strcmp(buffer, "ping") == 0)
        {
            send_data("pong\r\n");
        }
        else
        {
            send_data("ERR\r\n");
        }
    }
    return 0;
}