#include <avr/io.h>

int main(void) {
    DDRC = 0xFF;
    DDRD = 0xFF;

    // ADC initialization
    ADMUX = (0 << REFS1) | (1 << REFS0) | (1<<ADLAR); // AVCC
    ADCSRA = (1<<ADEN) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);  // prescale = 8

    while (1) {   
        ADCSRA |= ((1 << ADSC) | (1 << ADIF)); // start conversion
        while( (ADCSRA & (1 << ADIF)) == 0 ); // wait till end of the conversion
        PORTC = (unsigned char)ADCW; // low 8 bit (ADCL)
        PORTD = (ADCW>>8); // high 8 bit (ADCH)
    }
}