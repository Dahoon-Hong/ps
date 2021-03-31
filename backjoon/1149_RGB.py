# https://www.acmicpc.net/problem/1149
DEBUG = False
l = 3

if DEBUG:
    import sys
    import fileinput

    input_buffer = []
    with fileinput.input(files = ('./backjoon/input.txt')) as f:
        for line in f:
            input_buffer.append(line)


def read_input():
    if DEBUG:
        n = int(input_buffer.pop(0))
    else:
        n = int(input())
    board = []
    for i in range(0, n):
        if DEBUG:
            line = input_buffer.pop(0).split()
        else:
            line = input().split()
        board.append([int(x) for x in line])
    return board, n


def solution(inputs, n):
    dp = []
    for i in range(0, n):
        dp.append([0, 0, 0])
    
    for c in range(0, l):
        dp[0][c] = inputs[0][c]

    for i in range(1, n):
        for c in range(0, l):
            dp[i][c] = min([dp[i-1][x] for x in range(0, l) if x != c]) + inputs[i][c]
    if DEBUG:
        print(dp)
    return min([dp[n-1][x] for x in range(0, l)])


inputs, n = read_input()
print(solution(inputs, n))

