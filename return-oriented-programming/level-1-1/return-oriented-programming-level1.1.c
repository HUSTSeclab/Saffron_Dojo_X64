#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

#define BUF_LEN 0x100
char *flag = "/flag\0";

void gift()
{
        // TODO here
        __asm__ __volatile__(
                "ldp x2, x3, [sp], #16; ret;"
                "ldp x0, x1, [sp], #16; ret;"
                "svc 0; ret;"
        );
}

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

int main()
{
        char s[0x10];

        init();
        print_image("Furret", "image.txt");
        
        read(0, s, BUF_LEN); // vulnerable read

        puts("Bye bye~");

	return 0;
}