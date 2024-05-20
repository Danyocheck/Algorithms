n, m = map(int, input().split())
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

for j in range(m):
    for i in range(n - 1, -1, -1):
        print(matrix[i][j], end=" ")
    print()