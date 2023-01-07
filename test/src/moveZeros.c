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

void MoveZeros(int *nums, int numSize)
{
	if (numSize == 0) {
		return;
	}
	int fast = 0;
	int slow = 0;
	while (fast < numSize) {
		if (nums[fast] != 0) {
			nums[slow++] = nums[fast];
		}
		fast++;
	}
    for (int i = slow; i < numSize; i++) {
        nums[i] = 0;
    }
}

int main()
{
	int nums[10] = { 1, 0, 1, 0, 2, 0, 3, 0, 3, 0};
	int numSize = sizeof(nums) / sizeof(int);
    MoveZeros(nums, numSize);
    PrintArrayElement(nums, numSize);
	return 0;
}