#include <stdio.h>
#include <stdlib.h>

void insert(int q[], int *rear, int item, int QSIZE) {
    if (*rear == QSIZE - 1) {
        printf("Queue overflow\n");
    } else {
        (*rear)++;
        q[*rear] = item;
    }
}

void delete(int *front, int *rear, int q[]) {
    if (*front > *rear) {
        printf("Queue underflow\n");
    } else {
        printf("Deleted item: %d\n", q[*front]);
        (*front)++;
    }
}

void display(int *front, int *rear, int q[]) {
    if (*front == *rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = *front; i <= *rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int QSIZE = 3;
    int q[QSIZE];
    int choice, item;
    int front = 0;
    int rear = -1;

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                insert(q, &rear, item, QSIZE);
                break;
            case 2:
                delete(&front, &rear, q);
                break;
            case 3:
                display(&front, &rear, q);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    printf("Likith.Tarakaram");
    printf("1BM23CS171");
    return 0;
}
