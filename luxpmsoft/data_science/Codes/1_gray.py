import cv2
img = cv2.imread(r'../apple_1.png', cv2.IMREAD_REDUCED_COLOR_8)
gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
blue_plane = img[:, :, 0]
green_plane = img[:, :, 1]
red_plane = img[:, :, 2]
cv2.imshow("COLOR_RGB2GRAY", gray_image)
cv2.imwrite("op_1_gray.png", gray_image)
cv2.imshow("blue_plane", blue_plane)
# cv2.imwrite("op_blue_plane.png", blue_plane)
cv2.imshow("green_plane", green_plane)
# cv2.imwrite("op_green_plane.png", green_plane)
cv2.imshow("red_plane", red_plane)
# cv2.imwrite("op_red_plane.png", red_plane)
cv2.waitKey(0)
cv2.destroyAllWindows()