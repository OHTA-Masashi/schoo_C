// 第４講
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
// class ExercisePerson
// {
//     // public://public.で取り出し可能
//     // std::string m_name;//メンバ変数を示すためm_を付ける
//     // private://privateは取り出し不可
//     // double m_weight;
//     // public:

//     //カプセル化の場合
//     private:
//     std::string m_name;
//     double m_weight;

    
//     public:
//     ExercisePerson(std::string name, double weight)//class名と同じコンソラクター
//     {
//         m_name = name;
//         m_weight = weight;
//     }
//     double exercise()
//     {
//         m_weight = m_weight-1;
//         return m_weight;
//     }

//     std::string getName()
//     {
//         return m_name;
//     }
// };


//親クラスを定義
class Person
{
    protected:
    std::string m_name;
    double m_height;
    double m_weight;

    public:
    Person(std::string name, double height, double weight)
    {
        m_name = name;
        m_height = height;
        m_weight = weight;
    }

    std::string getName()
    {
        return m_name;
    }

    //virtualをつけることで，子クラスの関数を呼び出せるようになる
    virtual double exercise(){return 0.0;};
};

//子クラスを定義
class ExercisePerson : public Person
{
    using Person::Person;//親クラスのコンストラクタを使う
    public:
    double exercise()
    {
        m_weight = m_weight-1;
        return m_weight;
    }
};

//ポリモーフィズムの例
class RunningPerson : public Person
{
    using Person::Person;
    public:
    double exercise()
    {
        m_weight = m_weight-1.0;
        return m_weight;
    }
};
class WalkingPerson : public Person
{
    using Person::Person;
    public:
    double exercise()
    {
        m_weight = m_weight-0.5;
        return m_weight;
    }
};

int main()
{
    // ExercisePerson person1 = ExercisePerson("Ken", 70);//スタック用メモリを使用
    // ExercisePerson person2 = ExercisePerson("Emi", 50);
    // // print(person1.m_name);
    // // print(person2.m_name);
    // double a = person1.exercise();
    // double b = person2.exercise();

    // print(person1.getName());
    // print(person2.getName());
    // print(a);
    // print(b);

    //子クラスをスマートポインタを用意して，そこに子クラスのメモリを確保
    // std::unique_ptr<ExercisePerson> person1 = std::make_unique<ExercisePerson>("Ken", 170, 60);
    // double a = person1->exercise();
    // print(a);

    // //親クラスのスマートポインタを用意して，そこに子クラスのメモリを確保
    // //std::unique_ptr<Person> person1 = std::make_unique<ExercisePerson>("Ken", 170, 70);
    // std::unique_ptr<Person> person2 = std::make_unique<ExercisePerson>("Emi", 160, 50);
    // //double b = person2->exercise();//取り出せない
    // print(person1->getName());


    std::unique_ptr<RunningPerson> person1 = std::make_unique<RunningPerson>("Ken", 170, 60);
    double c = person1->exercise();
    print(c);
    std::unique_ptr<Person> person2 = std::make_unique<WalkingPerson>("Emi", 160, 50);
    double d = person2->exercise();
    print(d);
}