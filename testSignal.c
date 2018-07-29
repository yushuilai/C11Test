#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

void signalHandler(int signal){

    printf("Catch signal %d\n", signal);

}

int main(int argc, char const *argv[])
{
    /* code */
    if(SIG_ERR == signal(SIGINT, signalHandler)){
        printf("Initial signal function error\n");
        return -1;
    }
    printf("raise SIGINT signal1!\n");
    raise(SIGINT);

    if(SIG_ERR == signal(SIGINT, SIG_IGN)){
        printf("Initial signal function error\n");
        return -1;
    }

    printf("raise SIGINT signal2!\n");
    raise(SIGINT);

    printf("Exit from main\n");
    return 0;
}
