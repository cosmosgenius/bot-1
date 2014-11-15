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

clean:
	$(RM) *.o *.elf *.hex *.map