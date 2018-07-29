#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;
static int count = 0;
void test_longjmp()
{
    printf("test_longjmp = %d\n", count);
    count++;
    longjmp(env, count);
}

int main(int argc, char const *argv[])
{
    /* code */
    if(setjmp(env) < 10){
        test_longjmp();
    }
    return 0;
}
