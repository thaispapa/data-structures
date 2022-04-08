#include <stdio.h>
#include <stdlib.h>

// Simple code that shows how queue works.

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
            sizeof(struct Queue));
    queue -> capacity = capacity;
    queue -> front = queue -> size = 0;

    queue -> rear = capacity - 1;
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
    // We always enqueue the new element to the rear of the queue
    if (isFull(queue))
        printf("Queue is full!\n");
    queue -> rear = (queue -> rear + 1) % queue -> capacity;
    queue -> array[queue -> rear] = item;
    queue -> size = queue -> size + 1;
    printf("%i enqueued to queue\n", item);
}

int dequeue(struct Queue* queue)
{
    // We always dequeue the element located in the front of the queue
    if (isEmpty(queue))
        printf("Queue is empty!\n");
    int item = queue -> array[queue -> front];
    queue -> front = (queue -> front + 1)
                     % queue->capacity;
    queue -> size = queue -> size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        printf("Queue is empty!\n");
    return queue -> array[queue -> front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        printf("Queue is empty!\n");
    return queue -> array[queue -> rear];
}

int main()
{
    // Here we create our queue.
    struct Queue* queue = createQueue(1000);

    // Here we enqueue certain numbers to our queue.
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Here we dequeue from the queue, the element that must appears in the
    // output is 10 since it is the first element of the queue
    // and we know that in this structure we have first in first out method
    printf("%i dequeued from queue\n\n", dequeue(queue));

    printf("Front item is %i\n", front(queue));
    printf("Rear item is %i\n", rear(queue));

    return 0;
}

