import numpy as np
import cv2
img = cv2.imread("../images.jpg")

rows, cols, dim = img.shape
# shearing in x
# M = np.float32([[1, 0.25, 0],
#              	[0, 1  , 0],
#             	[0, 0  , 1]])
# shearing in y
M = np.float32([[1, 0, 0],
             	[0.25, 1  , 0],
            	[0, 0  , 1]])
transformed_img = cv2.warpPerspective(img,M,(int(cols*1.5),int(rows*1.5)))
cv2.imshow("img",img)
cv2.imshow("translated_img",transformed_img)
cv2.imwrite("transform_in_y_dir_25_per.jpg",transformed_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
