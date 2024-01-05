num = int(input())

for i in range(num):
    n, a, b = map(int, input().split())
    find = False
    dict = {}
    for j in range(a, b + 1):
        if n % j == 0:
            print("YES")
            find = True
            break
        elif dict.get(n % j) is not None:
            print("YES")
            find = True
            break
        else:
            dict[j] = 1
    if not find:
        print("NO")