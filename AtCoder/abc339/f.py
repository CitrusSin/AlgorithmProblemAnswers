n = int(input())

a = dict()
for _ in range(n):
    x = int(input())
    if a.get(x) == None:
        a[x] = 0
    a[x] += 1

cnt = 0
for x in a.keys():
    for y in a.keys():
        v = x * y
        if v in a.keys():
            cnt += a[x] * a[y] * a[v]

print(cnt)