


# def Read_From_File(filename) -> list[list]:
#     with open(filename, 'r') as f:
#         l = []
#         for line in f:
#             str = [int(x) for x in line.split()]
#             l.append(str)
#     return l

# def Write_To_File(filename, data):
#     with open(filename, 'w') as f:
#         f.write(data)

def solve():
    n:int = int(input())
    a:list[list] = []
    for i in range(n):
        a.append(list(map(int, input().split())))

    a2 = a
    
    for i in range(1, n):
        a2[i][0] = a[i][0] + a2[i-1][0]
        a2[i][i] = a[i][i] + a2[i-1][i-1]

    for i in range(1, n):
        for k in range(1, i):
            a2[i][k] = max(a2[i-1][k], a2[i-1][k-1]) + a[i][k]
    
    ans = max(a2[n-1])
    
    print(str(ans))

if __name__ == "__main__":
    solve()