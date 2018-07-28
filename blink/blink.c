#define RCC_AHB1_PERI_ENBLR_ADDR	(*((volatile unsigned long*) (0x40023800 + 0x30) )) 
#define GPIO_G_PORTMODE			(*((volatile unsigned long*)  0x40021800 ))
#define GPIO_G_OUTPUT_TYPE		(*((volatile unsigned long*) (0x40021800 + 0x4 ) ))
#define GPIO_G_PUPD			(*((volatile unsigned long*) (0x40021800 + 0xC ) ))
#define GPIO_G_PORT_SETRESET		(*((volatile unsigned long*) (0x40021800 + 0x18) ))


asm(".word 0x20001000");
asm(".word main ");

int main()
{

	int i;

	RCC_AHB1_PERI_ENBLR_ADDR 	|= (0x00000001 << 6); 	/*Enalbe GPIO G clock*/

	GPIO_G_PORTMODE 		|= (0x00000001 << 26 | 0x00000001 << 28);	/* Set PG13 PG14 mode to GPIO */
	GPIO_G_PORTMODE 		&= ~(0x00000001 << 27 | 0x00000001 << 29);   

	GPIO_G_OUTPUT_TYPE		&= ~(0x00000001 << 13 | 0x00000001 << 14);	/*Set PG13 PG14 to push-pull*/					
	GPIO_G_PUPD			|= (0x00000001 << 27 | 0x00000001 << 29);  	/*Set PG13 PG14 to pull-down*/
	
	while(1)
	{
		GPIO_G_PORT_SETRESET 	= 0x20004000; /*PG13 off, PG14 on*/
		for(i = 0 ; i < 100000 ; i++);
		GPIO_G_PORT_SETRESET	= 0x40002000; /*PG14 off, PG13 on*/
		for(i = 0 ; i < 100000 ; i++);
	}
	
	
	return 0;
}
