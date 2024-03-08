

C:str = "bcd"
V:str= "ae"
n: int = int(input())
for i in range(n):
    n = int(input())
    slovo: str = input()
    k: int = 0
    while k < n-3:
            if slovo[k+2] in C and slovo[k+3] in C:
                print(slovo[k:k+3], end = "")
                k = k + 3
            else:
                print(slovo[k:k+2], end = "")
                k = k + 2
            print(".", end="")
    if slovo[-2] in C and slovo[-1] in V:
        print(slovo[-2:])
    else:
         print(slovo[-3:])