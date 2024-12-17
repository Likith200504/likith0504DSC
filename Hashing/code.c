#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht, index;
int count = 0;

void insert(int key) {
    index = key % m;
    while (ht[index] != -1) {
        index = (index + 1) % m;
    }
    ht[index] = key;
    count++;
}

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++) {
        printf("T[%d] --> %d\n", i, ht[i]);
    }
}

int main() {
    int i;
    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("Enter the key values (4-digit integers) for %d Employee Records:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    for (i = 0; i < n; i++) {
        if (count == m) {
            printf("\nHash table is full. Cannot insert the record %d key\n", i + 1);
            break;
        }
        insert(key[i]);
    }

    display();
    free(ht);
    return 0;
}
