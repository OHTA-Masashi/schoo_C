#include <stdio.h>
#include <string.h>

// 関数の記入
// void countdown(void)
// {
//     printf("カウントダウンします\n");
//     for (int i=5; i>=0; i--)
//     {
//         printf("%d\n", i);
//     }
// }

// void func_b(void)
// {
//     printf("func_bが呼び出されました\n");
//     countdown();
// }

// void countdown(int start, int end)
// {
//     printf("関数が受け取った値: %d,%d\n", start, end);
//     printf("カウントダウンします\n");
//     for (int i=start; i>=end; i--)
//     {
//         printf("%d\n", i);
//     }
// }

// void func(int i)
// {
//     i++;
// }

// double circle_area(double r)
// {
//     return r*r*3.14159;
// }

// void func(int *p)
// {
//     *p = 100;
// }

// void swap(int *a, int *b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// 型の追加
typedef struct Person
{
    char name[16];
    int age;
    struct Person *mother; //母親のアドレスを格納
} Person;

void func(Person *p)//年齢を変えたくなければconst Person
{
    printf("func の中\n");
    printf("%s, %d\n", p->name, p->age);// printf("%s, %d\n", (*p).name, (*p).age);と同じ

    p->age++;//(*p).age++;
}


// main関数
int main(void)
{
    // 第1講
    // //printf("Hello World!\n");
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("今年は西暦%d年です\n", 2022);
    // }
    
    // 第２講
    // int i=12;
    // double d = 2.34;
    // char c = 'A';
    // printf("%d %f %c\n", i, d, c);

    // int i;
    // printf("整数を入力\n");
    // scanf("%d", &i);
    // printf("%d が入力されました\n", i);

    // 第３講
    // int age =13;
    // if(age<4)
    // {
    //     printf("無料");
    // }
    // else if(age<13)
    // {
    //     printf("子供料金");
    // }
    // else
    // {
    //     printf("大人料金");
    // }

    // int score=100;
    // switch(score)
    // {
    //     case 1:
    //         printf("もっと頑張りましょう");
    //         break;
    //     case 2:
    //         printf("もう少し頑張りましょう");
    //         break;
    //     case 3:
    //         printf("普通です");
    //         break;
    //     case 4:
    //         printf("よくできました");
    //         break;
    //     case 5:
    //         printf("大変よくできました");
    //         break;
    //     default:
    //         printf("想定外です");

    // }

    // int c=(a>b)?a:b;   //参考演算子

    // int age=100;
    // if (age<=13||age>75)
    // {
    //     printf("こんにちは");
    // }
    
    // int sum=0;
    // for (int i=1; i<=100; i++)
    // {
    //     sum +=i;
    //     printf("%dを加える\n", i);
    //     printf("現在の合計は%d\n", sum);
    // }

    // int i=0;
    // while(i<5)
    // {
    //     printf("こんにちは\n");
    //     i++;
    // }
    // do
    // {
    //     printf("こんにちは\n");
    //     i++;
    // }while(i<5);
    // for(int i=0; i<3; i++)
    // {
    //     // if(i==22)
    //     // {
    //     //     // break;
    //     //     continue;
    //     // }
    //     // printf("iの値は%d\n", i);
    //     for(int j=0; j<5; j++)
    //     {
    //         printf("i=%d, j=%d\n", i, j);
    //     }
    // }
    // int scores[]={2, 5, 3, 98, 6, 4};
    // int sum=0;
    // for(int i=0; i<6; i++)
    // {
    //     sum+=scores[i];
    //     printf("%d\n", scores[i]);
    // }
    // printf("合計は%d\n", sum);

    // 第４講
    // func_b();
    // countdown(7, 3);
    // countdown(10);

    // int i=10;
    // printf("%d\n", i);
    // func(i);
    // printf("%d\n", i);

    // double d = circle_area(2.5);
    // printf("%f\n", d);

    // 第５講
    // int i = 5;
    // int* p = &i; // ポインタ変数に変数iのアドレスを代入
    // int j = *p;

    // printf("iのアドレス: %p\n", &i);
    // printf("pに入っている値: %p\n", p);
    // printf("iの値: %d\n", i);
    // printf("*pの値: %d\n", *p);
    // printf("jに入っている値: %d\n", j);

    // *p = 10;
    // printf("iの値: %d\n", i);

    // printf("はじめてのiの値: %d\n", i);
    // func(&i);
    // printf("funcを呼び出した後のiの値: %d\n", i);
    
    // int a = 2;
    // int b = 3;
    // printf("a=%d, b=%d\n", a, b);
    // printf("swap関数を呼び出す\n");
    // swap(&a, &b);
    // printf("a=%d, b=%d\n", a, b);

    // int scores[]={10, 20, 30};

    // int *p = scores;
    // int *p = &scores[0]; このようにしても同じ

    // printf("%d\n", *p);
    // p++;
    // printf("%d\n", *p);
    // p++;
    // printf("%d\n", *p);
    // p--;
    // printf("%d\n", *p);

    // 第6講
    // char str[] = "dog, hellow, c, printf";
    //printf("%s\n", str);
    // char str[32];

    // printf("名前を入力してください\n");
    // scanf("%s", str);
    // printf("%sさん、こんにちは\n", str);

    // char str[3][5] = {"dog", "cat", "bird"};
    // for (int i = 0; i<3; i++)
    // {
    //     printf("%s\n", str[i]);
    //     for(int j = 0; j<3; j++)
    //     {
    //         printf("%c\n", str[i][j]);
    //     }
    // }

    // 文字列の代入
    // char str[4];
    // strcpy(str, "dog");
    // printf("%s\n", str);//dog

    // 文字列のコピー，比較
    // char str1[] = "Hellow";
    // char str2[] = "HELLOW";

    // if (strcmp(str1, str2) == 0)
    // {
    //     printf("同じ\n");
    // }else
    // {
    //     printf("違う\n");
    // }// 違う

    //文字列の取得
    // char str[32] = "Hello";
    // int len = strlen(str);
    // printf("%d", len);//5

    //文字列の連結
    // char str[32] = "Hello";
    // strcat(str, " world!");
    // printf("%s", str);//Hello world!

    //文字列への出力
    // char str[32];
    // char name[] = "Taro";
    // sprintf(str,  "Hello %s!", name);
    // printf("%s", str);//Hello Taro

    // struct Person a = {"SUZUKI TARO", 17};
    // struct Person b = {"SATO HANAKO", 19};
    // Person a = {"SUZUKI TARO", 17};
    // Person b = {"SATO HANAKO", 19};


    // printf("%s, %d\n", a.name, a.age);
    // printf("%s, %d\n", b.name, b.age);

    // Person a = {"SUZUKI TARO", 17};
    // func(&a);
    // printf("%s, %d\n", a.name, a.age);

    Person p0 = {"SUZUKI AKIKO", 44, NULL};
    Person p1 = {"SUZUKI TARO", 1, &p0};
    printf("TAROの母親は %s\n", p1.mother->name);
    printf("TAROの母親の年齢は %d\n", p1.mother->age);

    return 0;
}