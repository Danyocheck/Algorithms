N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]

dp = [[0] * M for _ in range(N)]

# Инициализация первой строкы и первого столбца
for i in range(N):
    dp[i][0] = grid[i][0]
for j in range(M):
    dp[0][j] = grid[0][j]

max_side = 0  # Максимальная сторона квадрата

for i in range(1, N):
    for j in range(1, M):
        if grid[i][j] == 1:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            max_side = max(max_side, dp[i][j])

print(max_side)