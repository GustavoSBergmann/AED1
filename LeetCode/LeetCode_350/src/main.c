#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void insertionSort(int *array, int arraySize)
{
    for (int j = 1; j < arraySize; j++)
    {
        int i = j - 1;
        int temp = array[j];

        while ((i >= 0) && (temp < array[i]))
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = temp;
    }
}

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    insertionSort(nums1, nums1Size);
    insertionSort(nums2, nums2Size);

    int maxSizeResult = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int *result = (int *)malloc(maxSizeResult * sizeof(int));
    int i = 0, j = 0;

    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] == nums2[j])
        {
            result[*returnSize] = nums1[i];
            (*returnSize)++;
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

int main()
{
    int nums1[3] = {4, 9, 5}, nums2[5] = {9, 4, 9, 8, 4};
    int nums1Size = 3, nums2Size = 5;
    int returnSize = 0;
    int *result = NULL;

    result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Interseccao: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", result[i]);
    }
    printf(" ]");

    free(result);

    return 0;
}
