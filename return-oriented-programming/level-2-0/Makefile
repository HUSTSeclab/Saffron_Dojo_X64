TARGET = return-oriented-programming-level2.0
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS = -fno-stack-protector -masm=intel
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
