// 第２講
# include <iostream> //iostreamはライブラリ
# include <string>

//関数を定義
auto print(int a)
{
    std::cout <<a<< std::endl;
}
//関数のクロスオーバー(同じ名前で型を変える(C++特有))
auto print(double a)
{
    std::cout <<a<< std::endl;
}
auto print(std::string a)
{
    std::cout <<a<< std::endl;
}
auto print(int* a)
{
    std::cout <<a<< std::endl;
}

int add(int a, int b)
{
    return a+b+100;
}

void sumPrint(int a)
{
    a = a+20;
    print(a);
}

//ポインタとメモリ
int sample(int* a)
{
    print(a);
    print(*a);
    *a = *a+20;
    return *a;
}

int sample2(int &a)
{
    print(a);
    a = a+20;
    return a;
}

int main()
{
    // auto x = 100;
    // auto y = 200;
    // if(x<y)
    // {
    //     std::cout << "y" << std::endl;
    // }
    // else
    // {
    //     std::cout << "x" << std::endl;
    // }

    // bool z = x>y;
    // if(z)
    // {
    //     std::cout << "y" << std::endl;
    // }
    
    // //if else文
    // if(x>100)
    // {
    //     std::cout << "100より大きい" << std::endl;
    // }
    // else if(x>50)
    // {
    //     std::cout << "50より大きく100以下" << std::endl;
    // }
    // else
    // {
    //     std::cout << "50以下" << std::endl;
    // }

    //for文
    for (int i = 1; i<12; i=i+1)
    {
        if(i%2==0)
        {
            continue;//次の処理に移る
        }
        std::cout <<i<<"月"<<std::endl;
        if(i==5)
        {
            break;//i=5で離脱
        }
    }
    std::cout <<"処理終了"<<std::endl;

    //関数
    int a = 10;
    std::cout << a << std::endl;
    int b = 20;
    print(b);//関数の呼び出し
    double c = 123.456;
    print(c);

    int x = 10;
    // int y = 20;
    // int z = add(x, y);
    // print(z);
    sumPrint(x);
    print(x);

    //int z = sample(&x);//どっちで書いてもOK
    int z = sample2(x);
    print(z);
    print(x);
}