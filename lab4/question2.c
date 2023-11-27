/**lab-4 Q2. Find the value of  (1+i)^n where i = sqrt (-1) in O(log2n) time and O(log2n) space.
Input: n
Output: (1+i)^n*/
#include <stdio.h>
#include <complex.h>


double complex complex_power(double complex base, int n) {
    if (n == 0) {
        return 1 + 0 * I;
    } else if (n % 2 == 0) {
        double complex temp = complex_power(base, n / 2);
        return temp * temp;
    } else {
        double complex temp = complex_power(base, (n - 1) / 2);
        return base * temp * temp;
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    double complex base = 1 + I; 
    double complex result = complex_power(base, n);

    printf("Result: %.2f + %.2fi\n", creal(result), cimag(result));
    return 0;
}
