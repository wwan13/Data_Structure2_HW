
#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

#define  MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
}StackType;

void stack_init(StackType *s) {
    s->top = -1;
}

int stack_is_empty(StackType *s) {
    return (s->top==-1);
}

int stack_is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, int item) {
    if(stack_is_full(s)) {
        printf("스택 포화");
        exit(1);
    }
    else {
        s->stack[++(s->top)] = item;
    }
}

int pop(StackType *s) {
    if(stack_is_empty(s)) {
        printf("스택 공백");
        exit(1);
    }
    else {
        return s->stack[(s->top)--];
    }
}


#endif
