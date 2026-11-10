#include <stdio.h>
#define DATA_NUM 5
int data[] = {7, 2, 6, 9, 4};

void printout()
{
    for (int i = 0; i<DATA_NUM; i++)
    {
        printf("%d", data[i]);
    }
    printf("\n");
}

int main(void)
{
    printout();

    for(int i = 0; i<DATA_NUM-1; i++)
    {
        for(int j = DATA_NUM-1; j>i; j--)
        {
            if(data[j]<data[j-1])
            {
                int tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
                printout();
            }
        }
    }

    printf("---\n");
    printout();
}