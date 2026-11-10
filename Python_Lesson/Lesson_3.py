import numpy as np

class ExercisePerson():
    def __init__(self, name, weight):
        print("初期化メソッドが実行されました")
        self.name = name # nameという情報を持つクラス
        self.weight = weight # nameという情報を追加
    
    # 実行すると体重を-1するメソッドを追加
    def exercise(self):
        print(self.name + "さんは運動したので1kg体重が減りました")
        self.weight -= 1

    # 実行すると体重を+1するメソッドを追加
    def eat(self):
        print(self.name + "さんは食事したので1kg体重が増えました")
        self.weight += 1

person1 = ExercisePerson("Ken", 100)
person2 = ExercisePerson("Emi", 50)

print(person1.name)
print(person1.weight)
print(person2.name)
print(person2.weight)

person1.exercise()
person2.eat()

print(person1.name)
print(person1.weight)
print(person2.name)
print(person2.weight)