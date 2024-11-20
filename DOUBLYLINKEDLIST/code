#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
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

NODE insert_beg(NODE first,int item)
{
    NODE new_node;
    new_node=getnode();
    new_node->value=item;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(first==NULL)
        return new_node;
    new_node->next=first;
    first->prev=new_node;
    return new_node;
}
NODE insert_value(NODE first,int item,int key)
{
    NODE new,current=first;
    new=getnode();
    new->value=item;
    new->next=NULL;
    new->prev=NULL;
    if(first==NULL)
        return new;
    while(current!=NULL && current->value!=key)
        current=current->next;
    if(current->value==key)
    {
        (current->prev)->next=new;
        new->prev=current->prev;
        new->next=current;
        current->prev=new;
        return first;
    }
    else
    {
        printf("value not found");
        return first;
    }
}

NODE delete_value(NODE first,int key)
{
    NODE current=first;
    if(first==NULL)
    {
        printf("LL is empty");
        return NULL;
    }
    while(current!=NULL && current->value!=key)
        current=current->next;
    if(current->value==key)
    {
        (current->prev)->next=current->next;
        (current->next)->prev=current->prev;
        free(current);
        return first;
    }
    else
    {
        printf("value not found");
        return first;
    }
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
        printf("%d ",temp->value);
        temp=temp->next;
    }
}
void main()
{
    NODE first=NULL;
    int choice,item,pos,key;
    while(1)
    {
        printf("\nEnter your choice\n 1.insert\n 2.insert_left_value\n 3.delete_value\n 4.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
               printf("Enter the item:");
               scanf("%d",&item);
               first=insert_beg(first,item);
               break;
            }
        case 2:
            {
                printf("Enter the item:");
                scanf("%d",&item);
                printf("enter the value to be searched");
                scanf("%d",&key);
                first=insert_value(first,item,key);
                break;
            }
        case 3:
            {
                printf("enter the value to be deleted");
                scanf("%d,&key");
                delete_value(first,key);
                break;
            }
        case 4:
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
