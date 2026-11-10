#include <stdio.h>

typedef struct Node
{
    char str[256];
    struct Node *next;
}Node;

Node *head = NULL;

void printout(void)
{
    Node *node = head;
    while (node != NULL)
    {
        printf("[%s]", node->str);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    Node n0 = {"This", NULL};
    Node n1 = {"is", NULL};
    Node n2 = {"a", NULL};
    Node n3 = {"cat", NULL};
    head = &n0;
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    printout();
    Node new_node = { "not", &n2};
    n1.next = &new_node;
    printout();
}