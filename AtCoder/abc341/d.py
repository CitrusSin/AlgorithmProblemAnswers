import math

arr = [int(x) for x in input().split(' ')]
n = arr[0]
m = arr[1]
if n > m:
    sp = n
    n = m
    m = sp
k = arr[2]
u = math.lcm(n, m)
p = u // n
q = u // m
unit = p + q - 2
uc = (k-1) // unit
rem = (k-1) % unit
base = u * uc
xl = 0
xr = p
while xl < xr:
    mid = (xl + xr) // 2
    if (xl + xr) % 2 == 1:
        mid += 1
    if mid+(mid*n)//m - 1 <= rem:
        xl = mid
    else:
        xr = mid - 1
pr = xl
qr = (xl*n)//m

pt = pr + qr
while pt - 1 < rem:
    pt += 1
    if pr*n > qr*m:
        qr += 1
    else:
        pr += 1

fin = max(pr*n, qr*m) + base
print(fin)
