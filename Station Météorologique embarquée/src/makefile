FILENAME = main
PORT = /dev/ttyACM0
PROGRAMMER = arduino
BAUD = 115200
DEVICE = atmega328p
COMPILE = avr-g++ -Wall -Os -mmcu=$(DEVICE)

default: compile upload clean

compile:
	l
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o 
	avr-objcopy -j text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf
	

upload:
	avrdude -C /etc/avrdude.conf -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex