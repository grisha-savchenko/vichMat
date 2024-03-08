def solve():
    n, m, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    cnt = [0] * (k + 1)
    for e in a:
        if e <= k:
            cnt[e] |= 1
    for e in b:
        if e <= k:
            cnt[e] |= 2
    c = [0] * 4
    for e in cnt:
        c[e] += 1
    if c[1] > k // 2 or c[2] > k // 2 or c[1] + c[2] + c[3] != k:
        print("NO")
    else:
        print("YES")
 
 
for _ in range(int(input())):
    solve()