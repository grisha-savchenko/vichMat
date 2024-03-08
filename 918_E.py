

t: int = int(input())
for i in range(t):
    n = int(input())
    st = list(map(int, input().split()))

    for k in range(1, n, +2):
        st[k] *= -1

    cum = [0]
    temp: int = 0

    for k in range(n):
        temp += st[k]
        cum.append(temp)

    cum.sort()

    success: bool = False

    for k in range(len(cum)-1):
        if cum[k] == cum[k+1]:
            success = True
    
    if success:
        print("YES")
    else:
        print("NO")