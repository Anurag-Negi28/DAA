#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int rollNumber;
    char name[100];
} Student;

void merge(Student arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i].rollNumber <= rightArr[j].rollNumber)
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(Student arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{

    FILE *inputFile = fopen("merge_sort.txt", "r");
    if (inputFile == NULL)
    {
        perror("Could not open input.txt");
        return EXIT_FAILURE;
    }

    int numStudents = 0;
    char line[256];

    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        numStudents++;
    }

    rewind(inputFile);

    Student students[numStudents];
    int i = 0;

    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        sscanf(line, "Roll number %d,%99[^\n]", &students[i].rollNumber, students[i].name);
        i++;
    }

    fclose(inputFile);

    mergeSort(students, 0, numStudents - 1);

    FILE *outputFile = fopen("Output.txt", "w");
    if (outputFile == NULL)
    {
        perror("Could not open output.txt");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < numStudents; i++)
    {
        fprintf(outputFile, "Roll number %d,%s\n", students[i].rollNumber, students[i].name);
    }

    fclose(outputFile);

    printf("Student details sorted and saved to output.txt.\n");

    return 0;
}
