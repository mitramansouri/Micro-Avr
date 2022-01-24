#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){

    DDRD |= (1<<0); //D0 is output 
    PORTD |= (1<<0);//initial value on D0= 1

    //Regs for interrups 
    //GICR
    GICR |= (1<<INT0);//set INT0 = 1 
    //MCUCR
    MCUCR |= (1<<ISC00); //Interrupts on Rising edge 11
    MCUCR |= (1<<ISC01); 
    

    sei();
    while (1)
    {
        
    }
    
}

ISR (INT0_vect){
    PORTD ^= (1<<0);
}