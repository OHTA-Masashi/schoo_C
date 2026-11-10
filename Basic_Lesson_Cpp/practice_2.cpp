// 第２講
# include <iostream> //iostreamはライブラリ
# include <string>

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

    return 0;
}