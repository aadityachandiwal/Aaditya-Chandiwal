#include <stdbool.h>
#include <stdlib.h>

// Hash node structure for handling collisions via chaining
typedef struct Node {
    int val;
    struct Node* next;
} Node;

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return false;
    }

    // Set table size to twice the array size to reduce collisions
    int tableSize = numsSize * 2; 
    Node** hashTable = (Node**)calloc(tableSize, sizeof(Node*));

    for (int i = 0; i < numsSize; i++) {
        // Compute bucket index, handling negative numbers
        int key = abs(nums[i]) % tableSize;

        // Check if the value already exists in the bucket
        Node* curr = hashTable[key];
        while (curr != NULL) {
            if (curr->val == nums[i]) {
                // Duplicate found: free allocated memory and return true
                for (int j = 0; j < tableSize; j++) {
                    Node* tmp = hashTable[j];
                    while (tmp) {
                        Node* toFree = tmp;
                        tmp = tmp->next;
                        free(toFree);
                    }
                }
                free(hashTable);
                return true;
            }
            curr = curr->next;
        }

        // Insert new value at the head of the bucket list
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = nums[i];
        newNode->next = hashTable[key];
        hashTable[key] = newNode;
    }

    // No duplicates found: clean up memory and return false
    for (int i = 0; i < tableSize; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            Node* toFree = curr;
            curr = curr->next;
            free(toFree);
        }
    }
    free(hashTable);

    return false;
}
