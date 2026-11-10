import numpy as np

a = 20
a_list = [10, 20, 30, 40,50]

# リスト内の値の取り出し
print(a_list[0:2])
# 下のようにも書けるっぽい
# L=[str(b) for b in a_list]
# L=" ".join(L)
# print(L)

# 文字列のリストの作成
str_list = ['Hellow', 'こんにちは！', 'OKOKOKOK!']
print(str_list[0])

# 合計値などの計算
print(sum(a_list))
print(min(a_list))

# 値の変更
num_list = [10, 20, 30, 40,50]
print(num_list[2])
num_list[2] = 100
print(num_list[0:4])

# 辞書(keyとvalueをセットにしたデータ構造)
# 'a'がkey, 20がvalue
# 'b'がkey, 30がvalue
# 'c'がkey, 15がvalue
tmp_dict = {'a':20, 'b':30, 'c':15}
tmp_list = [20, 30, 15]

print(tmp_list[0], tmp_dict['a'])# リストからもkeyからも表示できる

# タプル(リストと違い要素の変更不可)
num_list = [0, 1, 8, 12]
num_tuple = (0, 1, 8, 12)
# num_tuple[2]=100などするとエラーになる
print(num_list, num_tuple)

# for
num_list = [0, 1, 2, 3, 4, 5, 6]
for a in num_list:
    print(a)
    b = a+30
    print("b=",b)

# 条件分岐
print(3>2)#True
print(10>4)#False
a = 100
b = 200
print(a>b)#False

if a>50:# a>50が正しければ，以下の処理を実行
    print('50よりも大きい')
else:# a>50が正しくなければ，以下の処理を実行
    print('50以下')

# if~elif~else
a = 30
if a>50:# a>50が正しければ，以下の処理を実行
    print('50よりも大きい')
elif a>30:# a>50はFalseだが，a>30はTrueのときに以下の処理を実行
    print('30よりも大きく50以下')
else:# a>50が正しくなければ，以下の処理を実行
    print('50以下')

# while(条件式が真のときに実行する何らかの処理)
num = 1
while num<10:
    print(num)
    num = num+1

    if num == 5:#numが5になった際に処理を中断する
        break

# 関数
def is_bigger_50(number):#ある値numberが50よりも大きいか表示してくれる関数
    if number > 50:
        print('50よりも大きい')
    else:
        print('50以下')

is_bigger_50(30)

def calories_walking(weight, minutes):
    return 3*weight*minutes/60*1.05

print(calories_walking(60, 30))
colorie = calories_walking(50, 15)
print(colorie)