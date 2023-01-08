p = [-1]*10001
p_len = 0
def solve(n):
    global p, p_len
    if n-1 < p_len:
        return p[n-1]
    else:
        p[0] = 1
        p[1] = 3
        p[2] = 5
        last_skip_index = 0
        for n2 in range(max(3, p_len), n):
            rlist = [2*p[i]+(2**(n2-i)-1) for i in range(last_skip_index, n2-1)]
            min_val = rlist[0]
            min_index = 0
            for i, v in enumerate(rlist):
                if v < min_val:
                    min_val = v
                    min_index = i + last_skip_index
            p[n2] = min_val
            last_skip_index = min_index
        p_len = n
        return p[n-1]

t = int(input())
for k in range(0, t):
    n = int(input())
    print(solve(n))