#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void insertionSort(int *array, int arraySize)
{
    int i, j, tmp;

    for (i = 1; i < arraySize; i++)
    {
        j = i - 1;
        tmp = array[i];

        while ((j >= 0) && (tmp < array[j]))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int maxSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int *result = (int *)malloc(maxSize * sizeof(int));
    int i = 0, j = 0, k = 0;

    insertionSort(nums1, nums1Size);
    insertionSort(nums2, nums2Size);

    while (i < nums1Size && j < nums2Size)
    {

        if (nums1[i] == nums2[j])
        {
            if (k == 0 || result[k - 1] != nums1[i])
            {
                result[k] = nums1[i];
                k++;
            }
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

    (*returnSize) = k;
    return result;
}

int main()
{
    int nums1[3] = {4, 9, 5};
    int nums2[5] = {9, 4, 9, 8, 4};
    int nums1Size = 3;
    int nums2Size = 5;
    int returnSize = 0;
    int *result = NULL;

    result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Interseccao: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", result[i]);
    }
    printf(" ]");

    free(result);

    return 0;
}
