#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_LEN 0x100

void open_file()
{
        puts("No No No");
}

void read_flag()
{
        puts("No No No");
}

void leave_message()
{
        char buf[0x30];
        puts("Input your message:");
        read(0, buf, BUF_LEN); // vulnerable read
}

void gift()
{
        puts("Here is your gift");
        printf("printf 函数的地址: %p\n", &printf);     // just give libc address to player
}

void close_file()
{
        puts("No No No");
}

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void menu()
{
        puts("1. Open file");
        puts("2. Read flag");
        puts("3. Leave message");
        puts("4. Close file");
        puts("5. Gift");
        puts("6. Exit");
        puts("Choice >> ");
}

int main()
{
        int choice, flag = 1;

        init();
        puts("This is an easy challenge of ret2libc, have fun :)");

        while (flag) {
                /* code */
                menu();
                scanf("%d", &choice);
                switch ( choice )
                {
                case 1:
                        open_file();
                        break;
                case 2:
                        read_flag();
                        break;
                case 3:
                        leave_message();
                        break;
                case 4:
                        close_file();
                        break;
                case 5:
                        gift();
                        break;
                case 6:
                        flag = 0;
                        break;
                default:
                        puts("Invalid choice");
                        break;
                }
        }
        
        puts("Bye bye~");

	return 0;
}