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

int* searchRange(int* nums, int numsSize, int target){
    int* ret = malloc(sizeof(int) * 2);
    if (nums == NULL || numsSize == 0) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (nums[left] != target) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    ret[0] = left;
    left = 0;
    right = numsSize - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (nums[mid] <= target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    ret[1] = right;
    return ret;
}

/* test begin */
int main()
{
    int sum;
    // sum = Sum(0, 6, 1, 2, 3, 4, 5, 6);
    // printf("sum is [%d].\n", sum);
    int nums[] = { 5, 7, 7, 8, 8, 10};
    int *res = searchRange(nums, 6, 6);
    printf("res is {%d, %d}", *res, *++res);
    return 0;
}