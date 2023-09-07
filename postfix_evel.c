#include "stack.c"

int evaluatePostfix(char* exp) {
 
    struct Stack* stack = createStack(strlen(exp));
    int i;

   
    if (!stack)
        return -1;

   
    for (i = 0; exp[i]; ++i) {
  
        if (exp[i] == ' ')
            continue;

        else if (isdigit(exp[i])) {
            int num = 0;


            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            push(stack, num);
        }

        else {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (exp[i]) {
                case '+':
                    push(stack, val2 + val1);
                    break;
                case '-':
                    push(stack, val2 - val1);
                    break;
                case '*':
                    push(stack, val2 * val1);
                    break;
                case '/':
                    push(stack, val2 / val1);
                    break;
            }
        }
    }

    return pop(stack);
}