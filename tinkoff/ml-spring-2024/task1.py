n = int(input())
marks = list(map(int, input().split()))

max_num_of_fives = -1
for i in range(6, n):
    curr_num_of_fives = 0
    for j in range(i - 6, i + 1):
        if marks[j] == 2 or marks[j] == 3:
            curr_num_of_fives = -1
            break
        if marks[j] == 5:
            curr_num_of_fives += 1

    if curr_num_of_fives > max_num_of_fives:
        max_num_of_fives = curr_num_of_fives

print(max_num_of_fives)