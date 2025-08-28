#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue* create_queue();
struct queue* insert(struct queue*, int);
struct queue* delete_element(struct queue*);
struct queue* display(struct queue*);
int peek(struct queue*);

int main() {
    int val, option;
    struct queue *q = create_queue();  // Initialize the queue properly

    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the number to insert in the queue: ");
                scanf("%d", &val);
                q = insert(q, val);
                break;
            case 2:
                q = delete_element(q);
                break;
            case 3:
                val = peek(q);
                if (val != -1)
                    printf("\nThe value at the front of the queue is: %d", val);
                break;
            case 4:
                q = display(q);
                break;
            case 5:
                printf("\nExiting program.");
                break;
            default:
                printf("\nInvalid option.");
        }
    } while (option != 5);

    return 0;
}

struct queue* create_queue() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

struct queue* insert(struct queue *q, int val) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL) {
        q->front = ptr;
        q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    return q;
}

struct queue* delete_element(struct queue *q) {
    struct node *ptr;

    if (q->front == NULL) {
        printf("\nUNDERFLOW");
    } else {
        ptr = q->front;
        q->front = q->front->next;
        printf("\nThe value being deleted is: %d", ptr->data);
        free(ptr);

        if (q->front == NULL) {
            q->rear = NULL;  // Queue becomes empty
        }
    }

    return q;
}

struct queue* display(struct queue *q) {
    struct node *ptr = q->front;

    if (ptr == NULL) {
        printf("\nQUEUE IS EMPTY");
    } else {
        printf("\nQueue elements: ");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }

    return q;
}

int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("\nQUEUE IS EMPTY");
        return -1;
    } else {
        return q->front->data;
    }
}

