#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
double dutyCyle = 0 ;


int main(void){
    // OC0 is output pin (on PB3)
    DDRB |= (1<<PORTB3);

    // Fast PWM
    TCCR0 |= (1<<WGM01) | (1<<WGM00);

    // Clear on compare match (the non inverting type)
    TCCR0 |= (1<<COM01);

    // Pre-scalling 
    TCCR0 |= (1<<CS01);

    // DC 
    OCR0 = (dutyCyle/100)*255;

    // TMISK - OverFlow interrupt
    TIMSK |= (1<<TOIE0);
    sei();

    while (1)
    {
        _delay_ms(100);
        dutyCyle += 10;
        if (dutyCyle >100){
            dutyCyle = 0;
        }
    }
    
}
ISR (TIMER0_OVF_vect){
    OCR0 = (dutyCyle/100)*255;
}