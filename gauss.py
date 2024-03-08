import math


def Read_From_File(filename) -> list[list]:
    with open(filename, 'r') as f:
        l = []
        for line in f:
            str =[float(x) for x in line.split()]
            l.append(str)
    return l

def Print_Matrix(matrix: list[list]):
    for str in matrix:
        print(str)


def gauss_straight_way(matrix: list[list]) -> list[list]:
    row = len(matrix)
    col = row+1
    for i in range(0, row-1):
        matrix = max_row(matrix, i)
        if matrix[i][i] == 0:
            for g in range(i, row):
                if matrix[g][i] != 0:
                    matrix = swap(matrix, i, g)
                    break
            else:
                return [[0]]
        for g in range(i+1, row): 
            tmp: float = matrix[g][i]/matrix[i][i]
            for k in range(i+1, col): # i+1
                matrix[g][k] = matrix[g][k] - tmp*matrix[i][k]
                
    return matrix

def gauss_obrat_way(matrix: list[list]) -> list[float]:
    row = len(matrix)
    col = row+1
    answer:float = [] 
    for i in range(row-1, -1, -1):
        if matrix[i][i] == 0:
            for g in range(i, row):
                if matrix[g][i] != 0:
                    matrix = swap(matrix, i, g)
                    break
            else:
                return [0]
        tmp:float = 0
        for k in range(row-1, i, -1):
            tmp = tmp + matrix[i][k]*answer[row-k-1]
        x = (matrix[i][col-1]-tmp)/matrix[i][i]
        x = round(x,3)
        if x == 0:
            x = 0
        answer.append(x)
    return answer

def swap(matrix: list[list], x, y) -> list[list]:
    row = len(matrix)
    tmp = matrix[x]
    matrix[x] = matrix[y]
    matrix[y] = tmp
    return matrix

def max_row(matrix:list[list], x) -> list[list]:
    n = len(matrix)
    for i in range(x+1,n):
       if abs(matrix[x][x]) < abs(matrix[i][x]):
           swap(matrix, x, i)
    return matrix

matrix = Read_From_File("matrix.txt")
Print_Matrix(matrix)
gauss_straight_way(matrix)
print()
Print_Matrix(matrix)
print()
answer = gauss_obrat_way(matrix)
print(answer)