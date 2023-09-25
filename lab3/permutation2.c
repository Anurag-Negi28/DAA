#include <stdio.h>

int main()
{
    int nums[] = {2, 2, 3, 4, 4, 1};
    int n = sizeof(nums) / sizeof(nums[0]) - 2;
    int xor_all = 0;
    int xor_array = 0;

    for (int i = 1; i <= n; i++)
    {
        xor_all ^= i;
    }

    for (int i = 0; i < n + 2; i++)
    {
        xor_array ^= nums[i];
    }

    int xor_duplicates = xor_all ^ xor_array;

    int bit_mask = 1;
    while ((xor_duplicates & bit_mask) == 0)
    {
        bit_mask <<= 1;
    }

    int duplicate1 = 0;
    int duplicate2 = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i & bit_mask)
        {
            duplicate1 ^= i;
        }
        else
        {
            duplicate2 ^= i;
        }
    }

    for (int i = 0; i < n + 2; i++)
    {
        if (nums[i] & bit_mask)
        {
            duplicate1 ^= nums[i];
        }
        else
        {
            duplicate2 ^= nums[i];
        }
    }

    printf("The first duplicate element is: %d\n", duplicate1);
    printf("The second duplicate element is: %d\n", duplicate2);

    return 0;
}
