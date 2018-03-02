#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack{
    char data[MAX];
    int top;
} stack;

int isEmpty(stack *s){
    if(s->top==-1)                     // Problem 9-1 
        return 1;
    else 
        return 0; 
}

int isFull(stack *s){
    if(s->top==MAX)                    // Problem 9-2 
        return 1;
    else 
        return 0;
}

void push(stack *s, char ch){
    s-> top++;
    s-> data[s->top] = ch;
}

char pop(stack *s){
    char ch;
    ch = s-> data[s->top];             // Problem 9-3
    s-> top--;
    return ch;
}

void reserveString(stack *s){
    char ch;
    printf("Reversed String: \n");
    while(!isEmpty(s)){                // Problem 9-4
        ch = pop(s);                   // Problem 9-5
        printf("%c", ch);
    }
    printf("\n");
}

int main(void){
    stack s;
    char str[MAX];
    s.top = -1; // initialize the top variable
    int i;
    puts("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    /* original code
    printf("Enter a string: ");
    gets(str);
    */
    /* push the characters of the string into the stack */
    for(i=0;str[i]!='\n';i++){
        if(!isFull(&s))
            push(&s, str[i]);         // Problem 9-6
        else
            printf("The stack is full.\n");
    }
    /* pop the characters of the string from the stack */
    reserveString(&s);
    return 0;
}
