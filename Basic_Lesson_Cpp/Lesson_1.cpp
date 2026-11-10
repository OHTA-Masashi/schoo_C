// 第１講
# include <iostream> //iostreamはライブラリ
# include <string>

int main()
{
    // std::cout << "Hello World!"<< std::endl;
    // std::cout << "12345"<< std::endl;
    // std::cout << 100<< std::endl;
    // std::cout << 123.456<< std::endl;
    // std::cout << 10+12<< std::endl;
    // std::cout << 100-10*2<< std::endl;
    // std::cout << (100-10)/2<< std::endl;
    // std::cout << 10.234+12.1345<< std::endl;
    // std::cout << "ABCD"+1234<< std::endl;

    // auto x = 123;
    // x = x+100;
    // auto y = 123.456;
    // // auto z = "Hello";
    // auto z = x+y;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    // std::cout << z << std::endl;

    // auto x = 123;
    // double y = 123.456;
    // std::string z = "Hello";
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    // std::cout << z << std::endl;

    // int x = 123.456;
    // double y = 123;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;

    // int x = "123";//エラーとなる
    // std::string x = 123;//エラーとなる
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;

    // int x[5] = {10, 20, 30, 40, 50};
    // double y[3]= {0.12, 10.23, 20.34};
    // std::string z[2] = {"Hello1", "Hello2"};
    // std::cout << x[2] << std::endl;
    // std::cout << y[0] << std::endl;
    // std::cout << z[1] << std::endl;
    // //std::cout << z[2] << std::endl;//エラーとなる

    // int x{};
    // std::cin >> x;
    // std::cout << x;
    // std::string z{};
    // std::cin >> z;
    // std::cout << z;

    double x{};
    double y{};
    std::cin >> x;
    std::cin >> y;
    double z = x+y;
    std::cout <<z;
}