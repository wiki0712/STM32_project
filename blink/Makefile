CROSS_COMPILE ?= arm-none-eabi-

.PHONY: all

all: blink.bin

blink.o: blink.c
	$(CROSS_COMPILE)gcc -mcpu=cortex-m4 -mthumb -nostartfiles -c blink.c -o blink.o

blink.out: blink.o blink.ld
	$(CROSS_COMPILE)ld -T blink.ld -o blink.out blink.o		

blink.bin: blink.out
	$(CROSS_COMPILE)objcopy -j .text -O binary blink.out blink.bin

clean:
	rm -rf *.o *.out *.bin
 
