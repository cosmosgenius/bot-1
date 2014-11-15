TARGET = main

MCU	= atmega8
F_CPU = 8000000L

CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -Wall -Os -std=gnu99 -DF_CPU=$(F_CPU) -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
LDFLAGS = -mmcu=$(MCU) -Wl,-Map=main.map

SRC = src/main.c

OBJS = $(SRC:.c=.o)

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	@echo "Generating $< -> $@";
	@$(OBJCOPY) -O ihex $< $@

$(TARGET).elf: $(OBJS)
	@echo "Linking $^ -> $@";
	@$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	@echo "building $< -> $@"; 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.elf *.hex *.map $(OBJS)