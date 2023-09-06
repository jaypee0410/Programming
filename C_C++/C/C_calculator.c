#include <stdio.h>

int main() {
    int option, num1, num2, result;

    do {
        // Print the menu options
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Addition
                printf("\nEnter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
				break;
            case 2:
                // Subtraction
                printf("\nEnter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
            case 3:
                // Multiplication
                printf("\nEnter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
            case 4:
			    // Division
			    printf("\nEnter first number: ");
			    scanf("%d", &num1);
			    printf("Enter second number: ");
			    scanf("%d", &num2);
			    if (num2 == 0) {
			        printf("Error: division by zero\n");
			    } 
				else {
			        float result = (float) num1 / num2;
			        printf("Result: %.2f\n", result);
			    }
			    break;
            case 0:
                // Exit
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option\n");
                break;
        }

    } while (option != 0);

    return 0;
}

