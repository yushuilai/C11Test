#include <time.h>
#include <stdio.h>
#include <locale.h>

static void test_clock(){
    clock_t currClock = clock();
    printf("clock is: %lu\n", currClock);
}

static void test_time(){
    /* code */
    time_t curTime;
    time_t result = time(&curTime);
    if(result != -1){
        printf("%s\n", ctime(&result));
        printf("%s\n", ctime(&curTime));
    }
}

static void test_gmtime(){
    time_t currTime;
    currTime = time(NULL);
    struct tm* currTimeTm = gmtime(&currTime);

    printf("gmtime %s\n", asctime(gmtime(&currTime)));
    printf("localtime %s\n", asctime(localtime(&currTime)));
}

static void test_ctime(){
    time_t currTime = time(NULL);

    printf("test_ctime : %s\n", ctime(&currTime));

#ifdef __STDC_LIB_EXT1
    char str[26];
    ctime_s(str, sizeof(str), &currTime);
#endif
}

static void test_asctime(){
    time_t currTime = time(NULL);

    printf("test_asctime: %s\n", asctime(gmtime(&currTime)));

#ifdef __STDC_LIB_EXT1
    char str[26];
    asctime_s(str, sizeof(str), gmtime(&currTime));
#endif

}

static void test_strftime(){
    char str[128];
    struct tm myTime = {
        .tm_year=112, // = 2012年
        .tm_mon=9,    // = 10月
        .tm_mday=9,   // = 9日
        .tm_hour=8,   //= 8时
        .tm_min=10,   // = 10分
        .tm_sec=20    // = 20秒
    };

    strftime(str, sizeof(str), "%A %c", &myTime);
    printf("test_strftime = %s\n", str);
    
}

static void test_timespec_get(){

#ifdef TIME_UTC
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char buff[100];
    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
#endif
}

int main(int argc, char const *argv[])
{
    /* code */

    test_clock();

    test_time();

    test_gmtime();

    test_ctime();

    test_asctime();

    test_strftime();

    test_timespec_get();


    return 0;
}

