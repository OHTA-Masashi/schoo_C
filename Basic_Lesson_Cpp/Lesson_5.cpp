// 第５講
# include <iostream>
# include <string>
# include <map>//mapを使うために必要
# include <vector>//vectorを使うために必要

int main()
{
    //std::vector
    std::vector<int>x;//vectorは配列のようなもの
    x.push_back(20);
    x.push_back(10);
    x.push_back(30);
    x.push_back(100);
    std::cout << x.at(0) << std::endl;//各要素にはx.at(要素番号)でアクセスできる
    //std::cout << x.at(4) << std::endl;//存在しない要素にアクセスするとエラーになる

    int length = x.size();
    for(int i = 0; i < length; i++)
    {
        std::cout << x.at(i) << std::endl;//各要素にはx.at(要素番号)でアクセスできる
    }


    //エラー処理
    try
    {
        std::cout << x.at(2) << std::endl;
        std::cout << x.at(4) << std::endl;
    }
    catch(...)
    {
        std::cerr << "エラーが発生しました: " << std::endl;
    }


    std::vector<std::string>y;
    y.push_back("aaa");
    y.push_back("bbb");
    y.push_back("300.1234");
    for(size_t i = 0; i < y.size(); i++)
    {
        std::cout << y.at(i) << std::endl;
    }


    std::vector<std::vector<int>>z;
    std::vector<int>tmp1={0,1,2};
    std::vector<int>tmp2={10,20};
    std::vector<int>tmp3={-1, -2, -3};

    z.push_back(tmp1);
    z.push_back(tmp2);
    z.push_back(tmp3);

    std::cout << z.at(0).at(2) << std::endl;//z.at(0)はtmp1のこと、tmp1.at(2)は2番目の要素のこと

    for(int i = 0; i < z.size(); i++)
    {
        for(int j = 0; j < z[i].size(); j++)
        {
            std::cout << z.at(i).at(j) << std::endl;
        }
    }


    //std::map
    std::map<std::string, int>score;//キーはstring型、値はint型のmapを作る

    score.insert(std::make_pair("Ken", 96));//{("Ken", 96)}というペアをmapに追加する  
    score.insert(std::make_pair("Emi", 86));
    score.insert(std::make_pair("Tom", 76));

    std::cout << score["Ken"] << std::endl;
    std::cout << score["Emi"] << std::endl;
    std::cout << score["Tom"] << std::endl;


    for(auto w:score)
    {
        std::cout << w.first << std::endl;
        std::cout << w.second << std::endl;
    }


    std::map<int, std::string>score2;//キーはint型、値はstring型のmapを作る
    score2.insert(std::make_pair(1, "AAA"));//{(1, "AAA")}というペアをmapに追加する
    score2.insert(std::make_pair(10, "BBB"));
    score2.insert(std::make_pair(100, "CCC"));

    std::cout << score2[100] << std::endl;
    std::cout << score2[1] << std::endl;
    std::cout << score2[10] << std::endl;
}