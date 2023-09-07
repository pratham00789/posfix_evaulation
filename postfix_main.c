#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postfix_evel.c"


int main() {
    char expression[100];
    int result;

    while (1) {
        printf("Menu:\n");
        printf("1. Evaluate postfix expression\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf(" %[^\n]s", expression);
                result = evaluatePostfix(expression);
                printf("Result: %d\n", result);
                break;
            case 2:
                printf("Exiting program......\n");
                printf(".......................................................\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                printf(".......................................................\n");

                break;
        }
        
    }

    return 0;
}