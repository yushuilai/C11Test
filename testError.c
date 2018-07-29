#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <fenv.h>

#pragma STDC FENV_ACCESS ON

void show_errno(void){
   
   switch(0 ){
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
        //errno = 0;
   }

    if (math_errhandling & MATH_ERREXCEPT) {
        int res = fetestexcept(FE_ALL_EXCEPT);
        
        if(res & FE_DIVBYZERO){
            printf("FE_DIVBYZERO raised\n");
        }
        else if(res & FE_OVERFLOW){
            printf("FE_OVERFLOW raised\n");
        }
        else if(res & FE_INEXACT){
            printf("FE_INEXACT raised\n");
        }
        else if(res & FE_UNDERFLOW){
            printf("FE_UNDERFLOW raised\n");
        }
        else if(res & FE_INVALID){
            printf("FE_INVALID raised\n");
        }else
             printf("no raised %d\n", res);

        feclearexcept(FE_ALL_EXCEPT);
            
    }
}


double divide(double x, double y)
{
	double res = x/y;
	return res;
}


int main(int argc, char const *argv[])
{
    /* code */
    double x = 1e-40;
    float y;
    printf("MATH_ERRNO is %s\n", math_errhandling & MATH_ERRNO ? "set" : "not set");
    printf ("Error handling: %d\n", math_errhandling);

    errno = 0;
    show_errno();

    //note 1.0/0.0 = inf
    printf("1.0/0.0 = %f\n", divide(2.0, 0.0)); 
    show_errno();

    printf("acos(1.1) = %f\n", acos(+1.1));
    show_errno();
 
    printf("lpow(1000, 10000) = %f\n", pow(1000, 10000));
    show_errno();

    printf("lpow(1000, -10000) = %f\n", pow(1000, -10000));
    show_errno();

    printf("log(0.0) = %f\n", log(0.0));
    show_errno();

    printf("sin(0.0) = %f\n", sin(0.0));
    show_errno();

    printf("sqrt(-1) = %f\n", sqrt((double)-1));
    show_errno();

    printf("y=x= %f\n", y = x);
    show_errno();

    return 0;

}
