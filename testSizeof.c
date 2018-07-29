#include <stdio.h>

typedef struct person_t{
    int a;
    char b;
    long c;
    char d;
    double e;

}person_t;

int main(int argc, char const *argv[])
{
    /* code */
    int a[10];
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(&main) = %lu\n", sizeof(&main));
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(long) = %lu\n", sizeof(long));
    printf("sizeof(float) = %lu\n", sizeof(long));
    printf("sizeof(double) = %lu\n", sizeof(double));
    printf("sizeof(person_t) = %lu\n", sizeof(person_t));
    printf("sizeof(\"Hello\") = %lu\n", sizeof("Hello"));
    printf("sizeof(int a[10]) = %lu\n", sizeof(a));
    printf("sizeof((void*)(void)) = %lu\n", sizeof(int(*)(void)));
}
