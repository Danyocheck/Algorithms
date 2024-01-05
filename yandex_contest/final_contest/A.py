def find_cx(x):
    idx_a, idx_b = 1, 1
    val_a, val_b = 1, 1

    for _ in range(x):
        if val_a < val_b:
            yield val_a
            idx_a += 1
            val_a = idx_a ** 2
        else:
            yield val_b
            idx_b += 1
            val_b = idx_b ** 3


x = int(input())
result_cx = next(val for idx, val in enumerate(find_cx(x), start=1) if idx == x)

print(result_cx)