
t: int = int(input())
for i in range(t):
    n:int = int(input())
    a:list =list(map(int, input().split()))
    q: int = int(input())
    first: list = []
    second: list = []
    for k in range(q):
        temp1, temp2 = map(int, input().split())
        first.append(temp1)
        second.append(temp2)
    for k in range(q):
        temp1 = -1
        temp2 = -1
        for g in range(first[k]-1, second[k]):
            breakflag = False
            for l in range(g, second[k]):
                if a[g] != a[l]:
                    temp1 = g+1
                    temp2 = l+1
                    breakflag = True
                    break
            if breakflag:
                break

        print(temp1, temp2)

    # print(first, second, sep="\n")