 #include <avr/io.h>
#include <util/delay.h>
#include <LCD.h>


int key_pressed(void) {
    PORTA = PORTA | (1<<PORTA1) | (1<<PORTA2) | (1<<PORTA3);
    PORTA &= ~(1<<PORTA0);
    if(!((PINA >> PINA4) & 1)) return 7;
    if(!((PINA >> PINA5) & 1)) return 8;
    if(!((PINA >> PINA6) & 1)) return 9;
    if(!((PINA >> PINA7) & 1)) return 10;

    PORTA = PORTA | (1<<PORTA0) | (1<<PORTA2) | (1<<PORTA3);
    PORTA &= ~(1<<PORTA1);
    if(!((PINA >> PINA4) & 1)) return 4;
    if(!((PINA >> PINA5) & 1)) return 5;
    if(!((PINA >> PINA6) & 1)) return 6;
    if(!((PINA >> PINA7) & 1)) return 11;

    PORTA = PORTA | (1<<PORTA0) | (1<<PORTA1) | (1<<PORTA3);
    PORTA &= ~(1<<PORTA2);
    if(!((PINA >> PINA4) & 1)) return 1;
    if(!((PINA >> PINA5) & 1)) return 2;
    if(!((PINA >> PINA6) & 1)) return 3;
    if(!((PINA >> PINA7) & 1)) return 12;

    PORTA = PORTA | (1<<PORTA0) | (1<<PORTA1) | (1<<PORTA2);
    PORTA &= ~(1<<PORTA3);
    if(!((PINA >> PINA4) & 1)) return 15;
    if(!((PINA >> PINA5) & 1)) return 0;
    if(!((PINA >> PINA6) & 1)) return 14;
    if(!((PINA >> PINA7) & 1)) return 13;
    
    return 16; // if no key is pressed it'll return 16
}


void show_pressed_key(int key) {
    if(key==0)  LCD_write('0');
    if(key==1)  LCD_write('1');
    if(key==2)  LCD_write('2');
    if(key==3)  LCD_write('3');
    if(key==4)  LCD_write('4');
    if(key==5)  LCD_write('5');
    if(key==6)  LCD_write('6');
    if(key==7)  LCD_write('7');
    if(key==8)  LCD_write('8');
    if(key==9)  LCD_write('9');
    if(key==10) LCD_write('/');
    if(key==11) LCD_write('*');
    if(key==12) LCD_write('-');
    if(key==13) LCD_write('+');
    if(key==14) LCD_write('=');
    if(key==15) LCD_cmd(0x01); // Clear the lcd
}


int main(void) {
    int key;

    DDRB=0xFF; //B is output 
    DDRD=0x07; //D2-1-0 is output 
    DDRA=0X0F; //A3-2-1-0 is output other inputs
    
    PORTA=0XF0;//value of PA is 11110000

    init_LCD();

    while (1){
        do
            key = key_pressed();
        while(key==16); // if no key was pressed key_pressed will return 16

        show_pressed_key(key); 
        
        _delay_ms(100);
    };
}