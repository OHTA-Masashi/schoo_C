import numpy as np

exercise_list = ["running", "walking", "cycling"] # "running", "walking", "cycling" の3つの要素からなるリストを作成し，『exercise_List』という変数に代入

class ExercisePerson():
    def __init__(self, weight):
        self.weight = weight # 引数weightをメンバ変数『self.weight』に代入
    
    def exercise_running(self, minutes):
        calory = 9*self.weight*minutes/60*1.05 # runningの消費カロリーを，体重と運動時間を元に計算し，『calory』という変数に代入
        self.weight -= round(calory / 7200, 2) # 現在の体重から(calory / 7000)の値を引く

    def exercise_walking(self, minutes):
        calory = 3*self.weight*minutes/60*1.05 # walkingの消費カロリーを，体重と運動時間を元に計算し，『calory』という変数に代入
        self.weight -= round(calory / 7200, 2) # 現在の体重から(calory / 7000)の値を引く

    def exercise_cycling(self, minutes):
        calory = 5*self.weight*minutes/60*1.05 # cyclingの消費カロリーを，体重と運動時間を元に計算し，『calory』という変数に代入
        self.weight -= round(calory / 7200, 2) # 現在の体重から(calory / 7000)の値を引く

your_weight_str = input("体重(kg)を数字のみで入力してください．\n") #  ユーザーに任意の文字列を入力してもらい，その結果を『your_weight_str』という変数に代入
your_weight = int(your_weight_str) # your_weight_strを整数型に変形し，『your_weight』という変数に代入

user = ExercisePerson(your_weight) # ExercisePersonクラスオブジェクトを作成し，『user』という変数に代入
print("あなたの体重は現在，{}kgです．".format(user.weight))

print("running/walking/cyclingの中から運動を選択してください．それ以外を入力すると，運動をやめます．\n")
exercise = input()

if exercise not in exercise_list:
    # exerciseの値がexercise_listに含まれない場合は以下を実行
    print("そんな運動は知りません・・・\n")
else:
    if exercise == "running":
        # exerciseの値が"running"だったら以下を実行
        user.exercise_running(600)
    elif exercise == "walking":
        # exerciseの値が"walking"だったら以下を実行
        user.exercise_walking(600)
    else:
        # exerciseの値が"running"でも"walking"でもない場合，以下を実行
        user.exercise_cycling(600)
    
    print("{}を600分間運動しました．".format(exercise))
    print("あなたの体重は現在，{}kgです．".format(user.weight))

# 以下は複数回行う場合
# while True:
#     your_weight_str = input("体重(kg)を数字のみで入力してください．\n")
#     try:
#         your_weight = int(your_weight_str)
#         break
#     except ValueError:
#         # もし入力された文字列が整数型に変換できない場合，以下を実行
#         print("数字じゃないようです．もう一度!")

# user = ExercisePerson(your_weight)
# print("あなたの体重は現在，{}kgです．".format(user.weight))

# while True:
#     print("running/walking/cyclingの中から運動を選択してください．それ以外を入力すると，運動をやめます．\n")
#     exercise = input()

#     if exercise not in exercise_list:
#         # exerciseの値がexercise_listに含まれない場合は以下を実行
#         print("運動を修了します．\n")
#         print("あなたの体重は現在，{}kgです．".format(user.weight))
#         break

#     if exercise == "running":
#         # exerciseの値が"running"だったら以下を実行
#         user.exercise_running(600)
#     elif exercise == "walking":
#         # exerciseの値が"walking"だったら以下を実行
#         user.exercise_walking(600)
#     else:
#         # exerciseの値が"running"でも"walking"でもない場合，以下を実行
#         user.exercise_cycling(600)
    
#     print("{}を600分間運動しました．".format(exercise))
#     print("あなたの体重は現在，{}kgです．".format(user.weight))