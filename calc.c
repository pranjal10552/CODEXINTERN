#include <stdio.h>
#include <stdlib.h>
int add(int a, int b) // addtion function
{
    return a + b;
}
int subtract(int a, int b) // subtraction function
{
    return a - b;
}
int multiply(int a, int b) // multiplication function
{
    return a * b;
}
float divide(int a, int b) // division function
{
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return (float)a / b;
}
int modulus(int a, int b) // modulus function
{
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
        return 0;
    }
    return a % b;
}
int main() 
{
    int choice, num1, num2;
    while (1) {
        // Menu
        printf("\n--- Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        if (choice == 6) // exits if the user wants
        {
            printf("\nExiting calculator!\n");
            break;
        }
        // Input numbers
        printf("Enter two integers: \n");
        if (scanf("%d %d", &num1, &num2) != 2) 
        {
            printf("Invalid input. Please enter integers only.\n"); // handle invalid input
            while (getchar() != '\n');
            continue;
        }
        // Perform operation
        switch (choice) 
        {
            case 1:
                printf("Result: %d\n", add(num1, num2));
                break;
            case 2:
                printf("Result: %d\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result: %d\n", multiply(num1, num2));
                break;
            case 4:
                printf("Result: %.2f\n", divide(num1, num2));
                break;
            case 5:
                printf("Result: %d\n", modulus(num1, num2));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
