import cv2
import numpy as np

src = cv2.imread(".png") # 対象画像を読み込む
mask = cv2.imread(".png") # 基準画像を読み込む

height, width, color = src.shape # 幅・高さ・色を取得
dst = np.zeros((height, width, 3), dtype = "uint8") # 合成画像用の変数を作成

for y in range(0, height):
	for x in range(0, width):
		if (mask[y][x] > 240).all(): # 「青・緑・赤」すべてが241以上なら
			dst[y][x] = src[y][x] # 隠れていない部分なので、対象画像の画素を代入
		else:
			dst[y][x] = 0 # 隠れている部分なので、黒にする

while 1:
	cv2.imshow("dst", dst) # 画像を表示
	
	k = cv2.waitKey(1) # キー入力
	if k == ord('q'): # もしQが押されたら終了する
		break
cv2.destroyAllWindows() # 終了処理