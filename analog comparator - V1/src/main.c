#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
    DDRD = (1<<DDD0);

    SFIOR |= (0<<ACME); // disable ADC multiplexer output
    ACSR  |= (0<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (1<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0); // enable interrupt, intrupt mode = toggle

    sei(); // enable global interrupt
    while(1){}
}

ISR(ANA_COMP_vect) {
    PORTD ^= (1<<PORTD0); // toggle D0 port
}