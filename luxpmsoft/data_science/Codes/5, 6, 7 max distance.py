import cv2
import math
def solution(img, b_l):
    hls = cv2.cvtColor(img, cv2.COLOR_RGB2HLS)
    hls_s = hls[:, :, 2]
    y, hls_s_th = cv2.threshold(src=hls_s, thresh=45, maxval=255, type=cv2.THRESH_BINARY, dst=None)
    apple_hls_s = cv2.bitwise_and(img, img, mask=hls_s_th)
    d = 0
    p = []
    c, h = cv2.findContours(hls_s_th, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    i = 0
    for cnt in c:
        area = cv2.contourArea(cnt)
        if area > 0:
            idx = i
        i = i+1
    contours = c[i-1]
    for j in range(0, len(contours)):
        for k in range(j, len(contours)):
            if (j != k):
                point1 = contours[j][0]
                point2 = contours[k][0]
                y_square = (point2[1] - point1[1]) * (point2[1] - point1[1])
                x_square = (point2[0] - point1[0]) * (point2[0] - point1[0])
                y_square_plus_x_square = y_square + x_square
                distance_bw_pts = math.sqrt(y_square_plus_x_square)
                if distance_bw_pts > d:
                    d = distance_bw_pts
                    p = [point1, point2]
    return apple_hls_s, d, p, i

img1 = cv2.imread(r'../apple_1.png')
img2 = cv2.imread(r'../apple_2.png')

apple_hls_s_1, max_d_1, img1_p, img1_i = solution(img1, 45)
apple_hls_s_2, max_d_2, img2_p, img2_i = solution(img2, 45)

print("max_d_1:", max_d_1,
      ", img1_p ", img1_p,
      ", img1_i ", img1_i)
cv2.drawMarker(apple_hls_s_1, img1_p[0], (0, 0, 255), thickness=7)
cv2.drawMarker(apple_hls_s_1, img1_p[1], (0, 0, 255), thickness=7)
cv2.imshow(str(max_d_1), apple_hls_s_1)
# cv2.imwrite("op_apple_1_edge_distance.png",apple_hls_s_1)

print("max_d_2:", max_d_2,
      ", img2_p ", img2_p,
      ", img2_i ", img2_i)
cv2.drawMarker(apple_hls_s_2, img2_p[0], (0, 0, 255), thickness=7)
cv2.drawMarker(apple_hls_s_2, img2_p[1], (0, 0, 255), thickness=7)
cv2.imshow(str(max_d_2), apple_hls_s_2)
# cv2.imwrite("op_apple_2_edge_distance.png",apple_hls_s_2)
print("ratio of the distances= ", (max_d_1/max_d_2))
cv2.waitKey(0)
cv2.destroyAllWindows()