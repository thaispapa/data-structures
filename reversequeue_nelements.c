#include <stdio.h>
#include <stdlib.h>

// Problem: reverse the first n elements of a queue.
// input : Q = [10, 20, 30, 40, 50, 60,
// 70, 80, 90, 100]
// n = 5
// output : Q = [50, 40, 30, 20, 10, 60,
// 70, 80, 90, 100]

// Let's use a stack to help us store

struct QNode {
    int data;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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

void push(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
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

void pop(struct Queue* q)
{
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        temp = head;
        head = head->next;
        // When we pop from the stack we enqueue again
        // but this time the last in is the first out
        // since we are using a stack.
        enQueue(q, temp->data);
        free(temp);
    }
}

void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;

    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    // When we dequeue an element we push it into a stack
    push(temp->data);

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

void reverse(struct Queue* q)
{
    if (q->front == NULL)
        return;

    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    enQueue(q,temp->data);

    free(temp);
}

int main()
{
    struct Queue* q = createQueue();

    int qtd;
    printf("Number of elements in the queue:\n");
    scanf("%i", &qtd);

    int elem;
    for(int i = 0; i < qtd; i++){
        printf("Insert an element:\n");
        scanf("%i", &elem);
        enQueue(q, elem);
    }

    int n;
    printf("Number of elements to reverse:\n");
    scanf("%i", &n);

    // ex.: Q = [10, 20, 30, 40, 50, 60,
    // 70, 80, 90, 100] and i = 5
    for(int i = 0; i < n; i++){
        deQueue(q);
    }
    // Q = [60, 70, 80, 90, 100]
    // meanwhile our stack S = [50, 40, 30, 20, 10]
    for(int i = 0; i < n; i++){
        pop(q);
    }
    // Q = [60, 70, 80, 90, 100, 50, 40, 30, 20, 10] and stack is empty
    for(int i = 0; i < n; i++){
        reverse(q);
    }
    // Q = [50, 40, 30, 20, 10, 60, 70, 80, 90, 100]

    printf("Queue with the first %i elements reversed:\n", n);
    display(q);
}
