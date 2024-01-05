import math

def is_circle(x1, y1, x2, y2):
    return x1 * x1 + y1 * y1 == x2 * x2 + y2 * y2

def is_straight(x1, y1, x2, y2):
    if ((x1 == 0 and x2 != 0) or (x1 != 0 and x2 == 0)
        or (y1 == 0 and y2 != 0) or (y1 != 0 and y2 == 0)
    ):
        return False
    elif ((x1 == 0 and x2 == 0) or (y1 == 0 and y2 == 0)
        or (x1 == 0 and y1 == 0) or (x2 == 0 and y2 == 0)
    ):
        return True
    
    k1 = y1 / x1
    k2 = y2 / x2
    return k1 == k2

def find_angle(x1, y1, x2, y2):
    return abs(math.atan2(y2, x2) - math.atan2(y1, x1))

def find_alpha(x1, y1, x2, y2, r):
    if x2 == 0:
        if y2 < 0:
            alpha = find_angle(x1, y1, 0, -r)
        else:
            alpha = find_angle(x1, y1, 0, r)
    else:
        k = y2 / x2
        if x2 < 0:
            intersection_x = -r / math.sqrt(1 + k * k)
        else:
            intersection_x = r / math.sqrt(1 + k * k)
        intersection_y = k * intersection_x
        alpha = find_angle(x1, y1, intersection_x, intersection_y)

    return alpha

x1, y1, x2, y2 = map(float, input().split())
if is_straight(x1, y1, x2, y2):
    sub_x = x1 - x2
    sub_y = y1 - y2
    print(f"{math.sqrt(sub_x * sub_x + sub_y * sub_y):.12f}")
elif is_circle(x1, y1, x2, y2):
    r = math.sqrt(x1 * x1 + y1 * y1)
    angle = find_angle(x1, y1, x2, y2)
    if angle < 2:
        print(f"{angle * r:.12f}")
    else:
        print(f"{2 * r:.12f}")
else:
    r1 = math.sqrt(x1 * x1 + y1 * y1)
    r2 = math.sqrt(x2 * x2 + y2 * y2)
    if r1 < r2:
        alpha = find_alpha(x1, y1, x2, y2, r1)
        if alpha < 2:
            print(f"{alpha * r1 + r2 - r1:.12f}")
        else:
            print(f"{r1 + r2:.12f}")
    else:
        alpha = find_alpha(x2, y2, x1, y1, r2)
        ans = alpha * r2
        if alpha < 2:
            print(f"{alpha * r2 + r1 - r2:.12f}")
        else:
            print(f"{r1 + r2:.12f}")