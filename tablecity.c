// this is an insanely simple problem if you think about it!
// free 10 points :)

#include <stdio.h>

int main()
{
    printf("1998\n");
    for (int i = 2; i <= 1000; i++)
        printf("%d %d %d %d\n", i, 1, i, 2);
    for (int i = 2; i <= 1000; i++)
        printf("%d %d %d %d\n", i, 1, i, 2);
    return 0;
}
