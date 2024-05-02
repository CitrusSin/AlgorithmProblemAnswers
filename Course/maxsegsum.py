import time
import math
import random

def mss_brute_stupid(arr):
    ans = max(arr)
    ansleft = arr.index(ans)
    ansright = ansleft
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            s = sum(arr[i:j+1])
            if s > ans:
                ans = s
                ansleft = i
                ansright = j
    return ansleft, ansright, ans

def mss_brute_clever(arr):
    ans = max(arr)
    ansleft = arr.index(ans)
    ansright = ansleft
    for i in range(len(arr)):
        partans = 0
        for j in range(i, len(arr)):
            partans += arr[j]
            if partans > ans:
                ansleft = i
                ansright = j
                ans = partans
    return ansleft, ansright, ans

def mss_split(arr):
    n = len(arr)
    if n == 0:
        return None
    elif n == 1:
        return (0, 0, arr[0])
    
    split = n // 2
    (left_part, right_part) = (arr[:split], arr[split:])

    left_max = 0
    left_sum = 0
    lp = 0
    for i, val in enumerate(left_part[::-1]):
        left_sum += val
        if left_sum > left_max:
            left_max = left_sum
            lp = i+1
    
    right_max = 0
    right_sum = 0
    rp = 0
    for i, val in enumerate(right_part):
        right_sum += val
        if right_sum > right_max:
            right_max = right_sum
            rp = i+1
    center_ans = (split - lp, split + rp - 1, left_max + right_max)
    left_ans = mss_split(left_part)
    (righti, rightj, right_sum) = mss_split(right_part)
    righti += split
    rightj += split
    
    if lp + rp > 0:
        anses = (center_ans, left_ans, (righti, rightj, right_sum))
    else:
        anses = (left_ans, (righti, rightj, right_sum))
    ans = anses[0]
    for tup in anses:
        if tup[2] > ans[2]:
            ans = tup
    return ans

def mss_dp(arr):
    ans = 0
    part = 0
    (mxl, mxr) = (0, 0)
    (l, r) = (0, 0)
    for i, val in enumerate(arr):
        if part + val >= 0:
            part = part + val
            r = i+1
        else:
            l = i+1
            r = i+1
            part = 0
        
        if part > ans:
            ans = part
            (mxl, mxr) = (l, r)
    if (mxr - mxl) == 0:
        ans = max(arr)
        idx = arr.index(ans)
        mxl = idx
        mxr = idx + 1
    return mxl, mxr-1, ans


def benchmark(func, *args, **kwargs):
    start = time.perf_counter_ns()
    result = func(*args, **kwargs)
    end = time.perf_counter_ns()

    return (end-start), result

def test_batch(arr, funcs):
    tms = [0] * len(funcs)
    for i, func in enumerate(funcs):
        tm, ans = benchmark(func, arr)
        print(f'Algorithm name: {repr(func).split(" ")[1]}\n\t- Time: {tm}ns\n\t- Result: {ans}')
        tms[i] = tm
    return tms


if __name__ == "__main__":
    print('Input list length: ', end='')
    n = int(input())

    arr = [0] * n
    for i in range(n):
        arr[i] = random.randint(-10000, 10000)
    
    print(f"Test data: {arr}")

    funcs = [
        mss_brute_stupid,
        mss_brute_clever,
        mss_split,
        mss_dp
    ]

    print()
    for k in range(int(math.log2(n)), -1, -1):
        n2 = n // (2 ** k)
        print(f'Test Region arr[0:{n2}] -----------------------------')
        test_batch(arr[:n2], funcs)
        print()
    
