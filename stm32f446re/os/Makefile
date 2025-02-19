CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -std=gnu11 -Wall -O0 -ffunction-sections -fdata-sections -g
LDFLAGS = -T linker.ld -nostdlib -Wl,--gc-sections
SOURCES = main.c startup.c rtos.c gpio.c usart.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = final.elf

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

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

qe:
	qemu-system-arm -cpu cortex-m4 -machine st1030-evb -nographic -kernel final.elf -S -gdb tcp::3333
