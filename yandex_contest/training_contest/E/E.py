n = int(input())
ratings = list(map(int, input().split()))

prefix_sum = [0] * n
total_rating = sum(ratings)

for i in range(n):
    if i == 0:
        prefix_sum[i] = ratings[i]
    else:
        prefix_sum[i] = prefix_sum[i - 1] + ratings[i]

dissatisfactions = [0] * n

for i in range(n):
    dissatisfactions[i] = (i + 1) * ratings[i] - prefix_sum[i] + (total_rating - prefix_sum[i]) - (n - i - 1) * ratings[i]

print(*dissatisfactions)