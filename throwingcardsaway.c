#include <stdio.h>
#include <stdlib.h>

// Problem 1110 from beecrowd for just one case

// A card is removed from the top of pile of cards
// and the card that is now at the top will go to the bottom
// and so on until there's only one card left

// output: sequence of removed cards and the last card left

int discard;

struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue -> capacity = capacity;
    queue -> front = queue -> rear = -1;
    queue -> size = 0;
    queue -> array = (int*)malloc(queue -> capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue -> size == queue -> capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue -> size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue)){
        printf("Queue is full!\n");
    }else if(isEmpty(queue)){
        queue -> front = queue -> front + 1;
        queue -> rear = queue -> front;
        queue -> array[queue -> front] = item;
        queue -> size = queue -> size + 1;
    }else{
        queue -> rear = queue -> rear + 1;
        queue -> array[queue -> rear] = item;
        queue -> size = queue -> size + 1;
    }
}

void dequeue(struct Queue* queue, struct Queue* queue2)
{
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
    }else{
        discard = queue -> array[queue -> front];
        queue -> front = queue -> front + 1;
        queue -> size = queue -> size - 1;
        enqueue(queue2, discard);
        queue -> rear = queue -> rear + 1;
        queue -> array[queue -> rear] = queue -> array[queue ->front];
        queue -> front = queue -> front + 1;
    }
}

void display(struct Queue* queue){
    if(isEmpty(queue))
        printf("Queue is empty!\n");
    else{
        for(int i = queue -> front; i <= queue -> rear; i++)
        {
            printf("%i ", queue -> array[i]);
        }
    }
}

int main()
{
    int n = 50;
    struct Queue *q = createQueue(n);
    struct Queue *q2 = createQueue(n);

    int qtd;
    printf("\nNumber of cards:\n");
    scanf("%i", &qtd);
    for(int j = 1; j < qtd + 1; j++){
        enqueue(q, j);
    }
    for(int i = 1; i < qtd; i++){
        dequeue(q, q2);
    }
    printf("Discarded cards: ");
    display(q2);
    printf("\nRemaining card: ");
    display(q);

    return 0;
}
