CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=final.map

all:main.o stm32_startup.o  final.elf

semi:main.o stm32_startup.o syscalls.o final_sh.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf: main.o stm32_startup.o 
	$(CC) $(LDFLAGS) -o $@ $^
	
final_sh.elf: main.o stm32_startup.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf

load:

	openocd -f board/stm32f4discovery.cfg 
debug:
	arm-none-eabi-gdb final.elf


qemu:
	qemu-system-arm -M ast1030-evb -cpu cortex-m4 -kernel final.elf -s -S
