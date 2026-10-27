#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insert_head(int val) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void insert_tail(int val) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) 
	{
        head = new_node;
        return;
    }
    struct Node* p = head;
    while (p->next != NULL) 
		p = p->next;
    p->next = new_node;
}

void insert_mid(int val, int pos) 
{
    int i;
	if (pos <= 1 || head == NULL) 
	{
        insert_head(val);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    struct Node* p = head;
    for (i = 1; i < pos-1 && p->next != NULL; i++) 
	{
        p = p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
}

void display() 
{
    struct Node* p = head;
    if (p == NULL) 
	{
        printf("Linked List is empty\n");
        return;
    }
    printf("Linked List elements: ");
    while (p != NULL) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() 
{
    insert_tail(10);
    insert_tail(30);
    display();
    insert_head(5);
    display();
    insert_mid(20,3);
    display();
    return 0;
}
