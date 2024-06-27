#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int element)
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        {printf("\n Queue is full!! \n");}
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

int dequeue()
{
    int element;
    if (front==-1)
    {
        printf("\n Queue is empty !! \n");
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("\n Deleted element -> %d \n", element);
        return (element);
    }
}

// Display the queue
void display()
{
    int i;
    if (front==-1)
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\n Rear -> %d \n", rear);
    }
}

int main()
{
    dequeue();

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    enqueue(6);

    display();
    dequeue();

    display();

    enqueue(7);
    display();

    enqueue(8);

    return 0;
}
