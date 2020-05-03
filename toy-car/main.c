#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define __AVR_ATmega328P__ 1
#define FORWARD 1
#define BACKWARD 2


static inline void init_l289n(void) {

    /* ------ Set output pins ------- */
    // PD0 connected to IN1 (pin 8)
    // PD1 connected to IN2 (pin 9)
    DDRD = (1 << PIND0) | (1 << PIND1);
    // PB1 connected to ENA (pin 7)
    DDRB = (1 << PINB1);

    // Output Compare 16-bit, this is done in two clock cycles (compiler magic)
    OCR1A = 0x01FF;

    // Protect 16-bit access
    unsigned char sreg;
    sreg = SREG; // save global interrupt flag
    cli(); // disable interupts

    /* -------- Timer Counter 1 Control Register A ------------ */
    // OC1A output overrides the normal port functionality of I/O pin it is
    // connected to
    TCCR1A |= (1 << COM1A1);
    // set non-inverting mode
    // PWM phase correct 10 bit
    TCCR1A |= (1 << WGM11) | (1 << WGM10);
    // set 10bit phase corrected PWM Mode
    /* -------- Timer Counter 1 Control Register B ------------ */
    TCCR1B |= (1 << CS11);
    
    // Restore global interrupt flag
    SREG = sreg;
}

static inline void init_adc0(void) {
    ADMUX |= (1 << REFS0); // Reference voltage on AVCC (disables AREF usage)

    // ADC Control and  Status Register A
    ADCSRA |= (1 << ADPS1) | (1 << ADPS0); // ADC clock prescaler /8
    ADCSRA |= (1 << ADEN); // Enable ADC

    // Use ADC[7:0] pins to replace negative input of the analog comparator
    // ADCSRA ^= ~(1 << ADEN); // Disable ADC
    // ADCSRB |= (1 << ACME); // Set Analog Comparator Multiplexer Enable to 1
    // ADMUX |= (1 << MUX1) | (1 << MUX2); // Use ADC6 as AC Negative Input

    // ADCSRA |= (1 << ADATE); // Enable ADC Auto Trigger Enable Bit

    // ADCSRA |= (1 << ADTS2); // Select trigger source for Auto Trigger Enable

    // You can use the ADC Interrupt Flag as a trigger source to make the ADC
    // start a new conversion as soon as the ongoing conversion has finished 
    // ADCSRA |= (1 << ADIF);
}

int main() {
    /* If the piezo sensor senses a vibration, light up the LED */

    // uint8_t led_value;
    // uint8_t i;
    volatile uint16_t adc_value; // ADC value is a 10 bit value

    init_adc0();
    init_l289n();

    // Initialize indicator LED
    DDRB |= (1 << PINB0);
    PORTB = (1 << PINB0);

    // Initialize Direction of Wheels
    PORTD |= (1 << PIND0);
    // Initialize input variable from piezo sensor
    int vibration_sensed = 0;

    while (1) {
        // Datasheet specification for a single conversion
        PRR &= ~(1 << PRADC); // Write 0 to Power Reduction ADC bit
        ADCSRA |= (1 << ADSC); // Write 1 to ADC Start Conversion bit
        // ADCS will stay high while conversion is in progress, low when done

        adc_value = ADC;
        if (adc_value < 512) {
            if (!vibration_sensed) {
                PORTD ^= ((1 << PIND0) | (1 << PIND1)); // Toggle only 
                PORTB ^= (1 << PINB0);  // Toggle only PB0
                vibration_sensed = 1;
            }
        } else {
            vibration_sensed = 0;
        }
    }
    return 0;
}
