#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int * TwoSum(int *nums, int numSize, int target)
{
    int *result = (int *)malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;
    if (numSize < 2) {
        return result;
    }
	int left = 0;
	int right = numSize - 1;
	while (left < right) {
        int sum = nums[left] + nums[right];
		if (sum == target) {
            result[0] = left;
            result[1] = right;
            return result;
		}
        if (sum < target) {
            left++;
        }
        if (sum > target) {
            right--;
        }
	}
    return result;
}

int main()
{
	int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int numSize = sizeof(nums) / sizeof(int);
    int target = 20;
    int *result = TwoSum(nums, numSize, target);
    printf("result is [%d, %d].\n", result[0], result[1]);
	return 0;
}