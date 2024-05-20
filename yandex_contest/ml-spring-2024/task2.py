def argsort(arr):
    return sorted(range(len(arr)), key=arr.__getitem__)


def main():
    n, q = map(int, input().split())

    a = [0] * n
    b = [0] * n
    for i in range(n):
        a[i], b[i] = map(int, input().split())

    idx = argsort(b)
    # print(f"{idx=}")

    a_sum = sum(a)
    b_sum = sum((n - idx[i]) * b_i for i, b_i in enumerate(b))

    # print(f"{a_sum=}\t{b_sum=}")
    print(f"{a_sum - b_sum}")

    for _ in range(q):
        n_chg, a_new, b_new = map(int, input().split())

        a_sum = a_sum + a_new - a[n_chg - 1]
        a[n_chg - 1] = a_new

        # DEB
        b[n_chg - 1] = b_new
        idx = argsort(b)
        b_sum = sum((n - idx[i]) * b_i for i, b_i in enumerate(b))
        # ! DEB

        print(f"{a_sum - b_sum}")


if __name__ == '__main__':
    main()
