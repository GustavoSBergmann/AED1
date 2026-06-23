#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    int nums[4] = {1, 3, 5, 6};
    int numsSize = 4;
    int target = 7;

    printf("Posicao: %d\n", searchInsert(nums, numsSize, target));
    return 0;
}
