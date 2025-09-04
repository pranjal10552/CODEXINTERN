#include <stdio.h>
#include <stdlib.h>

// defining custom structure to stimulate stack
typedef struct 
{
    int *arr;
    int top;
    int capacity;
}ArrayStack;

// initialising stack
void initArrayStack(ArrayStack *s, int capacity) 
{
    s->capacity = capacity;
    s->arr = (int *)malloc(capacity * sizeof(int));
    s->top = -1;
}

// check if stack is full
int isFull(ArrayStack *s) 
{
    return s->top == s->capacity - 1;
}

// check if stack is empty
int isEmpty(ArrayStack *s) 
{
    return s->top == -1;
}

// push value into stack
void push(ArrayStack *s, int val) 
{
    if (isFull(s)) 
    {
        printf("Stack Overflow (Array)\n");
        return;
    }
    s->arr[++s->top] = val;
    printf("%d pushed to Array Stack\n", val);
}

// pop a value from stack
void pop(ArrayStack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow (Array)\n");
        return;
    }
    printf("%d popped from Array Stack\n", s->arr[s->top--]);
}

// return top element of stack
void peek(ArrayStack *s) 
{
    if (isEmpty(s)) {
        printf("Array Stack is empty\n");
        return;
    }
    printf("Top of Array Stack: %d\n", s->arr[s->top]);
}

// display the stack
void display(ArrayStack *s) 
{
    if (isEmpty(s)) // check underflow
    {
        printf("Array Stack is empty\n");
        return;
    }
    printf("Array Stack elements: ");
    for (int i = 0; i <= s->top; i++)
    printf("%d ", s->arr[i]);       // print stack elements
    printf("\n");
}

// driver main function
int main() 
{
    int choice, val, capacity;
    ArrayStack stack;

    printf("Enter capacity of Array Stack: ");
    scanf("%d", &capacity);
    initArrayStack(&stack, capacity);

    while (1) 
    {
        printf("\n--- Array Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek/Top\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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
                free(stack.arr);
                printf("Exiting.\n");
                return 0;
            default: 
                printf("Invalid choice. Try again.\n");
        }
    }
}
