#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "util.h"

#define BUF_LEN 0x100
char *gift_flag = "/flag";
char *gift_binsh = "/bin/sh\0/bin/sh\0-p\0";
int fd;

void list_dir()
{
	system("ls");
}

void open_file()
{
	char fname[16];

        puts("Input file name:");
        scanf("%16s", fname);
        fd = open(fname, 0);
	if (fd < 0) {
		printf("无法打开文件\n");
		return;
	}
}

void read_flag()
{
        puts("No No No");
        // TODO here
        __asm__ __volatile__("ldp x2, x3, [sp], #16; ret;");
}

void leave_message()
{
        char buf[0x30];
        puts("Input your message:");
        read(0, buf, BUF_LEN); // vulnerable read
}

void close_file()
{
        if (fd < 0) {
		printf("文件未打开\n");
		return;
	}
        close(fd);
}

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void menu()
{
        puts("1. List dir");
        puts("2. Open file");
        puts("3. Read flag");
        puts("4. Leave message");
        puts("5. Close file");
        puts("6. Exit");
        puts("Choice >> ");
}

int main()
{
        int choice, flag = 1;

        init();
        print_desc();

        while (flag) {
                /* code */
                menu();
                scanf("%d", &choice);
                switch ( choice )
                {
                case 1:
                        list_dir();
                        break;
                case 2:
                        open_file();
                        break;
                case 3:
                        read_flag();
                        break;
                case 4:
                        leave_message();
                        break;                        
                case 5:
                        close_file();
                        break;
                case 6:
                        flag = 0;
                        break;
                default:
                        puts("Invalid choice");
                        break;
                }
        }
        
        print_exit();

	return 0;
}