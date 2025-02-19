CC=arm-none-eabi-gcc
MACH=cortex-m4
INCLUDES = -I./BSW -I./os -I./rte
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 $(INCLUDES) -g
LDFLAGS= -mcpu=$(MACH) -mthumb -nostdlib -T linker.ld -Wl,-Map=final.map

SRCS = application/main.c os/Os.c os/TaskManager.c os/Scheduler.c os/switch.c BSW/gpio.c BSW/usart.c startup.c
OBJS = $(SRCS:.c=.o)

all: final.elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f application/*.o BSW/*.o os/*.o rte/*.o *.o final.elf final.map

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
