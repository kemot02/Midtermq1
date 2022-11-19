#include "main.h"
#include "usb_host.h"
#define rccahb1enR *((unsigned volatile int*)0x40023830)
#define gpiodOdr *((unsigned volatile int*)0x40020c14)
#define gpiodModr *((unsigned volatile int*)0x40020c00)
#define gpiod 1<<3
#define gpiodP14 1<<28 //reg14
#define gpiodP13 1<<26 //reg13
#define gpiodP14on 1<<14 //on
#define gpiodP14off 0<<14 //off
#define gpiodP13on 1<<13 //on
#define gpiodP13off ~(1<<13) //off
void init_leds(){
	 rccahb1enR =gpiod;
	 gpiodModr=gpiodP14; //red led
	 gpiodModr |=gpiodP13; //orange led
}
void name(){
	turn_name_on();
	delay();
	turn_name_off();
	delay();
}
void surname(){
	turn_surname_on();
	delay();
	turn_surname_off();
	delay();
}
void turn_surname_on(){
	 gpiodOdr =gpiodP14on;

}
void turn_surname_off(){
	 gpiodOdr =gpiodP14off;

}
void turn_name_on(){
	 gpiodOdr |=gpiodP13on;

}
void turn_name_off(){
	 gpiodOdr &=gpiodP13off;

}
void delay(){
	int delay0 = 0x000FFFFF; //delay loop
	while (delay0--){
		}
}
 int main(){
init_leds();
int i;
	for(i=0;i<5;i++){
	name();
}
	for(i=0;i<6;i++){
	surname();
}

return 0;

 }
