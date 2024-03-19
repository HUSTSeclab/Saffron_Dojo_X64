TARGET = shellcode-injection-level3.0
CC = gcc
CFLAGS = -Wall -Wextra -Werror  
LDFLAGS = -z execstack -fPIE -pie -z now -fno-stack-protector
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS)

clean: 
	rm -rf $(TARGET)

