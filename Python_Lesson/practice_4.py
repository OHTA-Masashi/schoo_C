# ライブラリのimport
import matplotlib.pyplot as plt
import japanize_matplotlib
import plotly
import plotly.graph_objs as go
# Google ColabやJupyter Lab.でプロットするためには，以下を実行する
import plotly.io as pio
pio.renderers.default = "colab"
import pandas as pd

# このページの表を全て取得します．
weather_url = "https://www.data.jma.go.jp/obd/stats/data/mdrr/synopday/datals.html" # URL文字列を『weather_url』に代入
df_list = pd.read_html(weather_url) # pandasのread_html()を実行し，weather_urlにある表データを全て取得し，『df_list』という変数に代入

while True:
    target_id = input("1~5の中で数字を選んでください．") # ユーザーに任意sの数字を入力してもらい，その結果を『target_id』という変数に代入
    if target_id in ["1", "2", "3", "4", "5"]:
        break

    # 入力された文字が1~5の数字でない場合以下を実行
    print("1~5の中で数字ではないようです．")

df = df_list[int(target_id)] # target_id番目の表を『df』という変数に代入

col_name_list = ["気圧", "最高気温", "最低気温", "湿度"] # "気圧", "最高気温", "最低気温", "湿度"という文字列のリストを『col_name_list』という変数に代入
col_list = [3, 6, 8, 12]

df.index = df.iloc[:, 0] # dfの0列目(一番左の列)を取得し，DataFrameのindexに指定
target_df = df.iloc[3:, col_list] # dfのcol_list列データを取得し，『target_df』という変数に代入
target_df.columns = col_name_list # target_dfの列名をcol_name_listに指定

for col in col_name_list:
    target_df[col] = target_df[col].str.strip(')]') #target_ifに含まれる不要な文字列を削除

target_df = target_df.astype('float') # target_dfのデータを数値型に変換
file_name = input("ファイル名を入力してください．") # ユーザーに任意の文字列を入力してもらい，その結果を『file_name』という変数に代入

prefecture_list = target_df.index
target_col = "最高気温"

# 棒グラフを可視化
plot_data = go.Bar(y=prefecture_list, x=target_df.loc[:, target_col], orientation='h') # plotlyの某グラフ用データを生成，縦軸には都道府県情報・横軸にはtar
fig = go.Figure(plot_data) # plot_dataを元にグラフを作成

fig.update_layout(title=target_col, width=700, height=1000) # グラフのタイトルと，フラフの大きさを指定

fig.show() # グラフ描写
target_df.to_csv(file_name + ".csv") # 指定されたfile_nameで取得したデータをCSV保存