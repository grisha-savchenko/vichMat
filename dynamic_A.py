


# def Read_From_File(filename) -> list[list]:
#     with open(filename, 'r') as f:
#         l = []
#         for line in f:
#             str =[int(x) for x in line.split()]
#             l.append(str)
#     return l

def Write_To_File(filename, data):
    with open(filename, 'w') as f:
        f.write(data)

def solve():
    with open("ladder.in", 'r') as f:
        n = int(f.readline())
        a:list = [int(x) for x in f.readline().split()]
    path: list = [0]*n
    path[0] = a[0]
    if n > 1:
        path[1] = max(0, path[0]) + a[1]
    for i in range(2,n):
        path[i] = max(path[i-1], path[i-2]) + a[i]

    Write_To_File("ladder.out", str(path[-1])+"\n")


if __name__ == "__main__":
    solve()