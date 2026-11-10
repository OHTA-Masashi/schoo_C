// 第３講
# include <iostream> //iostreamはライブラリ
# include <string>
# include <memory>//unique_ptrを使うにはこれをincludeしないとダメ

//print関数を定義
auto print(int a)
{
    std::cout <<a<< std::endl;
}
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

//classを定義
class ExercisePerson
{
    public://public.で取り出し可能
    std::string m_name;//メンバ変数を示すためm_を付ける
    private://privateは取り出し不可
    double m_weight;
    public:
    ExercisePerson(std::string name, double weight)//class名と同じコンソラクター
    {
        m_name = name;
        m_weight = weight;
    }
    double exercise()
    {
        m_weight = m_weight-1;
        return m_weight;
    }
};

int main()
{
    // ExercisePerson person1 = ExercisePerson("Ken", 70);//スタック用メモリを使用
    // ExercisePerson person2 = ExercisePerson("Emi", 50);
    // print(person1.m_name);
    // print(person2.m_name);
    // //print(person1.m_weight);privateからpublicに移さないと表示できない
    // //print(person2.m_weight);

    // double a = person1.exercise();
    // double b = person2.exercise();
    // print(a);
    // print(b);
    // a = person1.exercise();
    // print(a);
    // a = person1.exercise();
    // print(a);

    //ヒープメモリを用いる
    ExercisePerson *person1 = new ExercisePerson("Ken", 70);//ヒープメモリを使用
    //ExercisePerson *person2 = new ExercisePerson("Emi", 50);
    print(person1->m_name);
    //print(person2->m_name);
    double a = person1->exercise();
    //double b = person2->exercise();
    print(a);
    //print(b);
    delete person1;//メモリ内から削除しないと飽和する
    //delete person2;
    //print(person1->m_name);//delete後にはアクセスできない．

    //スマートポインタ
    std::unique_ptr<ExercisePerson> person2 = std::make_unique<ExercisePerson>("Emi", 50);
    //ExercisePerson person2 = ExercisePerson("Emi", 50);
    print(person2->m_name);
    double b = person2->exercise();
    print(b);
}