 

def most_frequent(List):
    counter = 0
     
    for i in List:
        curr_frequency = List.count(i)
        if(curr_frequency> counter):
            counter = curr_frequency
 
    return counter
 
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    p:list = [x+1 for x in range(n)]
    a.sort(reverse=1)
    b = []
    c = [0]
    for x in range(n):
        if(x%2 == 0):
            b.append(a[x])
        else:
            b.append(a[x]*(-1))
    for x in range(1, n):
        c.append(b[x]+b[x-1])
    
    mx = 0
    cnt = 0
    for i in range(n):
        if c[i] == 1 or c[i] == -1:
            cnt = cnt + 1
        else:
            if cnt > mx:
                mx = cnt
            cnt = 0
        if cnt > mx:
                mx = cnt
    

    if mx < cnt:
        mx = cnt


    print(c)
    print(mx+1)
 
 
if __name__ == "__main__":
    for _ in range(int(input())):
        solve()