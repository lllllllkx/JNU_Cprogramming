#include <stdio.h>
#include <stdlib.h>

struct QueueNode 
{
    int data;
    struct QueueNode *next;
};
struct QueueNode *front = NULL, *rear = NULL;

void enqueue(int val) 
{
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = val;
    newNode->next = NULL;
    if(front == NULL) 
	{
        front = rear = newNode;
    } 
	else 
	{
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", val);
}

void dequeue() 
{
    if(front == NULL) 
	{
        printf("Queue Underflow\n");
        return;
    }
    struct QueueNode *temp = front;
    printf("Dequeued %d\n", temp->data);
    front = front->next;
    if(front == NULL) 
		rear = NULL;
    free(temp);
}

void displayQueue() 
{
    if(front == NULL) 
	{
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (Front to Rear): ");
    struct QueueNode *temp = front;
    while(temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    enqueue(100);
    enqueue(200);
    enqueue(300);
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}
