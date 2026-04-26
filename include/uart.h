#include <avr/io.h>

#define BAUD 9600
#define F_CPU 16000000UL

#define UBRRn (F_CPU / (16UL* BAUD)) - 1

unsigned char maxlen = 32;
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
char receive_byte()
{
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}
void receive_string(char* buffer)
{
    int i = 0;
    while(1)
    {
        if (i >= maxlen - 1)
        {
            flush_buffer();
            break;
        }
        char c = receive_byte();
        if (c == '\n' || c == '\r') break;
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
}
void flush_buffer()
{
    unsigned char t;
    while (UCSR0A & (1 << RXC0)) t = UDR0;
}