import random
import math

def pollard_rho(n: int):
    if n % 2 == 0:
        return 2
    f = lambda x, c: ((x*x)%n + c) % n
    while True:
        c = random.randint(1, n-1)
        a = f(0, c)
        b = f(f(0, c), c)
        while a != b:
            d = math.gcd(n, a - b if a > b else b - a)
            if d != 1 and d != n:
                return d
            a = f(a, c)
            b = f(f(b, c), c)

def qpowmod(base: int, exp: int, mod: int):
    r = base % mod
    rst = 1
    while exp > 0:
        if exp % 2 == 1:
            rst *= r
            rst %= mod
        r *= r
        r %= mod
        exp //= 2
    return rst

def miller_rabin(x: int, ti: int = 64):
    if x == 0 or x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    
    u = x - 1
    t = 0
    while u % 2 == 0:
        u //= 2
        t += 1
    
    for _ in range(ti):
        a = random.randint(1, x-1)
        d = qpowmod(a, u, x)
        if d == 1:
            continue
        for _ in range(t):
            if d == x-1:
                break
            d = (d * d) % x
            if d == 1:
                return False
        if d != 1 and d != x-1:
            return False
    
    return True

def product_decomposition(x: int):
    ans = list()
    def func(n: int):
        if n == 1:
            return
        if (miller_rabin(n)):
            ans.append(n)
            return
        d1 = pollard_rho(n)
        d2 = n // d1
        func(d1)
        func(d2)
    func(x)
    ans.sort()
    return ans


x = int(input())
print(product_decomposition(x))