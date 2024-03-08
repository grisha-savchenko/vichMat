
 
def Read_From_File(filename) -> list[list]:
    with open(filename, 'r') as f:
        l = []
        for line in f:
            str = [int(x) for x in line.split()]
            l.append(str)
    return l

def Write_To_File(filename, data):
    with open(filename, 'w') as f:
        f.write(data)

def solve():
    data: list[list[int]] = Read_From_File("knight.in")
    n, m = data[0][0], data[0][1]

    path:list[list] = [[0] * m for _ in range(n)]
    path[0][0] = 1
    
    for i in range(1,n):
        for k in range(1,m):
            if i - 2 < 0 and k - 2 < 0:
                path[i][k] = 0
            elif i - 2 < 0:
                path[i][k] = path[i-1][k-2]
            elif k - 2 < 0:
                path[i][k] = path[i-2][k-1]
            else:
                path[i][k] = path[i-2][k-1] + path[i-1][k-2]

            
    Write_To_File("knight.out", str(path[n-1][m-1])+"\n")

if __name__ == "__main__":
    solve()