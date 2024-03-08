from math import sqrt 
from math import floor

n: int = int(input())
for i in range(n):
    kolvo = int(input())
    kv = list(map(int, input().split()))
    sm = sum(kv)
    if (sqrt(sm) - int(floor(sqrt(sm)))) == 0:
        print("YES")
    else:
        print("NO")