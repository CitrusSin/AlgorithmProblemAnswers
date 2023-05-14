h4 = [0, 1, 3, 5]

def hanoi4(x):
    global h4
    if x < len(h4):
        return h4[x]
    for n in range(len(h4), x+1):
        i = int(((8*n+1)**0.5-1)/2)
        h4.append(2*h4[n-i] + 2**i - 1)
    return h4[x]

t = int(input())
while t > 0:
    k = int(input())
    print(hanoi4(k))
    t -= 1