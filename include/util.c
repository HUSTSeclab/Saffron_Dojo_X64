#include "util.h"

static char guess[] = "Guess who I am?\0";

void upper_print_str(char *str)
{
        const int cnt = 60;
        int i, padding, remain = 0;
        char upper_str[UTIL_MAX_LEN] = {0};

        // upper string
        for (int i = 0; str[i] != '\0'; i++) {
                upper_str[i] = toupper(str[i]);
        }

        padding = (cnt - 2 - strlen(str)) / 2;
        remain = (cnt - 2 - strlen(str)) % 2;

        // padding
        for (i = 0; i < padding; i++) {
                printf("=");
        }
        // print string
        printf(" %s ", upper_str);
        // padding
        for (i = 0; i < padding; i++) {
                printf("=");
        }
        if (remain) {
                printf("=");
        }
        printf("\n");
}


int print_image(char * pokemon_name, char * filename)
{
	char read_string[UTIL_MAX_LEN];
	FILE *fptr = NULL;

        // open pokemon text art file
	if((fptr = fopen(filename,"r")) == NULL) {
		fprintf(stderr,"error opening %s\n",filename);
		return 1;
	}

        // print pokemon text art
        upper_print_str(guess);
	while(fgets(read_string, sizeof(read_string), fptr) != NULL)
		printf("%s",read_string);
	printf("\n");
        
        // print pokemon name
        upper_print_str(pokemon_name);
        fflush(stdout);

	fclose(fptr);
	return 0;
}
