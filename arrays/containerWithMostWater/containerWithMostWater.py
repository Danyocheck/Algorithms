height = list(map(int, input().split()))
max_volume, left_pointer, right_pointer = 0, 0, len(height) - 1
while left_pointer < right_pointer:
    max_volume = max(min(height[left_pointer], height[right_pointer]) * (right_pointer - left_pointer), max_volume)
    if height[left_pointer] > height[right_pointer]:
        right_pointer -= 1
    else:
        left_pointer += 1
print(max_volume)