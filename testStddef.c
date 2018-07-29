#include <stdio.h>
#include <stddef.h>

static struct a_t{
    int a;
    int b;
}a_t;

int main(int argc, char const *argv[])
{
    /* code */
    int a[2];
    ptrdiff_t diff = &a[0] - &a[1];
    printf("ptr diff = %td\n", diff);

    printf("offsetof(s, a) = %zu\n", offsetof(struct a_t, a));
    printf("offsetof(s, b) = %zu\n", offsetof(struct a_t, b));
    return 0;
}
