/**in insertion sort use names as input instead of integers*/#include <stdio.h>
#include <string.h>

int main() {
    char arr[100][50];  // Assuming each string has a maximum length of 49 characters
    printf("Enter number of strings wanted:\n");
    int size;
    scanf("%d", &size);
    printf("Enter string values:\n");
    
    // Input strings
    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i]);
    }

    int i;
    char key[50];
    int j;

    for (i = 1; i < size; i++) {
        strcpy(key, arr[i]);
        j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }
        strcpy(arr[j + 1], key);
    }

    printf("Sorted array is:\n");
    
    // Output sorted strings
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    return 0;
}
