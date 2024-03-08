

t: int = int(input())
for i in range(t):
    n = int(input())
    string: str = input()
    i = 0
    k = len(string) - 1 
    leftflag: bool = False
    rightflag: bool  = False
    while i <= k:
        if string[i] == 'B':
            leftflag = True
        if string[k] == 'B':
            rightflag = True
        if not(leftflag):
            i += 1
        if not(rightflag):
            k -= 1
        if leftflag and rightflag:
            break
        
    print(k-i+1)