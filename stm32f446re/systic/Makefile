CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 -ffunction-sections -fdata-sections
LDFLAGS= -g -O0 -nostdlib -T linker.ld -Wl,--gc-sections

all: final.elf

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $<

startup.o: startup.c
	$(CC) $(CFLAGS) -o $@ $<

final.elf: main.o startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o final.elf

nm:
	arm-none-eabi-nm final.elf

dumph:
	arm-none-eabi-objdump -h final.elf

dumpd:
	arm-none-eabi-objdump -d final.elf

gdb:
	arm-none-eabi-gdb final.elf

load:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program final.elf verify reset exit"

openocd:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
