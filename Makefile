MCU = atmega328p
F_CPU = 16000000UL
BAUD = 9600
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DBAUD=$(BAUD) \
         -Os -Wall -std=c++11

PORT = /dev/ttyACM0
PROGRAMMER = arduino

SRC = src/main.cpp
TARGET = firmware

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -I include -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b 115200 -U flash:w:$<:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex