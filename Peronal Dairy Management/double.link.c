#include <stdio.h>
typedef struct List{
    int data;
    struct List *next;
    struct List *prev;
}List,*Listptr;
Listptr head;
void insert (int val);

int main()
{
     head = NULL;
    insert (10);
    insert (20);
    insert (30);
    insert (40);
    return 0;
}
void insert(int x)
{
     Listptr newNode=malloc(sizeof(List));
    newNode->key=key;
    newNode->link=head;
    head=newNode;
}
