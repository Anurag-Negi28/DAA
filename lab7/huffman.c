/**lab-7 Q1. Input: A total of 10 characters and their probability distribution 
Output: Huffman codes for these 10 characters
Example : Input           Output (Huffman code for)
a : 0.01                          a : 
b : 0.09                          b :
c : 0.10                          c :
d : 0.05                          d :
e : 0.15
f : 0.10
g : 0.20
h : 0.02
i : 0.08
j : 0.20
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the Huffman tree
struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(char data, unsigned freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Custom comparison function for sorting nodes by frequency
int compare(const void* a, const void* b) {
    return ((struct Node*)a)->freq - ((struct Node*)b)->freq;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;

    // Create an array to store the nodes
    struct Node* nodes[size];

    // Initialize the nodes with the given data and frequencies
    for (int i = 0; i < size; ++i)
        nodes[i] = newNode(data[i], freq[i]);

    // Build the Huffman tree
    while (size > 1) {
        // Sort the nodes in ascending order by frequency
        qsort(nodes, size, sizeof(struct Node*), compare);

        left = nodes[0];
        right = nodes[1];

        // Create a new internal node with these two nodes as children
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Remove the processed nodes from the array
        nodes[0] = top;
        for (int i = 1; i < size - 1; ++i)
            nodes[i] = nodes[i + 1];

        size--;
    }
    return nodes[0];
}

// Function to print Huffman codes from the root of the Huffman tree
void printHuffmanCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (root->data != '$') {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int freq[] = {10, 15, 12, 3, 4, 13, 1, 2, 5, 10};
    int size = sizeof(data) / sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, freq, size);

    int arr[size], top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);

  return 0;
}