#include <stdio.h>
#include <stdlib.h>

// define a LL node
typedef struct Node 
{
    int data;
    struct Node *next;
}Node;

// define custom structure to make stack
typedef struct LinkedStack
{
    Node *top;
}LinkedStack;

// initialise stack
void initLinkedStack(LinkedStack *s) 
{
    s->top = NULL;
}

// check if stack is empty
int isEmpty(LinkedStack *s) 
{
    return s->top == NULL;
}

// push element into stack
void push(LinkedStack *s, int val) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;            // create
    newNode->next = s->top;         // new 
    s->top = newNode;               // node
    printf("%d pushed to Linked Stack\n", val);
}

// pop an element from the stack
void pop(LinkedStack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow (Linked)\n");
        return;
    }
    Node *temp = s->top;
    printf("%d popped from Linked Stack\n", temp->data);
    s->top = temp->next;
    free(temp);
}

// return the top element
void peek(LinkedStack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Linked Stack is empty\n");
        return;
    }
    printf("Top of Linked Stack: %d\n", s->top->data);
}

// display stack elements 
void display(LinkedStack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Linked Stack is empty\n");
        return;
    }
    printf("Linked Stack elements: ");
    Node *temp = s->top;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// driver main function
int main() {
    int choice, val;
    LinkedStack stack;
    initLinkedStack(&stack);

    while (1) 
    {
        printf("\n--- Linked List Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek/Top\n4. Display\n5. Exit\n");
        printf("Enter choice(1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value: ");
                scanf("%d", &val);
                push(&stack, val);
                break;
            case 2: 
                pop(&stack);
                break;
            case 3: 
                peek(&stack);
                break;
            case 4: 
                display(&stack);
                break;
            case 5: 
                printf("Exiting.\n");
                return 0;
            default: 
                printf("Invalid choice. \nTry again.\n");
        }
    }
}
