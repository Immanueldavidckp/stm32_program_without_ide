CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g -O0 -Wall -I.
LDFLAGS = -T stm32f446retx.ld -nostdlib

SOURCES = main.c startup_stm32f446retx.s
OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(OBJECTS:.s=.o)
EXECUTABLE = stm32f446_dma.elf
BINARY = stm32f446_dma.bin

all: $(EXECUTABLE) $(BINARY)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(BINARY): $(EXECUTABLE)
	$(OBJCOPY) -O binary --only-section=.isr_vector --only-section=.text --only-section=.rodata $< $@
	$(SIZE) $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q main.o startup_stm32f446retx.o stm32f446_dma.elf stm32f446_dma.bin

flash: $(BINARY)
	openocd -f custom_stm32f446re.cfg -c "program $(BINARY) verify reset exit 0x08000000"