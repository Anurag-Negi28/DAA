#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the permutation: ");
    scanf("%d", &n);
    int perm[n + 3];
    for (int i = 0; i < n + 3; i++)
    {
        printf("Enter element: ");
        scanf("%d", &perm[i]);
    }

    // find duplicates
    for (int i = 0; i < n + 3; i++)
    {
        int index = perm[i] % (n + 3);
        perm[index] += n + 3;
    }
    printf("Elements appearing twice: ");
    for (int i = 0; i < n + 3; i++)
    {
        if (perm[i] >= 2 * (n + 3))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
