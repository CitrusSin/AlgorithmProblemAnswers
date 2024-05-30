def div_ceil(a, b):
    p = a // b
    if a % b != 0:
        p += 1
    return p

def align_ceil(a, b):
    return div_ceil(a, b) * b
    
def align_floor(a, b):
    return (a // b) * b

def countl0(a, b):
    total = b - a
    if total % 2 == 0:
        return total // 2
    if a % 2 == 0:
        return total // 2 + 1
    else:
        return total // 2

a, b, c, d = tuple(map(int, input().split(' ')))

if a > c:
    a, c = c, a
if b > d:
    b, d = d, b

x_area_1 = [2, 1, 0, 1]
x_area_2 = [1, 2, 1, 0]

ap = align_ceil(a, 4)
cp = align_floor(c, 4)
lp = cp - ap

l1 = lp
l2 = lp
for k in range(a, ap):
    l1 += x_area_1[k%4]
    l2 += x_area_2[k%4]
for k in range(cp, c):
    l1 += x_area_1[k%4]
    l2 += x_area_2[k%4]

if lp < 0:
    l1 = 0
    l2 = 0
    for k in range(a, c):
        l1 += x_area_1[k%4]
        l2 += x_area_2[k%4]

ans = l1*countl0(b, d) + l2*(d-b-countl0(b, d))
print(ans)
