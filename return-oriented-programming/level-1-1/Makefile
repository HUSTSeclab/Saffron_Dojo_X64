TARGET = return-oriented-programming-level1.1
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS = -fno-stack-protector -no-pie -masm=intel
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
