#include <stdio.h>

int maxArea(int *height, int heightSize)
{
    int i = 0, j = heightSize - 1;
    int area = 0, base = 0;

    while (i <= j)
    {
        base = j - i;
        if (height[i] < height[j])
        {
            if (area < height[i] * base)
            {
                area = height[i] * base;
            }
            i++;
        }
        else
        {
            if (area < height[j] * base)
            {
                area = height[j] * base;
            }
            j--;
        }
    }

    return area;
}

int main()
{
    int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = 9;
    int area;

    area = maxArea(height, heightSize);

    printf("Area maxima: %d\n", area);

    return 0;
}
