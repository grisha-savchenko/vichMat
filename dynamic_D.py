


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
    data: list[list[int]] = Read_From_File("king2.in")
    data2 =data
    # print(data2)
    
    data2[7][0] = data[7][0]
    for i in range(6, -1, -1):
        data2[i][0] = data2[i+1][0] + data[i][0]
    for i in range(1, 8):
        data2[7][i] = data2[7][i-1] + data[7][i]


    for i in range(6, -1, -1):
        for k in range(1, 8):
            data2[i][k] = min(data2[i+1][k], data2[i][k-1],  data2[i+1][k-1]) + data[i][k]
            
    # print(data2)
   
    Write_To_File("king2.out", str(data2[0][7])+"\n")

if __name__ == "__main__":
    solve()