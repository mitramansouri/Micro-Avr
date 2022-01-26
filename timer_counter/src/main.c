#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
double dutyCyle = 0.6 ;

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
    OCR0 = dutyCyle*255;

    while (1)
    {
        
    }
    
}