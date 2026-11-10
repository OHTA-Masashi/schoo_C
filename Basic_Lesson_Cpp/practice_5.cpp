// 第５講
# include <iostream> //iostreamはライブラリ
# include <string>
# include <memory>

class Person
{
    protected:
    double m_weight;

    public:
    Person(int number, double weight)
    {
        m_weight = weight;
    }

    double weight(){return m_weight;}
    //virtualをつけることで，子クラスの関数を呼び出せるようになる
    virtual double exercise(double exciseTime){return 0.0;};
};

class RunningPerson : public Person
{
    using Person::Person;
    protected:
    int exercisenumber;
    public:
    double exercise(int exercisenumber, double exerciseTime)
    {
        for(int i = 0; i < exercisenumber; i++)
        {
            std::cout << "運動時間(分)を入力してください" << std::endl;
            double exerciseTime {};
            std::cin >> exerciseTime;
            
            double weightExcised = exercise(exerciseTime);

            
            std::cout << "運動後の体重は " << weightExcised << " kgです。" << std::endl;
        }
        double calory = 9 * m_weight * exerciseTime * 1.05 / 60;
        m_weight = m_weight - (calory / 7200);
        return m_weight;
    }
};

class WalkingPerson : public Person
{
    using Person::Person;
    public:
    double exercise(double exerciseTime)
    {
        double calory = 3 * m_weight * exerciseTime * 1.05 / 60;
        m_weight = m_weight - (calory / 7200);
        return m_weight;
    }
};

class CyclingPerson : public Person
{
    using Person::Person;
    public:
    double exercise(double exerciseTime)
    {
        double calory = 5 * m_weight * exerciseTime * 1.05 / 60;
        m_weight = m_weight - (calory / 7200);
        return m_weight;
    }
};

int main()
{
    std::string exerciseType {};
    double weight {};
    int exercisenumber {};

    std::cout << "running/walking/cyclingの中で、あなたの運動のタイプを入力してください" << std::endl;
    std::cin >> exerciseType;
    std::cout << "体重を入力してください" << std::endl;
    std::cin >> weight;
    std::cout << "運動回数を入力してください" << std::endl;
    std::cin >> exercisenumber;

    std::unique_ptr<Person> person;
    if(exerciseType == "running")
    {
        person = std::make_unique<RunningPerson>(weight);
    }
    else if(exerciseType == "walking")
    {
        person = std::make_unique<WalkingPerson>(weight);
    }
    else if(exerciseType == "cycling")
    {
        person = std::make_unique<CyclingPerson>(weight);
    }


    double weightExcised = person->exercise(exerciseTime);
    std::cout << "運動前の体重は " << weight << " kgです。" << std::endl;
    std::cout << "運動後の体重は " << weightExcised << " kgです。" << std::endl;

    return 0;
}


//解答例
// #include <iostream>
// # include <string>
// # include <memory>//unique_ptrを使うにはこれをincludeしないとダメ
// # include <vector>//vectorを使うために必要

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
//     int count {};

//     std::cout << "running/walking/cyclingの中で、あなたの運動のタイプを入力してください" << std::endl;
//     std::cin >> exerciseType;
//     std::cout << "体重を入力してください" << std::endl;
//     std::cin >> weight;
//     std::cout << "運動時間(分)を入力してください" << std::endl;
//     std::cin >> exerciseTime;
//     std::cout << "何回運動するかを入力してください" << std::endl;
//     std::cin >> count;

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
//     else
//     {
//         std::cout << "running/walking/cyclingの中から選ばれなかったので終了します。" << std::endl;
//         return 0;
//     }

//     std::vector<double> weightList;
//     for (int i = 0; i < count; ++i) 
//     {
//         double bmi = person->exercise(exerciseTime);
//         weightList.push_back(bmi);
//     }
    
//     std::cout << "体重の推移: ";
//     try
//     {
//         std::cout << weightList.at(0) << ", " <<weightList.at(weightList.size() - 1);
//     }
//     catch(...)
//     {
//         std::cerr << "エラーが発生しました: " << std::endl;
//         return 0;
//     }

//     return 0;
// }