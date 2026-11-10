// 第３講
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

double exerciseRunning(double weight, double exerciseTime)
{
    return 9*weight*exerciseTime*1.05/60;
}
double exerciseWalking(double weight, double exerciseTime)
{
    return 3*weight*exerciseTime*1.05/60;
}
double exerciseCycling(double weight, double exerciseTime)
{
    return 5*weight*exerciseTime*1.05/60;
}

class Exercise
{
    public://public.で取り出し可能
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
// class ExercisePerson_
// {
//     private:
//     double m_weight;
//     std::string m_exerciseType;

//     public:
//     ExercisePerson_(double weight, std::string exerciseType)
//     {
//         m_weight = weight;
//         m_exerciseType = exerciseType;
//     }
//     double exercise(double weight, double exerciseTime)
//     {
//         double calory;
//         if(m_exerciseType == "running")
//         {
//             calory = exerciseRunning(weight, exerciseTime);
//         }
//         else if(m_exerciseType == "walking")
//         {
//             calory = exerciseWalking(weight, exerciseTime);
//         }
//         else if(m_exerciseType == "cycling")
//         {
//             calory = exerciseCycling(weight, exerciseTime);
//         }
//         else
//         {
//             return 0;
//         }

//         m_weight = m_weight - calory/7200;
//         return m_weight;
//     }

//     private:
//     double exerciseRunning(double weight, double exerciseTime)
//     {
//         return 9*weight*exerciseTime*1.05/60;
//     }
//     double exerciseWalking(double weight, double exerciseTime)
//     {
//         return 3*weight*exerciseTime*1.05/60;
//     }
//     double exerciseCycling(double weight, double exerciseTime)
//     {
//         return 5*weight*exerciseTime*1.05/60;
//     }
// };

// int main()
// {
//     std::string exerciseType {};
//     double weight {};
//     double exerciseTime {};
//     double calory;

//     std::cout << "running/walking/cyclingの中で、あなたの運動のタイプを入力してください" << std::endl;
//     std::cin >> exerciseType;

//     if ((exerciseType !="runnning") and (exerciseType !="walking") and (exerciseType !="cycling"))
//     {
//         std::cout << "running/walking/cyclingの中から選ばれなかったので終了します。" << std::endl;
//         return 0;
//     }

//     std::cout << "体重を入力してください" << std::endl;
//     std::cin >> weight;
//     std::cout << "運動時間(分)を入力してください" << std::endl;
//     std::cin >> exerciseTime;

//     std::unique_ptr<ExercisePerson_> person1;
//     person1 = std::make_unique<ExercisePerson_>(weight, exerciseType);

//     double weightExercised = person1->exercise(weight, exerciseTime);

//     std::cout << "運動後の体重は" << weightExercised << std::endl;
//     return 0;
// }