t = int(input())

for _ in range(t):
    sts = [x.lower() for x in input().split(' ')]
    if sts[0][0] == sts[1][0]:
        print("Yes")
    else:
        print("No")
    