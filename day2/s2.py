def cp(x, y):
    d = int(x) - int(y) 
    if 0 < d < 4:
        return True
    return False

def cn(x, y):
    d = int(x) - int(y) 
    if -4 < d < 0:
        return True
    return False

def l(a):
    b = a.copy()
    m = len(a)
    inc = True
    chance = True
    for i in range(1, m):
        if not cp(a[i], a[i-1]):
            if chance:
                chance = False
                a[i] = a[i-1]
            else:
                inc = False
                break

    if inc:
        return inc

    a = b
    inc = True
    chance = True
    for i in range(1, m):
        if not cn(a[i], a[i-1]):
            if chance:
                chance = False
                a[i] = a[i-1]
            else:
                inc = False
                break

    return inc


def main():
    n = int(input())

    cnt = 0
    for i in range(n):
        a = input().split()
        c = a.copy()
        d = a.copy()[::-1]
        if l(c) or l(d):
            cnt += 1
    print(cnt)


if __name__ == "__main__":
    main()

