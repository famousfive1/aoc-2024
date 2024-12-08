def l(a):
    m = len(a)
    inc = True
    for i in range(1, m):
        d = int(a[i]) - int(a[i-1]) 
        if not 0 < d < 4:
            inc = False
            break

    if inc:
        return inc

    inc = True
    for i in range(1, m):
        d = int(a[i]) - int(a[i-1]) 
        if not -4 < d < 0:
            inc = False
            break

    return inc


def main():
    n = int(input())

    cnt = 0
    for i in range(n):
        a = input().split()
        if l(a):
            cnt += 1
    print(cnt)


if __name__ == "__main__":
    main()

