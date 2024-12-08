import sys

rules = {}
lines = []


def check(arr, n):
    for x in range(n):
        for y in range(x+1, n):
            if arr[x] not in rules or arr[y] not in rules[arr[x]]:
                return False
    return True


with open(sys.argv[1]) as file:
    lines = file.readlines()

m = len(lines)
i = 0
while i < m:
    line = lines[i].rstrip()
    if len(line) == 0:
        break
    u, v = map(int, line.split('|'))
    if u in rules:
        rules[u].add(v)
    else:
        rules[u] = set([v])

    i += 1

i += 1
ans = 0
while i < m:
    line = lines[i].rstrip()
    arr = list(map(int, line.split(',')))
    n = len(arr)

    if check(arr, n):
        ans += arr[n // 2]

    i += 1

print(ans)
