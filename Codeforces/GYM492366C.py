def hex_to_int(s: str):
    ans = 0
    for i, c in enumerate(s):
        d = 0
        if c.isdigit():
            d = ord(c) - ord('0')
        elif c.islower():
            d = ord(c) - ord('a')
        elif c.isupper():
            d = ord(c) - ord('A')
        ans *= 16
        ans += d
    return ans

line = input()
nums = [hex_to_int(x) for x in line.split(' ')]

