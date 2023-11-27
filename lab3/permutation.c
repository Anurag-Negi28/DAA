/**lab-3 Q1. Input: Permutation of {1, 2 …. n} with one element appearing twice, making it a sequence of n+1 integers.
Output: Identify the element that appears twice in O(n) complexity and O(1) space complexity.*/
#include <stdio.h>

int findDuplicate(int arr[], int n) {
    int s = arr[0];
    int f = arr[0];

    do {
        s = arr[s];
        f = arr[arr[f]];
    } while (s != f);

    f = arr[0];
    while (s != f) {
        s = arr[s];
        f = arr[f];
    }

    return s;
}

int main() {
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int perm[n + 1];

    printf("Enter the array:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &perm[i]);
    }

    int duplicate = findDuplicate(perm, n);
    printf("%d appears twice\n", duplicate);

    return 0;
}