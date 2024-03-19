TARGET = return-oriented-programming-level2.4
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS = -Wno-format-security
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
