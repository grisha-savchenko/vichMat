


def Read_From_File(filename) -> list[list]:
    with open(filename, 'r') as f:
        l = []
        for line in f:
            str = line.split()
            l.append(str)
    return l

def Write_To_File(filename, data):
    with open(filename, 'w') as f:
        f.write(data)

def solve():
    data: list = Read_From_File("lepus.in")
    n:int = int(data[0][0])
    string:str = "".join(element for element in data[1])
    path = [0]*n
    path[0] = 0
    path[1] = path[0] + 1 if string[1] == "\"" else path[0] if string[1] == "." else -1
    if n > 2:
        path[2] = path[1] + 1 if string[2] == "\"" else path[1] if string[2] == "." else -1
    if n > 3:
        path[3] = max(path[2], path[0]) + 1 if string[3] == "\"" else max(path[2], path[0]) if string[3] == "." else -1
    if n > 4:
        path[4] = max(path[3], path[1]) + 1 if string[4] == "\"" else max(path[3], path[1]) if string[4] == "." else -1
    for i in range(5,n):
        if max(path[i-5], path[i-3], path[i-1]) == -1:
            path[i] = -1
        else:
            path[i] = max(path[i-5], path[i-3], path[i-1]) + 1 if string[i] == "\"" else max(path[i-5], path[i-3], path[i-1]) if string[i] == "." else -1
    Write_To_File("lepus.out", str(path[-1])+"\n")
    print(path)

if __name__ == "__main__":
    solve()