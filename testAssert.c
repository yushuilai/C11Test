#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

void show_errno(void){
   
   switch(errno){
    case EDOM:
        printf("Domain error \n");
        break;
    case EILSEQ:
        printf("Illegal sequence!");
        break;
    case ERANGE:
        printf("pole or range error!");
        break;
    default:
        break;
   }
}
int main(int argc, char const *argv[])
{
    /* code */
    printf("MATH_ERRNO is %s\n", math_errhandling & MATH_ERRNO ? "set" : "not set");
    errno = 0;
    1.0/0.0;


}
