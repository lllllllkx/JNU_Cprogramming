#include <stdio.h>
#include <stdlib.h>

struct StackNode 
{
    int data;
    struct StackNode *next;
};
struct StackNode *top = NULL;

void push(int val) 
{
    struct StackNode *newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to stack\n", val);
}

void pop() 
{
    if(top == NULL) 
	{
        printf("Stack Underflow\n");
        return;
    }
    struct StackNode *temp = top;
    printf("Popped %d from stack\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack() 
{
    if(top == NULL) 
	{
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    struct StackNode *temp = top;
    while(temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(30);
    push(20);
    push(10);
    displayStack();
    pop();
    displayStack();
    return 0;
}
