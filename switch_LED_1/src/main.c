#include <avr/io.h>
#include <util/delay.h>

int main(void){
    //PA output 
    //PB input , pullup 
    // DDRA = 0x00000001 
    DDRA = (0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (1<<DDA0); //PA0 output 
    DDRB = (0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);  // B input
    PORTB = (0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (1<<PORTB0); // B0 pullup

    while (1)
    {
        _delay_ms(20);
        if (((PINB << PINB0 ) & 1) == 0){ //checks the PINB0, it is pullup so it is initially 1 and will be 0 when pushed
            PORTA |= (1<<PORTA0); //Setting the PORTA0 
        }
        else {
            PORTA &= ~(1<<PORTA0); // clearing the PORTA0
        }
    }
}