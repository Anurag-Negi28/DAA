#include <stdio.h>
#include <stdlib.h>

int fibo(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int *fib = (int *)malloc(2 * sizeof(int));
    if (fib == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int nextFib = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = nextFib;
    }

    int result = fib[1];
    free(fib);

    return result;
}

int main()
{
    int n = 100;
    int result = fibo(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}