TARGET = main

MCU	= atmega8
F_CPU = 8000000UL

CC = avr-gcc
CXX = avr-g++
OBJCOPY = avr-objcopy

PROGRAMMER = avrdude
TYPE = usbasp

CPPFLAGS = -mmcu=$(MCU) -Wall -Os -std=gnu++11 -DF_CPU=$(F_CPU) -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
LDFLAGS = -mmcu=$(MCU) -Wl,-Map=main.map

SRC = src/main.cc

OBJS = $(SRC:.cc=.o)

all: compile 

compile: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	@echo "Generating $< -> $@";
	@$(OBJCOPY) -O ihex $< $@

$(TARGET).elf: $(OBJS)
	@echo "Linking $^ -> $@";
	@$(CC) $^ $(LDFLAGS) -o $@

%.o: %.cc
	@echo "building $< -> $@"; 
	@$(CC) $(CPPFLAGS) -c $< -o $@

upload: compile
	$(PROGRAMMER) -c $(TYPE) -p $(MCU) -u -U flash:w:$(TARGET).hex

clean:
	$(RM) *.elf *.hex *.map $(OBJS)