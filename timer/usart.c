#ifndef BAUD
#define BAUD 9600
#endif
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "usart.h"

void usart_init(void) {
    UBRR0H = (UBRRH_VALUE >> 8);
    UBRR0L = UBRRL_VALUE;
	// Disable double speed operation (synchronous comms)
    UCSR0A &= ~(1 << U2X0);
	/* Enable USART transmitter and receiver */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void transmit_byte(uint8_t data) {
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = data;
}

uint8_t receive_byte(void) {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

void print_str(const char s[]) {
    int i = 0;
    while (s[i]) {
        transmit_byte(s[i]);
        i++;
    }
}
