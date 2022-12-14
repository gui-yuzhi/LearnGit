#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void PrintArrayElement(int *nums, int numSize)
{
	if (nums == NULL) {
		printf("nums is null.\n");
	}
	for (int i = 0; i < numSize; i++) {
		printf("nums[%d] is [%d].\n", i, nums[i]);
	}
}

int RemoveElement(int *nums, int numSize, int val)
{
	if (numSize == 0) {
		return 0;
	}
	int fast = 0;
	int slow = 0;
	while (fast < numSize) {
		if (nums[fast] != val) {
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	PrintArrayElement(nums, numSize);
	return slow;
}

int main()
{
	int nums[10] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 3};
	int numSize = sizeof(nums) / sizeof(int);
    int val = 3;
	printf("result is [%d].\n", RemoveElement(nums, numSize, val));
	return 0;
}