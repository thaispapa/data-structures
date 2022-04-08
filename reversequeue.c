#include <stdio.h>
#include <stdlib.h>

// Program to reverse the order of the elements in a queue.
// For example:
// [1] [4] [5] [2] → [2] [5] [4] [1]
// This following queue code was implemented using linked list.

struct QNode {
    int data;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct QNode* newNode(int d)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->data = d;
    temp->next = NULL;

    return temp;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int d)
{
    struct QNode* temp = newNode(d);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;

    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(struct Queue* q)
{
    if(q->front == NULL)
        printf("Queue is Empty!!!\n");
    else
    {
        struct QNode *temp = q->front;
        while(temp->next != NULL)
        {
            printf("%i ",temp->data);
            temp = temp -> next;
        }
        printf("%i ",temp->data);
    }
}

int reverse(struct Queue* q)
{
    int aux;
    if(q->front == NULL){
        return 0;
    }else{
        aux = q->front->data;
        deQueue(q);
        reverse(q);
        enQueue(q, aux);
    }
}

int main()
{
    struct Queue* q = createQueue();
    int e, data;

    printf("Number of elements in the queue:\n");
    scanf("%i", &e);

    for(int i = 0; i < e; i++){
        printf("Insert element:\n");
        scanf("%i", &data);
        enQueue(q, data);
    }

    reverse(q);

    printf("Reversed queue: ");
    display(q);

    return 0;
}
