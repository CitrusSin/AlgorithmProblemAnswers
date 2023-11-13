def digit(val: str):
    c = ord(val)
    if c >= ord('0') and c <= ord('9'):
        return c - ord('0')
    elif c >= ord('A') and c <= ord('Z'):
        return 10 + c - ord('A')
    elif c >= ord('a') and c <= ord('z'):
        return 36 + c - ord('a')
    return -1

def dtc(c: int):
    if c >= 0 and c <= 9:
        return chr(ord('0') + c)
    elif c >= 10 and c <= 35:
        return chr(ord('A') + c - 10)
    elif c >= 36:
        return chr(ord('a') + c - 36)
    return '-'

def to_radix(val: int, radix: int):
    s = ''
    while val > 0:
        s = dtc(val % radix) + s
        val //= radix
    if len(s) == 0:
        s = '0'
    return s

def from_radix(val: str, radix: int):
    num = 0
    for c in val:
        num *= radix
        num += digit(c)
    return num

s = input().split(' ')
x = int(s[0])
y = int(s[1])

val = s[2]
print(to_radix(from_radix(val, x), y))
