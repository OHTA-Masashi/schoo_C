#include <stdio.h>
#define STACK_SIZE 5

int stack[STACK_SIZE];
int head_index = -1;

void push(int value)
{
    head_index++;
    stack[head_index] = value;
}

int pop()
{
    int value = stack[head_index];
    head_index--;
    return value;
}

int main(void)
{
    push(5);//[5][][][][]
    push(9);//[5][9][][][]
    push(5);//[5][9][3][][]
    printf("pop %d\n", pop());// 3, [5][9][3][][]
    printf("pop %d\n", pop());// 9, [5][9][3][][]
    printf("pop %d\n", pop());// 5, [5][9][3][][]
}