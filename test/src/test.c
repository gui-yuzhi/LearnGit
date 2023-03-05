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

/* test begin */
int main()
{
    int sum;
    sum = Sum(0, 6, 1, 2, 3, 4, 5, 6);
    printf("sum is [%d].\n", sum);
    return 0;
}

#define RESERT_NUM 4
#define BI_EVENT_PARAM_NUM 8
typedef struct {
    char *sn;
    char *prodId;
    int proType;
    int failCase;
    int reverse[RESERT_NUM];
} BiEventParam;

