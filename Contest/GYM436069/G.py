l1 = input().split(' ')

n = int(l1[0])
k = int(l1[1])

l2 = input().split(' ')
s = 0
for i in range(0, n):
    s += int(l2[i])

st = str(s*(10**k)//n)
stdec = st[-k:]
st2 = st[0:-k]+'.'+stdec
print(st2)