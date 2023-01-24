import cv2
import numpy as np

img = cv2.imread(r'C:\New folder\computer_vision\images.jpg')
h, w, ch = img.shape

theta = 0
phi = 0
gamma = -1.57
dx = 0
dy = 0

d = np.sqrt(h ** 2 + w ** 2)
dz = d / (2 * np.sin(gamma * (180.0 / 3.14)) if np.sin(gamma * (180.0 / 3.14)) != 0 else 1)
f = dz
# Projection 2D -> 3D matrix
A1 = np.array([[1, 0, -w / 2],
               [0, 1, -h / 2],
               [0, 0, 1],
               [0, 0, 1]])

# Rotation matrices around the X, Y, and Z axis
RX = np.array([[1, 0, 0, 0],
               [0, np.cos(theta), -np.sin(theta), 0],
               [0, np.sin(theta), np.cos(theta), 0],
               [0, 0, 0, 1]])

RY = np.array([[np.cos(phi), 0, -np.sin(phi), 0],
               [0, 1, 0, 0],
               [np.sin(phi), 0, np.cos(phi), 0],
               [0, 0, 0, 1]])

RZ = np.array([[np.cos(gamma), -np.sin(gamma), 0, 0],
               [np.sin(gamma), np.cos(gamma), 0, 0],
               [0, 0, 1, 0],
               [0, 0, 0, 1]])

# Composed rotation matrix with (RX, RY, RZ)
R = np.dot(np.dot(RX, RY), RZ)

# Translation matrix
T = np.array([[1, 0, 0, dx],
              [0, 1, 0, dy],
              [0, 0, 1, dz],
              [0, 0, 0, 1]])

# Projection 3D -> 2D matrix
A2 = np.array([[f, 0, w / 2, 0],
               [0, f, h / 2, 0],
               [0, 0, 1, 0]])

mat = np.dot(A2, np.dot(T, np.dot(R, A1)))

image = cv2.warpPerspective(img, mat, (w, h))
cv2.imshow("img", img)
cv2.imshow("image", image)
cv2.imwrite("rot in z by -90.png", image)
cv2.waitKey(0)
cv2.destroyAllWindows()

# referred http://jepsonsblog.blogspot.com/2012/11/rotation-in-3d-using-opencvs.html
