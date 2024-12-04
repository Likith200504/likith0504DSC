#include <stdio.h>
#include <stdlib.h>

void insert(int q[], int *rear, int *count, int item,int QSIZE) {
    if (*count >= QSIZE) {
        printf("Queue overflow\n");
    } else {
        *rear = (*rear + 1) % QSIZE;
        q[*rear] = item;
        (*count)++;
    }
}

int delete(int q[], int *front, int *count, int QSIZE) {
    int deleted_item;
    if (*count == 0) {
        printf("Queue underflow\n");
        return -1;
    } else {
        deleted_item = q[*front];
        *front = (*front + 1) % QSIZE;
        (*count)--;
        return deleted_item;
    }
}

void display(int q[], int *front, int *count, int QSIZE) {
    int i;
    if (*count == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (i = *front; i < *front + *count; i++) {
            printf("%d ", q[i % QSIZE]); // Correctly display elements
        }
        printf("\n");
    }
}

int main() {
    int count = 0;
    int QSIZE=3;
    int q[QSIZE];
    int choice, deleted_item, item;
    int front = 0;
    int rear = -1;

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                insert(q, &rear, &count, item,QSIZE);
                break;
            case 2:
                deleted_item = delete(q, &front, &count, QSIZE);
                printf("deleted item is %d\n", deleted_item);
                break;
            case 3:
                display(q, &front, &count, QSIZE);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    printf("Likith.Tarakaram");
    printf("1BM23CS171");
    return 0;
}
