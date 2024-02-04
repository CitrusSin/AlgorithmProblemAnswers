import sys
sys.setrecursionlimit(100000)

def mex(s: set) -> int:
    for i in range(len(s)):
        if not i in s:
            return i
    return len(s)

prse = dict()
def sg(m: int, k: int):
    if m < 2*k:
        return 0
    if m in prse.keys():
        return prse[m]
    mprv = m
    fac = list()
    facts = list()
    d = 2
    while d * d <= m:
        if m % d == 0:
            fac.append(d)
            cnt = 0
            while m % d == 0:
                m //= d
                cnt += 1
            facts.append(cnt)
        d += 1
    if m != 1:
        fac.append(m)
        facts.append(1)
    
    def dfs(idx: int = 0, par: int = 1):
        if idx == len(fac):
            yield par
            return
        u = fac[idx]
        t = facts[idx]
        for i in range(t+1):
            for k in dfs(idx+1, par * (u ** i)):
                yield k
    rfs = list()
    for v in dfs():
        rfs.append(v)
    nextsgs = set()
    for fc in rfs:
        if fc >= k and fc != mprv:
            pfc = mprv // fc
            nextsgs.add(sg(fc, k) if pfc % 2 != 0 else 0)
    val = mex(nextsgs)
    prse[mprv] = val
    return val

ips = [int(x) for x in input().split(' ')]
n = ips[0]
m = ips[1]
k = ips[2]

ans = "Bong"
if n % 2 == 1:
    if sg(m, k) != 0:
        ans = "Bing"
print(ans)

