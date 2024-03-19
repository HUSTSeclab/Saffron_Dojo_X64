TARGET = return-oriented-programming-level2.4
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
SECFLAGS = -Wno-format-security

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
