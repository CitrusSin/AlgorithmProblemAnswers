import decimal

mood = decimal.Decimal(0)

n = int(input())
arr = [int(x) for x in input().split(' ')]
for i in range(n):
    mood = mood / decimal.Decimal(2) + arr[i]
    if mood == 0:
        print('0', end='')
    elif mood < 0:
        print('-', end='')
    else:
        print('+', end='')
print()
