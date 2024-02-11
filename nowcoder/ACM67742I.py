#sum_i_j max(2|a_i|, 2|a_j|)
import math

t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split(' ')]
    for i in range(len(a)):
        a[i] = abs(a[i]) * 2
    a.sort(reverse=True)
    print(a)
    b = a.copy()
    for i in range(1, len(b)):
        b[i] += b[i-1]
    ans = 0
    for i in range(len(a)):
        if i >= 1:
            ans += b[i-1]
        ans += a[i] * (len(a) - i - 1)
    print(ans)