from bisect import bisect_right

if __name__ == "__main__":
    n = int(input("Interval counts> "))
    intervals = [tuple(map(int, input(f'Interval l_{i} r_{i}> ').split(' '))) for i in range(n)]

    intervals.sort(key=lambda x: x[1])

    print(f'Sorted intervals: {intervals}')

    p = []
    for i, (l, r) in enumerate(intervals):
        find_index = bisect_right(intervals[:i], l, key=lambda x: x[1]) - 1
        p.append(find_index)
    
    m = []
    for i, (l, r) in enumerate(intervals):
        if p[i] == -1:
            print(f'No p[i], let m[i]=1 at i = {i}')
            m.append(1)
            continue
        if 1 + m[p[i]] >= m[i-1]:
            print(f'Selected 1+m[p[i]]  at i = {i}')
            m.append(1 + m[p[i]])
        else:
            print(f'Selected m[i-1]     at i = {i}')
            m.append(m[i-1])
    
    print(f'p = {p}, m = {m}')
    selected_intervals = []
    ptr = n-1
    while ptr >= 0:
        if 1 + m[p[ptr]] >= m[ptr-1]:
            selected_intervals.append(intervals[ptr])
            ptr = p[ptr]
        else:
            ptr -= 1
    print(f'Selected intervals: {selected_intervals}')

# 测试样例：(1, 2), (1, 5), (3, 5), (6, 8), (7, 9)