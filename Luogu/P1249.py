n = int(input())
m = int(((8*n+9)**0.5-1)/2)
n2 = m*(m+1)//2-1
rem = n-n2

lst = [i for i in range(2, m+1)]

for i in range(m-2, m-2-rem, -1):
    lst[i] += 1

pdt = 1
for x in lst:
    print(x, end = ' ')
    pdt *= x
print()
print(pdt)