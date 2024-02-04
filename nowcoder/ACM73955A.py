import math

n = int(input())

a = [int(x) for x in input().split(' ')]

mod = 998244353

def popcount(x: int):
    cnt = 0
    while x > 0:
        if x % 2 == 1:
            cnt += 1
        x //= 2
    return cnt

ast = dict()
for v in a:
    if not v in ast.keys():
        ast[v] = 0
    ast[v] += 1

ans = 0
for k1 in ast.keys():
    v1 = ast[k1]
    for k2 in ast.keys():
        v2 = ast[k2]
        ans += math.gcd(k1, k2) * (popcount(k1) + popcount(k2)) % mod  * v1 % mod * v2 % mod
        ans %= mod
print(ans)