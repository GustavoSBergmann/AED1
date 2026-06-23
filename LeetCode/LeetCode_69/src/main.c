#include <stdio.h>

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    int left = 0, right = x;
    int resp = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid == x / mid)
        {
            if (mid * mid == x)
            {
                return mid;
            }
            resp = mid;
            left = mid + 1;
        }
        else if (x / mid < mid)
        {
            right = mid - 1;
        }
        else if (mid < x / mid)
        {
            resp = mid;
            left = mid + 1;
        }
    }

    return resp;
}

int main()
{
    printf("Raiz: %d\n", mySqrt(8));

    return 0;
}
