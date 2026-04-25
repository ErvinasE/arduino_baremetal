#include <avr/io.h>
void led_setup()
{
    DDRB |= (1 << DDB5);
}
void led_on()
{
    PORTB |= (1 << PORTB5);
}
void led_off()
{
    PORTB &= (0 << PORTB5);
}