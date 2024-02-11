n = int(input())

counts = [0] * 11
cps = [int(x) for x in input().split(' ')]
for k, v in enumerate(cps):
    counts[v] += 1

ans = counts[3] * counts[6] + counts[7] * counts[2] + counts[10] * counts[8]
print(ans)