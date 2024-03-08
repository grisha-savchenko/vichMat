

n: int = int(input())
for i in range(n):
    a,b,c = map(int, input().split())
    if(a == b):
        print(c)
    if(a == c):
        print(b)
    if(b == c):
        print(a)