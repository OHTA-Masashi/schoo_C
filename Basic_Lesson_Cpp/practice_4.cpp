// 第４講
# include <iostream> //iostreamはライブラリ
# include <string>
# include <memory>

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

//親クラスを定義
class Exercise
{
    protected:
    double m_weight;
    double m_calory;

    public:
    Exercise(double weight, double calory)//class名と同じコンソラクター
    {
        m_weight = weight;
        m_calory = calory;
    }
    double exercise()
    {
        m_weight = m_weight - (m_calory/7200);
        return m_weight;
    }

    //virtualをつけることで，子クラスの関数を呼び出せるようになる
    virtual double exercise(){return 0.0;};
};


//子クラスを定義
class Running : public Exercise
{
    public:
    Running(double weight, double calory) : Exercise(weight, calory) {}
    double exercise() override
    {
        return 9 * m_weight * m_calory * 1.05 / 60;
    }
};

class Walking : public Exercise
{
    public:
    Walking(double weight, double calory) : Exercise(weight, calory) {}
    double exercise() override
    {
        return 3 * m_weight * m_calory * 1.05 / 60;
    }
};

class Cycling : public Exercise
{
    public:
    Cycling(double weight, double calory) : Exercise(weight, calory) {}
    double exercise() override
    {
        return 5 * m_weight * m_calory * 1.05 / 60;
    }
};

int main()
{
    std::string exerciseType {};
    double weight {};
    double exerciseTime {};
    double calory;

    std::cout << "running/walking/cyclingの中で、あなたの運動のタイプを入力してください" << std::endl;
    std::cin >> exerciseType;
    std::cout << "体重を入力してください" << std::endl;
    std::cin >> weight;
    std::cout << "運動時間(分)を入力してください" << std::endl;
    std::cin >> exerciseTime;

    if(exerciseType == "running")
    {
        calory = exerciseRunning(weight, exerciseTime);
    }
    else if(exerciseType == "walking")
    {
        calory = exerciseWalking(weight, exerciseTime);
    }
    else if(exerciseType == "cycling")
    {
        calory = exerciseCycling(weight, exerciseTime);
    }
    else
    {
        std::cout << "running/walking/cyclingの中から選ばれなかったので終了します。" << std::endl;
        return 0;
    }

    std::cout << "消費カロリーは " << calory << std::endl;

    std::unique_ptr<Exercise> Exercise1;
    print(Exercise1->m_weight);
    double b = Exercise1->exercise();
    print(b);

    return 0;
}


//解答例
// #include <iostream>
// # include <string>
// # include <memory>//unique_ptrを使うにはこれをincludeしないとダメ

// class Person
// {
//     protected:
//     double m_weight;

//     public:
//     Person(double weight)
//     {
//         m_weight = weight;
//     }

//     double weight(){return m_weight;}
//     //virtualをつけることで，子クラスの関数を呼び出せるようになる
//     virtual double exercise(double exciseTime){return 0.0;};
// };

// class RunningPerson : public Person
// {
//     using Person::Person;
//     public:
//     double exercise(double exerciseTime)
//     {
//         double calory = 9 * m_weight * exerciseTime * 1.05 / 60;
//         m_weight = m_weight - (calory / 7200);
//         return m_weight;
//     }
// };

// class WalkingPerson : public Person
// {
//     using Person::Person;
//     public:
//     double exercise(double exerciseTime)
//     {
//         double calory = 3 * m_weight * exerciseTime * 1.05 / 60;
//         m_weight = m_weight - (calory / 7200);
//         return m_weight;
//     }
// };

// class CyclingPerson : public Person
// {
//     using Person::Person;
//     public:
//     double exercise(double exerciseTime)
//     {
//         double calory = 5 * m_weight * exerciseTime * 1.05 / 60;
//         m_weight = m_weight - (calory / 7200);
//         return m_weight;
//     }
// };

// int main()
// {
//     std::string exerciseType {};
//     double weight {};
//     double exerciseTime {};

//     std::cout << "running/walking/cyclingの中で、あなたの運動のタイプを入力してください" << std::endl;
//     std::cin >> exerciseType;
//     std::cout << "体重を入力してください" << std::endl;
//     std::cin >> weight;
//     std::cout << "運動時間(分)を入力してください" << std::endl;
//     std::cin >> exerciseTime;

//     std::unique_ptr<Person> person;

//     if(exerciseType == "running")
//     {
//         person = std::make_unique<RunningPerson>(weight);
//     }
//     else if(exerciseType == "walking")
//     {
//         person = std::make_unique<WalkingPerson>(weight);
//     }
//     else if(exerciseType == "cycling")
//     {
//         person = std::make_unique<CyclingPerson>(weight);
//     }

//     double weightExcised = person->exercise(exerciseTime);
//     std::cout << "運動後の体重は " << weightExcised << " kgです。" << std::endl;

//     return 0;
// }