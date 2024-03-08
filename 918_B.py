

n: int = int(input())
for i in range(n):
    for k in range(3):
        str = input()
        if('A' in str and 'B' in str and '?' in str):
            print('C')
        if('A' in str and 'C' in str and '?' in str):
            print('B')
        if('B' in str and 'C' in str and '?' in str):
            print('A')