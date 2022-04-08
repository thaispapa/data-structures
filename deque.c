#include <stdio.h>
#include <stdlib.h>

// Double-ended queue
// elements can be added to or removed from either the front or rear

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;

struct node * createNode(int data){

    struct node *newnode = (struct node *)malloc(sizeof (struct node));

    newnode->data = data;
    newnode->next = newnode->prev = NULL;

    return (newnode);
}

void createSentinels()
{
    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void enqueueAtFront(int data)
{
    struct node *newnode, *temp;
    newnode = createNode(data);

    temp = head->next;
    head->next = newnode;
    newnode->prev = head;
    newnode->next = temp;
    temp->prev = newnode;
}

void enqueueAtRear(int data)
{
    struct node *newnode, *temp;
    newnode = createNode(data);

    temp = tail->prev;
    tail->prev = newnode;
    newnode->next = tail;
    newnode->prev = temp;
    temp->next = newnode;
}

void dequeueAtFront()
{
    struct node *temp;

    if (head->next == tail) {
        printf("Queue is empty\n");
    } else {
        temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        free(temp);
    }
}

void dequeueAtRear()
{
    struct node *temp;

    if (tail->prev == head) {
        printf("Queue is empty\n");
    } else {
        temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if (head->next == tail) {
        printf("Queue is empty\n");
        return;
    }

    temp = head->next;

    while (temp != tail) {
        printf("%-3d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int data, key;

    createSentinels();

    while(1)
    {
        printf("1. Add element to the front\n2. Add element to the rear\n");
        printf("3. Remove element from the front\n4. Remove element from the rear\n");
        printf("5. Show queue\n6. Quit\n");
        scanf("%d", &key);
        switch (key) {
            case 1:
                printf("Element to be added to the front:");
                scanf("%d", &data);
                enqueueAtFront(data);
                break;

            case 2:
                printf("Element to be added to the rear:");
                scanf("%d", &data);
                enqueueAtRear(data);
                break;

            case 3:
                dequeueAtFront();
                break;

            case 4:
                dequeueAtRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid option!!! Try again.\n");
                break;
        }
    }
}

