/**lab-1 Q2) Input – Two strings made of characters
Output – Find out if the smaller string exists in the larger one. If yes, how many times?
*/
#include <stdio.h>
#include <string.h>

int countSubstring(const char *str, const char *sub) {
    int count = 0;
    int subLen = strlen(sub);

    while (*str) {
        if (strncmp(str, sub, subLen) == 0) {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char largerString[100], smallerString[50];

    // Input larger string
    printf("Enter the larger string: ");
    fgets(largerString, sizeof(largerString), stdin);
    largerString[strcspn(largerString, "\n")] = '\0'; // Remove newline character

    // Input smaller string
    printf("Enter the smaller string: ");
    fgets(smallerString, sizeof(smallerString), stdin);
    smallerString[strcspn(smallerString, "\n")] = '\0'; // Remove newline character

    // Find and count occurrences
    int occurrences = countSubstring(largerString, smallerString);

    // Output the result
    if (occurrences > 0) {
        printf("The smaller string exists in the larger one, and it occurs %d times.\n", occurrences);
    } else {
        printf("The smaller string does not exist in the larger one.\n");
    }

    return 0;
}
