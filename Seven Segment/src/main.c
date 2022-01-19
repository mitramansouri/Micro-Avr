#include <avr/io.h>
#include <avr/delay.h>

int main(void){
    unsigned char common_catode[10] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F };
    int i = 0 ;

    DDRC = (1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0); //PORTC is output 
    PORTC = (0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0); // value of PORTC is 0x00
    while (1)
    {
    for (i=0; i < 10; i++)
    {
        PORTC = common_catode[i];
        _delay_ms(100);
    }
    }
    
}