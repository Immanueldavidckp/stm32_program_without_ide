CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0  -g
LDFLAGS= -mcpu=$(MACH) -mthumb -nostdlib -T linker.ld -Wl,-Map=final.map

SRCS = main.c rtos.c gpio.c usart.c startup.c
OBJS = $(SRCS:.c=.o)

all: final.elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o final.elf final.map

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

qemu:
	qemu-system-arm -M ast1030-evb -cpu cortex-m4 -kernel final.elf -s -S

target:
	target remote localhost:3333
