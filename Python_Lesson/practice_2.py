import numpy as np

# ランニングの消費カロリー
# 体重と運動時間(分数)を与えると結果が戻ってくる
def calories_running(weight, minutes):
    # 9×体重(kg)×運動時間(分)÷60×1.05, 9はランニングの運動強度
    return 9*weight*minutes/60*1.05

# ウォーキングの消費カロリー
# 体重と運動時間(分数)を与えると結果が戻ってくる
def calories_walking(weight, minutes):
    # 3×体重(kg)×運動時間(分)÷60×1.05, 3はウォーキングの運動強度
    return 3*weight*minutes/60*1.05

# 自転車の消費カロリー
# 体重と運動時間(分数)を与えると結果が戻ってくる
def calories_cycling(weight, minutes):
    # 5×体重(kg)×運動時間(分)÷60×1.05, 5は自転車の運動強度
    return 5*weight*minutes/60*1.05

exercise_list = ["running", "walking", "cycling"] # "running", "walking", "cycling" の3つの要素からなるリストを作成し，『exercise_List』という変数に代入
exercise = input("running/walking/cyclingの中から運動を選択してください\n") # ユーザーに任意の文字列を入力してもらい，その結果を『exercise』という変数に代入

if exercise not in exercise_list:
    # exerciseの値がexercise_listに含まれない場合は以下を実行
    print("そんな運動は知りません・・・\n")
else:
    # exerciseの値がexercise_listに含まれない場合は以下を実行
    weight_input = int(input("体重(kg)を数字のみで入力してください．\n")) # ユーザーに任意の文字列を入力してもらい，その結果を整数型に変換し『weight_input』と
    minutes_input = int(input("運動時間(分)を数字のみで入力してください．\n")) # ユーザーに任意の文字列を入力してもらい，その結果を整数型に変換し

    if exercise == "running":
        # exerciseの値が"running"だったら以下を実行
        calory = calories_running(weight_input, minutes_input)
    elif exercise == "walking":
        # exerciseの値が"walking"だったら以下を実行
        calory = calories_walking(weight_input, minutes_input)
    else:
        # exerciseの値が"running"でも"walking"でもない場合，以下を実行
        calory = calories_cycling(weight_input, minutes_input)
    
    print("あなたの消費カロリーは，{}kcalです．\n".format(calory))