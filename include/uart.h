#include <avr/io.h>

#define BAUD 9600
#define F_CPU 16000000UL

#define UBRRn (F_CPU / (16UL* BAUD)) - 1
void initialize_usart()
{
    UBRR0H = 0;
    UBRR0L = UBRRn;


    UCSR0B |= (1 << RXEN0);
    UCSR0B |= (1 << TXEN0);

    //8 bit data 1 stop bit 
    UCSR0B |= (0 << UCSZ02);

    UCSR0C |= (1 << UCSZ00);
    UCSR0C |= (1 << UCSZ01);
}
void send_byte(char data)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}
void send_data(const char* string)
{
    while (*string != '\0')
    {
        send_byte(*string);
        string++;
    }
}