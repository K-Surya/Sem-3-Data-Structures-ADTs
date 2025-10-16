#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int a[100];
    int size, top;
};

void init(struct Stack* s, int size){
    s->size = size;
    s->top = -1;
}


int isFull(struct Stack* s){
    if(s->top == s->size-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack* s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack* s, int x){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    } else{
        s->a[++s->top] = x;
    }
}

int pop(struct Stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    } else{
        return s->a[s->top--];
    }
}