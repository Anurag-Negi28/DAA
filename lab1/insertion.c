//lab-1 Q1.Insertion Sort
//Input – Integers in arbitrary order, separated by space
//Output – Integers in sorted order, separated by space
#include <stdio.h>
int main() {
    int arr[100];
    printf("Enter number of integers wanted \n");
    int size;
    scanf("%d",&size);
    printf("Enter array values\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("sorted array is\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}