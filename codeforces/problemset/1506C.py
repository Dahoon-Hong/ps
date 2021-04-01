
N = int(input())

for tc in range(N):
    a = input()
    b = input()

    if a == b:
        print(0)
        continue

    cols = len(a)+1
    rows = len(b)+1

    arr_2d = []

    for r in range(rows):
        arr_2d.append([0]*cols)
        for c in range(cols):
            if c == 0 or r == 0:
                continue
            if a[c-1] == b[r-1]:
                diagonal = arr_2d[r-1][c-1]
                arr_2d[r][c] = diagonal + 1
                
    max_len = 0
    
    for r in range(rows):
        l_max = max(arr_2d[r])
        max_len = max(l_max, max_len)
    

    # print(max_len)
    if max_len == 0:
        print("{}".format(cols + rows - 2))
    else:
        print("{}".format(rows + cols - 2 - (max_len * 2)))
    