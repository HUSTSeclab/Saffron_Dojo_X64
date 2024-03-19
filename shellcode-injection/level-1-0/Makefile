TARGET = shellcode-injection-level1.0
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lcapstone -z execstack -fno-stack-protector -static
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS)

clean: 
	rm -rf $(TARGET)

