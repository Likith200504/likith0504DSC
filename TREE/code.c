#include<stdio.h>
#include<stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST* NODE;

NODE create()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct BST));
    printf("Enter the item: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert(NODE root, NODE temp)
{
    if (root->data < temp->data)
    {
        if (root->right != NULL)
            insert(root->right, temp);
        else
            root->right = temp;
    }
    else
    {
        if (root->left != NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    }
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    NODE root = create();
    NODE temp;
    int choice;

    while (1)
    {
        printf("\nEnter your choice\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                temp = create();
                insert(root, temp);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0); 
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
