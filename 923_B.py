

def solve():
    letters = {i: 0 for i in "qwertyuiopasdfghjklzxcvbnm"}
    n = int(input())
    a = map(int, input().split())
    result = ""
    for i in a:
        for key, value in letters.items():
            if i == value:
                result += key
                letters[key] += 1
                break
    print(result)


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()