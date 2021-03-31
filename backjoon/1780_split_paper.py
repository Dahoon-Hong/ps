# https://www.acmicpc.net/problem/1780
n = 9
board = """0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1"""
DEBUG = True


def read_input():
    if DEBUG:
        out = []
        b = board.split('\n')
        for i in range(0, n):
            l = [int(x) for x in b[i].split(" ")]
            out.append(l)
        return n, out


def split(n, board):
    if n == 1:
        raise Exception(1)
    k = int(n/3)
    result = []
    for i in range(0, 9):
        result.append(dict(
            size=k,
            value=None, 
            board=[]))

    for i in range(0, n):
        for j in range(0, 3):
            # print("%s %s [%s] %s %s" %(i, j, int(i/k)+j, j*k, (j+1)*k))
            # print(board['board'][i][(j*k):((j+1)*k)])
            result[int(i/k)*3+j]['board'].append(board['board'][i][(j*k):((j+1)*k)])
    # for i in range(0, 9):
    #     print(k, result[i])
    return result


def is_identical(n, board):
    c = [0, 0, 0]
    #print(board['board'])
    for line in board['board']:
        for v in line:
            c[v] += 1
        flag = 0
        for k in c:
            if k == 0:
                flag += 1
        if flag != 2:
            #print(c, "None")
            return None
    
    for idx, k in enumerate(c):
        if k > 0:
            #print(c, idx if idx != 2 else -1)
            return idx if idx != 2 else -1


def solution(n, board):
    board_size = n
    boards = [dict(
        size=board_size, 
        value=None, 
        board=board)]
    check_complete = []
    while True:
        #print(boards)
        need_to_split = []
        if len(boards) == 0:
            break
        
        while boards:
            b = boards.pop(0)
            res = is_identical(board_size, b)
            #print(res, b)
            if res is None:
                need_to_split.append(b)
            else:
                b['value'] = res
                check_complete.append(b)
        
        #print(need_to_split)
        #print(check_complete)
        for b in need_to_split:
            boards.extend(split(board_size, b))
        
        board_size = int(board_size / 3)

    result = [0, 0, 0]
    for b in check_complete:
        result[b['value']] += 1
    return result[-1], result[0], result[1]


n, board = read_input()
print(solution(n, board))
