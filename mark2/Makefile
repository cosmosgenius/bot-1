TARGET = main

MCU	= atmega8
F_CPU = 8000000L

CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -Wall -Os -std=gnu99 -DF_CPU=$(F_CPU) -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
LDFLAGS = -mmcu=$(MCU) -Wl,-Map=main.map

all: main.hex

main.hex: main.elf
	$(OBJCOPY) -O ihex main.elf $@

main.elf: main.o
	$(CC) $(LDFLAGS) -o $@ main.o

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o $@

hex:
	avr-gcc -Os -DF_CPU=8000000 -mmcu=attiny85 -c led_flash.c
	avr-gcc -DF_CPU=8000000 -mmcu=attiny85 -o led_flash.elf led_flash.o
	avr-objcopy -O ihex led_flash.elf led_flash.hex

	avr-gcc -g -Os -mmcu=$(MCU_TARGET) -c src/main.c
	avr-gcc -g -mmcu=$(MCU_TARGET) -o main.elf main.o
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

	rm led_flash.o
	rm led_flash.elf

clean:
	$(RM) *.o *.elf *.hex *.map