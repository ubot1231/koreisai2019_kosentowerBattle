import cv2
import numpy as np

src = cv2.imread(".png") # �Ώۉ摜��ǂݍ���
mask = cv2.imread(".png") # ��摜��ǂݍ���

height, width, color = src.shape # ���E�����E�F���擾
dst = np.zeros((height, width, 3), dtype = "uint8") # �����摜�p�̕ϐ����쐬

for y in range(0, height):
	for x in range(0, width):
		if (mask[y][x] > 240).all(): # �u�E�΁E�ԁv���ׂĂ�241�ȏ�Ȃ�
			dst[y][x] = src[y][x] # �B��Ă��Ȃ������Ȃ̂ŁA�Ώۉ摜�̉�f����
		else:
			dst[y][x] = 0 # �B��Ă��镔���Ȃ̂ŁA���ɂ���

while 1:
	cv2.imshow("dst", dst) # �摜��\��
	
	k = cv2.waitKey(1) # �L�[����
	if k == ord('q'): # ����Q�������ꂽ��I������
		break
cv2.destroyAllWindows() # �I������