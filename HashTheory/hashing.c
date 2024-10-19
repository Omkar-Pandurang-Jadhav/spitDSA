#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function for Double Hashing
void doubleHashing(int *table, int *keys, int t, int k) {
    int ans;
    // Loop through all keys to be inserted
    for (int i = 0; i < k; i++) {
        ans = keys[i] % t; // Calculate the hash value (primary hash)

        // If the calculated position is empty, insert the key
        if (table[ans] == -1) {
            table[ans] = keys[i];
            printf("At index %d, %d key is inserted.\n", ans, keys[i]);
        } else { // Collision occurs
            printf("Collision on table index %d.\n", ans);
            int j = 1;
            int index = ans;
            // Try resolving collision using double hashing until an empty spot is found
            while (table[index] != -1) {
                printf("%dth probing.\n", j);
                // Double hashing formula: (h(k) + j * (1 + (key % (table size - 1)))) % table size
                index = (ans + j * (1 + (keys[i] % (t - 1)))) % t;
                printf("index = (h(k) + j * ((key) mod (size - 1))) mod (table size)\n");
                printf("index = (%d + %d * ((%d) mod %d)) mod %d = %d\n", ans, j, keys[i], t - 1, t, index);
                j++;
            }
            // Insert the key at the resolved position
            table[index] = keys[i];
            printf("At index %d, %d key is inserted.\n", index, keys[i]);
        }
    }
    // Print the final hash table
    printf("\nThe Hash Table for Double Hashing is:\n");
    printf("Index : Element\n");
    for (int i = 0; i < t; i++) {
        printf("%d : %d\n", i, table[i]);
    }
}

// Function for Quadratic Probing
void qudraticProbing(int *table, int *keys, int t, int k) {
    int ans;
    // Loop through all keys to be inserted
    for (int i = 0; i < k; i++) {
        ans = keys[i] % t; // Calculate the hash value (primary hash)
        // If the calculated position is empty, insert the key
        if (table[ans] == -1) {
            table[ans] = keys[i];
            printf("At index %d, %d key is inserted.\n", ans, keys[i]);
        } else { // Collision occurs
            printf("Collision on table index %d.\n", ans);
            int j = 1;
            int index = ans;
            // Try resolving collision using quadratic probing until an empty spot is found
            while (table[index] != -1) {
                printf("%dth probing.\n", j);
                // Quadratic probing formula: (h(k) + j*j) % table size
                index = (ans + j * j) % t;
                printf("index = (h(k) + j*j) mod (table size)\n");
                printf("index = (%d + %d * %d) mod %d = %d\n", ans, j, j, t, index);
                j++;
            }
            // Insert the key at the resolved position
            table[index] = keys[i];
            printf("At index %d, %d key is inserted.\n", index, keys[i]);
        }
    }
    // Print the final hash table
    printf("\nThe Hash Table for Quadratic Probing is:\n");
    printf("Index : Element\n");
    for (int i = 0; i < t; i++) {
        printf("%d : %d\n", i, table[i]);
    }
}

// Function for Linear Probing
void linearProbing(int *table, int *keys, int t, int k) {
    int ans;
    // Loop through all keys to be inserted
    for (int i = 0; i < k; i++) {
        ans = keys[i] % t; // Calculate the hash value (primary hash)

        // If the calculated position is empty, insert the key
        if (table[ans] == -1) {
            table[ans] = keys[i];
            printf("At index %d, %d key is inserted.\n", ans, keys[i]);
        } else { // Collision occurs
            printf("Collision on table index %d.\n", ans);
            int j = 1;
            int index = ans;
            // Try resolving collision using linear probing until an empty spot is found
            while (table[index] != -1) {
                printf("%dth probing.\n", j);
                // Linear probing formula: (h(k) + j) % table size
                index = (ans + j) % t;
                printf("index = (h(k) + j) mod (table size)\n");
                printf("index = (%d + %d) mod %d = %d\n", ans, j, t, index);
                j++;
            }
            // Insert the key at the resolved position
            table[index] = keys[i];
            printf("At index %d, %d key is inserted.\n", index, keys[i]);
        }
    }
    // Print the final hash table
    printf("\nThe Hash Table for Linear Probing is:\n");
    printf("Index : Element\n");
    for (int i = 0; i < t; i++) {
        printf("%d : %d\n", i, table[i]);
    }
}

int main() {
    int tableSize;
    int noOfKeys;
    // Input table size
    printf("Enter size of table: ");
    scanf("%d", &tableSize);
    // Input number of keys
    printf("Enter the number of keys: ");
    scanf("%d", &noOfKeys);

    // Allocate memory for hash tables and keys
    int *table1 = (int *)malloc(tableSize * sizeof(int));
    int *table2 = (int *)malloc(tableSize * sizeof(int));
    int *keys = (int *)malloc(noOfKeys * sizeof(int));

    // Input keys
    printf("Enter the keys in the array keys:\n");
    for (int i = 0; i < noOfKeys; i++) {
        scanf("%d", &keys[i]);
    }

    // Initialize hash tables to -1
    for (int i = 0; i < tableSize; i++) {
        table1[i] = -1;
        table2[i] = -1;
    }

    // Perform linear probing
    printf("\nThe operation on linear probing are as follows:\n");
    linearProbing(table1, keys, tableSize, noOfKeys);

    // Perform quadratic probing
    printf("\n\nThe operation on Quadratic probing are as follows:\n");
    qudraticProbing(table2, keys, tableSize, noOfKeys);

    // Input new table size for double hashing
    printf("\n\nEnter the table size for double hashing operation: ");
    int tableSize2;
    scanf("%d", &tableSize2);

    // Allocate memory for the double hashing table
    int *table3 = (int *)malloc(tableSize2 * sizeof(int));
    for (int i = 0; i < tableSize2; i++) {
        table3[i] = -1;
    }

    // Perform double hashing
    printf("\nThe operation of double hashing are as follows:\n");
    doubleHashing(table3, keys, tableSize2, noOfKeys);

    // Free allocated memory
    free(table1);
    free(table2);
    free(table3);
    free(keys);

    return 0;
}
