n = int(input())
directories = []
for _ in range(n):
    directories.append(input())

directories.sort()
for directory in directories:
    last_slash = 0
    num_of_slashes = 0
    length = len(directory)
    for j in range(length):
        if directory[j] == '/':
            last_slash = j
            num_of_slashes += 1

    if last_slash == 0:
        print(' ' * (num_of_slashes * 2) + directory[last_slash:length])
    else:
        print(' ' * (num_of_slashes * 2) + directory[last_slash + 1:length])