import cv2

def on_trackbar(x):
    pass
def solution(img, b_l):
    blue = img[:, :, 0]
    x, img_th_blue = cv2.threshold(src=blue, thresh=b_l, maxval=255, type=cv2.THRESH_BINARY)
    img_th_blue_inv = cv2.bitwise_not(img_th_blue)
    apple = cv2.bitwise_and(img, img, mask=img_th_blue_inv)
    # cv2.imshow("img_th_blue_inv", img_th_blue_inv)
    # cv2.imshow("apple", apple)

    hls_h_l = cv2.getTrackbarPos("hls_h_l", LL)
    hls_l_l = cv2.getTrackbarPos("hls_l_l", LL)
    hls_s_l = cv2.getTrackbarPos("hls_s_l", LL)
    hls = cv2.cvtColor(img, cv2.COLOR_RGB2HLS)
    hls_h = hls[:, :, 0]
    hls_l = hls[:, :, 1]
    hls_s = hls[:, :, 2]
    y, hls_h_th = cv2.threshold(src=hls_h, thresh=hls_h_l, maxval=255, type=cv2.THRESH_BINARY, dst=None)
    y, hls_l_th = cv2.threshold(src=hls_l, thresh=hls_l_l, maxval=255, type=cv2.THRESH_BINARY_INV, dst=None)
    y, hls_s_th = cv2.threshold(src=hls_s, thresh=hls_s_l, maxval=255, type=cv2.THRESH_BINARY, dst=None)
    # h_l_s_planes =  cv2.hconcat([hls_h_th, hls_l_th, hls_s_th])
    # cv2.imshow("bgr",h_l_s_planes)
    apple_hls_s = cv2.bitwise_and(img, img, mask=hls_s_th)
    a=[]
    c, h = cv2.findContours(hls_s_th, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    for cnt in c:
        area = cv2.contourArea(cnt)
        if area > 0:
            a.append(area)
    cv2.drawContours(apple_hls_s, c, -1, (255, 0, 0),thickness=1)
    return hls_s_th, apple_hls_s, a

img1 = cv2.imread(r'../apple_1.png')
img2 = cv2.imread(r'../apple_2.png')

LL="Parameter"
cv2.namedWindow(LL)
cv2.resizeWindow(LL,300,200)
cv2.createTrackbar("b_l",LL,0,255,on_trackbar)
cv2.createTrackbar("hls_h_l",LL,0,255,on_trackbar)
cv2.createTrackbar("hls_l_l",LL,0,255,on_trackbar)
cv2.createTrackbar("hls_s_l",LL,0,225,on_trackbar)
cv2.setTrackbarPos("hls_s_l",LL,45)

while(1):
    b_l = cv2.getTrackbarPos("b_l", LL)
    hls_s_th_1, apple_hls_s_1, a1= solution(img1, 45)
    # print("area=", area_1)
    # cv2.imshow("hls_s_th", hls_s_th_1)
    # cv2.imshow("apple_hls_s", apple_hls_s_1)

    hls_s_th_2, apple_hls_s_2, a2 = solution(img2, 45)
    print("ratio (", a1[0],"/" ,a2[0], ") is : " , a1[0]/a2[0])
    cv2.imshow("edges_apple_1", apple_hls_s_1)
    cv2.imshow("edges_apple_2", apple_hls_s_2)
    cv2.imwrite("op_3_edges_apple_1.png", apple_hls_s_1)
    cv2.imwrite("op_3_edges_apple_2.png", apple_hls_s_2)
    if cv2.waitKey(1) == ord('q'):
        break
cv2.destroyAllWindows()