#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "triangle.h"
#define ADDRESS_CHECK

// int a = 10;

// void func(void)
// {
//     a++;
// }

int main(void)
{
    // FILE *fp = NULL;
    // char line[128];

    // fp = fopen("/home/mohta/development_C/scores.txt","r");
    // fp = fopen("/home/mohta/development_C/output.txt","w");
    // if(fp == NULL)
    // {
    //     printf("ファイルを開けませんでした\n");
    //     return 1;
    // }

    // int i;
    // int total = 0;

    // while(fgets(line, 128, fp) != NULL)
    // {
    //     printf(">>> %s", line);
    // }
    // while(fscanf(fp, "%d", &i) != EOF)
    // {
    //     printf("%dを読み込みました\n", i);
    //     total +=i;
    // }

    // for (int i = 0; i<10; i++)
    // {
    //     fprintf(fp, "[%d]\n", i);
    // }

    // // printf("合計は%d\n", total);
    // fclose(fp);

    // func();
    // printf("%d\n", a);

    // double area = triangle_area(5, 8);
    // printf("area=%f\n", area);

//     int a = 9;

// #ifdef ADDRESS_CHECK
//     printf("aのアドレスは%p\n", &a);
// #endif

//     printf("aの値%d\n", a);
    
    enum Size {S, M, L, XL};
    enum Size a = M;

    if (a == M)
    {
        printf("サイズはMです\n");
    }

    return 0;
}