#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE getnode()
{
    NODE ptr;
    ptr=(NODE)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("node not created");
        return NULL;
    }
    return ptr;
}

NODE insert_end(NODE first,int item)
{
    NODE new_end,current;
    new_end=getnode();
    new_end->data=item;
    new_end->next=NULL;
    if(first==NULL)
        return new_end;
    current=first;
    while(current->next!=NULL)
        current=current->next;
    current->next=new_end;
    return first;
}



NODE delete_end(NODE first)
{
    NODE prev,last;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
        return NULL;
    }
    prev=NULL;
    last=first;
    while(last->next!=NULL)
    {
        prev=last;
        last=last->next;
    }
    prev->next=NULL;
    free(last);
    return first;
}



void display(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Linked list is empty\n");
    }
    temp=first;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    NODE first=NULL;
    int choice,item,pos,value;
    while(1)
    {
        printf("\n Enter your choice\n 1.insert\n 2.delete\n 0.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter the item:");
                scanf("%d",&item);
                first=insert_end(first,item);
                break;
            }
        case 2:
            {
                first=delete_end(first);
                break;
            }
        case 0:
            {
                display(first);
                break;
            }
        default:
            {
                printf("exiting\n");
                exit(0);
            }
        }
    }
}
