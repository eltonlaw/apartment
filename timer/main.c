/* Timer code */
#define BAUD 9600
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <usart.h>

void flash(uint8_t b) {
    PORTB |= b;
    _delay_ms(100);
    PORTB &= ~b;
    _delay_ms(100);
}

int main(void) {
    uint8_t buffer;
    DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB7);

    usart_init();
    print_string("Hello World!\r\n");

    PORTB = 0xff;
        
    flash_twice(0b10000111);
    while (1) {
        _delay_ms(100000);
        buffer = receive_byte();
        transmit_byte(buffer);
        PORTB = buffer;
    }
    return (0);
}
