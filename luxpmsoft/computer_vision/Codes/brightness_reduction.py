import math

import cv2 as cv
import numpy as np

img = cv.imread(r'../images.jpg')

h, w, c = img.shape
new_img = np.zeros((h, w, 3), dtype = 'uint8')
p = 50
for i in range(0,int(w/2)):
    for theta in range(0,360):
        x = int((w/2) + i * math.cos(theta))
        y = int((h/2) + i * math.sin(theta))
        # print(x,y)
        blue, green, red = img[y][x]
        # intensity = blue/3+green/3+red/3
        new_img.itemset((y, x, 0), int(blue *(1- p/100)))
        new_img.itemset((y, x, 1), int(green *(1- p/100)))
        new_img.itemset((y, x, 2), int(red *(1- p/100)))
    p = p -1
cv.imshow("img",img)
cv.imshow("new_img",new_img)
cv.imwrite("brightness reduction.png", new_img)
cv.waitKey(0)
cv.destroyAllWindows()