#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void filter_num(char *str);

int main(void)
{
    char buffer[1000];
    char area_code[4];
    char xch_num[4];
    char sub_num[5];

    printf("Enter phone number: ");
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        fprintf(stderr, "Error in fgets\n");
        exit(EXIT_FAILURE);
    }

    filter_num(buffer);
    if (sscanf(buffer, "%3s%3s%4s", area_code, xch_num, sub_num) != 3) {
            fprintf(stderr, "Phone number format error\n");
            exit(EXIT_FAILURE);
        }

    printf("Phone number is: (%s) %s-%s\n",
           area_code, xch_num, sub_num);

    return 0;
}

void filter_num(char *str)
{
    char *p = str;
    while (*p != '\0') {
        if (isdigit(*p)) {
            *str++ = *p;
        }
        ++p;
    }
    *str = '\0';
}
