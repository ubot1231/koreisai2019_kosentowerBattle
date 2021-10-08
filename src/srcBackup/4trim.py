# Reference
# https://teratail.com/questions/167483`

import cv2
import matplotlib.pyplot as plt
import numpy as np

img = cv2.imread('/Users/uboT/Desktop/opencv4Ko/img/photo.png')

h, w = img.shape[:2]
mask = np.zeros((h + 2, w + 2), dtype=np.uint8)

flags = 4 | 255 << 8 | cv2.FLOODFILL_MASK_ONLY
print(bin(flags))
# 緑は（0，128，0)
cv2.floodFill(
    img, mask, seedPoint=(2, 2), newVal=(0, 0, 255),
    loDiff=(10, 10, 10), upDiff=(10, 10, 10), flags=flags)

RGBA = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)
mask = mask[1:-1, 1:-1]
RGBA[mask==255] = 0

cv2.imwrite('/Users/uboT/Desktop/opencv4Ko/img/readwrite.png', RGBA)