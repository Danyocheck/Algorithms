import math
import numpy as np


def distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


n, m = map(int, input().split())

children = []
for _ in range(n):
    x, y = map(int, input().split())
    children.append((x, y))

distribution_points = []
for _ in range(m):
    X, Y, a = map(int, input().split())
    distribution_points.append([X, Y, a])

M = np.zeros((len(distribution_points), len(children)))
for i, point in enumerate(distribution_points):
    for j, child in enumerate(children):
        M[i, j] = distance(child[0], child[1], point[0], point[1])

result = 0.0
MAX_VAL = np.max(M) + 1

for _ in range(n):
    d_pos, c_pos = np.unravel_index(M.argmin(), M.shape)
    result += M[d_pos, c_pos]

    M[:, c_pos] = MAX_VAL
    distribution_points[d_pos][2] -= 1
    if distribution_points[d_pos][2] == 0:
        M[d_pos, :] = MAX_VAL

print(result)
