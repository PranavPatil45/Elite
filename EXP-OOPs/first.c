#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = (char *)malloc(10);

    *(int *)ptr = 10;

    *(ptr + 4) = 'A';
    *(ptr + 5) = 'B';
    *(ptr + 6) = 'C';
    *(ptr + 7) = 'D';

    *(short int *)(ptr + 8) = 20;

    printf("Integer = %d\n", *(int *)ptr);
    printf("Characters = %c %c %c %c\n", *(ptr + 4), *(ptr + 5), *(ptr + 6), *(ptr + 7));
    printf("Short Integer = %d\n", *(short int *)(ptr + 8));

    free(ptr);

    return 0;
}