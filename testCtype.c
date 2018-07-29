#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <limits.h>

static void test_isalnum(){
    unsigned char c = '\xdf';
    
    printf("isalnum('\xdf') in default C local return %d\n", isalnum(c));

    if(setlocale(LC_CTYPE, "de_DE.iso88591")){
        printf("isalnum(\xdf) in ISO-8859-1 locale return %d\n", isalnum(c));
    }
}

static void test_isalpha(){
    unsigned char c = '\xdf';
    
    printf("isalpha('\xdf') in default C local return %d\n", isalpha(c));

    if(setlocale(LC_CTYPE, "de_DE.iso88591")){
        printf("isalpha(\xdf) in ISO-8859-1 locale return %d\n", isalpha(c));
    }
}

static void test_islower(){
    unsigned char c = '\xe5'; // ISO-8859-1 的字母 å

    printf("islower('\xe5') in default c return %d\n", islower(c));

    if(setlocale(LC_CTYPE, "de_DE.iso88591")){
        printf("islower('\xe5') in ISO-8859-1 locale return %d\n", islower(c));
    }
}

static void test_isupper(){

    unsigned char c = '\xc6'; // ISO-8859-1的 字母 Æ 
    printf("In locale c isupper('\xc6') is upper return = %d\n", isupper(c));
    if(setlocale(LC_CTYPE, "de_DE.iso88591")){
         printf("isupper('\xe5') in ISO-8859-1 locale return %d\n", isupper(c));
    }
}

static void test_isdigit(){
    for(int i = 0; i < UCHAR_MAX; i++){
        if(isdigit(i)){
            printf("%c",i);
        }
    }
    printf("\n");
}

static void test_isxdigit(){
    for(int i = 0; i < UCHAR_MAX; i++){
        if(isxdigit(i))
        printf("%c", i);
    }
    printf("\n");
}

static void test_iscntrl(){
    unsigned char c = '\x94'; // ISO-8859-1 的控制码 CCH 
    printf("In default c '\x94' is  %s control character.\n", iscntrl(c) ? "": "not");

    if(setlocale(LC_CTYPE, "de_DE.iso88951")){
         printf("In locale c '\x94' is %s control character.\n", iscntrl(c) ? "": "not");
    }
}

static void test_isgraph(){
    unsigned char c = '\xb6'; // ISO-8859-1 的字符 ¶
    printf("In the default C locale, \\xb6 is %sgraphical\n", isgraph(c) ? "" : "not " );
    if(setlocale(LC_ALL, "en_GB.iso88591")){
        printf("In ISO-8859-1 locale, \\xb6 is %sgraphical\n",isgraph(c) ? "" : "not " );
    }
}

static void test_isspace(){
    printf("Space character is:\n");
    for(int i = 0; i < UCHAR_MAX; i++){
        if(isspace(i)){
            printf("%02x\n", i);
        }
    }
    printf("\n");
}

static void test_isblank(){
    //C99
    printf("Blank character is:\n");
    for(int i = 0; i < UCHAR_MAX; i++){
        if(isblank(i)){
            printf("%02x\n", i);
        }
    }
    printf("\n");
}

static void test_isprint(){
    unsigned char c = '\xa0'; // ISO-8859-1 的无中断空格
    printf("In the default C locale, \\xa0 is %sprintable\n", isprint(c)?"":"not ");
    if(setlocale(LC_ALL, "en_GB.iso88591")){
        printf("In ISO-8859-1 locale, \\xa0 is %sprintable\n", isprint(c)?"":"not ");
    }
}

static void test_ispunct(){
    unsigned char c = '\xd7'; // ISO-8859-1的字符×（乘号）
    printf("In the default C locale, \\xd7 is %spunctuation\n",ispunct(c) ? "" : "not " );
    
    if(setlocale(LC_ALL, "en_GB.iso88591")){
        printf("In ISO-8859-1 locale, \\xd7 is %spunctuation\n",ispunct(c) ? "" : "not " );
    }
}

static void test_tolower(){
    printf("Upper to lower test:\n");
    for(int i = 0; i < UCHAR_MAX; i++){
        if(isupper(i)){
            printf("%c:%c\n", i, tolower(i));
        }
    }
    printf("\n");
}

static void test_toupper(){
    printf("Lower to upper:\n");
    for(int i = 0; i < UCHAR_MAX; i++){
        if(islower(i)){
            printf("%c:%c\n", i, toupper(i));
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]){

    /* code */
    test_isalnum();

    test_isalpha();

    test_islower();

    test_isupper();

    test_isdigit();

    test_isxdigit();

    test_iscntrl();

    test_isgraph();

    test_isspace();

    test_isblank();

    test_isprint();

    test_ispunct();

    test_tolower();

    test_toupper();

    return 0;
}