# mathモジュールの読み込み
import math
import numpy as np # 数値計算用ライブラリ
import pandas as pd # データの前処理用ライブラリ

# 10の兵宝庫運を表示
print(math.sqrt(10))

# 使用できる関数を調べる
# help(math)

# 別名の「mm」を使う
import math as mm
print(mm.sqrt(10))

import random
# 指定範囲でランダムに整数を返す
random.randint(1, 100)
print(random.randint(1, 100))

# 引数の中のリストの中で，ランダムに値を返す
random.choice(["雨", "晴れ", "曇り"])
print(random.choice(["雨", "晴れ", "曇り"]))

# 2次元配列の作り方
# 今回は2行4列の配列を定義
arr2 = np.array([[1, 2, 3, 4], [3, 6, 7, 8]])
print(arr2)
print(arr2.T) # 転置する場合

# csvファイルの読み込み(googleコラボなら)
# df = pd.read_csv("パスを入力")
# print(df)

# # numpyと同様にデータの次元を取得できる
# print(df.shape)

# # データの最初の数行のみ表示
# print(df.head())

# # longitudeを抽出
# print(df['longtude'])

# # indexが2の行以降(3行目以降)の抽出
# print(df.iloc[2:5])
# print(df.iloc[2:5, 1:4])

# # describe()を使用することで，各カラムの平均値や標準誤差，四分位数と言った基礎統計量を求めることが可能
# print(df.describe)

# # 2行目以降のデータを，新しいdf2という変数に代入
# df2 = df.iloc[2:,]
# print(df2)

# # csvに保存
# # dfはデータフレーム
# df2.to_csv('filename.csv')

# 可視化ライブラリ
from matplotlib import pyplot as plt
import seaborn as sns
plt.style.use('ggplot')
%matplotlib inline

from sklearn.datasets import load_iris
import pandas as pd

# seaborn
iris = load_iris()

df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['target'] = iris.target

print(df)

# 散布図
# seabornではjoinplot
sns.joinplot('sepal length(cm)', 'petal length(cm)', data=df)

# ヒストグラム
# seabornではdistplot
sns.distplot(df['sepal lengt(cm)'])

# 折れ線グラフ
x = [1, 2, 3, 4]
y = [2, 5, 7, 9]
# seabornではlineplot()
sns.lineplot(x, y)

# 箱ひげ図
sns.boxplot(x= 'target', y= 'sepal length (cm)', data=df)

# 相関行列を作製
corr = df.corr()
# ヒートマップ
sns.heatmap(corr)

# pairplot()を使うと，全変数間の散布図を可視化できる
# hueでしたカテゴリごとに色分けも可能
sns.pairplot(df, hue = 'target')

import plotly
import plotly.graph_objs as go
# Google ColabやJupyter Labでプロットするためには，以下を実行する．
import plotly.io as pio
pio.renderers.default = "colab"

df = pd.read_csv("/content/sample_data/california_housing_train.csv")
df = df.iloc[0:200, :] # 最初の200行を取得
df.head()

# 散布図
plot_data = go.Scatter(x=df["median_income"], y=df["median_house_value"], mode = 'markers',) # plotlyの某グラフ用データを生成，縦軸には都道府県情報・横軸にはtar
fig = go.Figure(plot_data) # plot_dataを元にグラフを作成
fig.show()

# 棒グラフ
plot_data = go.Bar(y=df["median_house_value"]) # plotlyの某グラフ用データを生成，縦軸には都道府県情報・横軸にはtar
fig = go.Figure(plot_data) # plot_dataを元にグラフを作成
fig.show()

# 折れ線グラフ
plot_data1 = go.Scatter(x=df["median_house_value"], mode = 'lines', name = 'house_value') # plotlyの某グラフ用データを生成，縦軸には都道府県情報・横軸にはtar
# plot_data2 = go.Scatter(x=df["median_house_value"], mode = 'lines', name = 'house_age')

fig = go.Figure(plot_data1)
# fig = go.Figure([plot_data1, plot_data2])
fig.show()