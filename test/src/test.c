#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ADD 0
#define MUl 1

int Sum(int type, int arg, ...)
{
    va_list ap;
    va_start(ap, arg);
    int result = 0;
    if (type == ADD) {
        for (int i = 0; i < arg; i++) {
            result += va_arg(ap, int);
        }
    } else {
        result = 1;
        for (int i = 0; i < arg; i++) {
            result *= va_arg(ap, int);
        }  
    }
    va_end(ap);
    return result;
}

int main()
{
    int sum;
    sum = Sum(1, 5, 1, 2, 3, 4, 5, 6, 7, 8);
    printf("sum is [%d].\n", sum);
    return 0;
}