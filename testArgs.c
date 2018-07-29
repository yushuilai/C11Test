#include <stdio.h>
#include <stdarg.h>

int sample_printf(const char* fmt, ...){
    va_list list;
    va_start(list, fmt);
    while(*fmt != '\0'){
        if(*fmt == 'd'){
            int i = va_arg(list, int);
            printf("%d\n", i);
        }else if(*fmt == 'c'){
            int i = va_arg(list, int);
            printf("%c\n", i);
        }else if(*fmt == 'f'){
            double d = va_arg(list, double);
            printf("%f\n", d);
        }

        ++fmt;
    };

    va_end(list);
}

int main(int argc, char const *argv[])
{
    /* code */
    sample_printf("dccf", 1, 'c', 'd', 1.99999);
}
