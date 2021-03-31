# https://www.acmicpc.net/problem/1149
# TIMEOUT
DEBUG = False
l = 3

if DEBUG:
    import sys
    import fileinput

    input_buffer = []
    with fileinput.input(files = ('./input.txt')) as f:
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
        board.append(line)
    return board, n


cache = []

class Node:
    def __init__(self, i, j, edges, dist=-1):
        self.i = i
        self.j = j
        self.edges = edges
        self.dist = dist


def ready(inputs, n):
    graph = []

    for i in range(0, n+2):
        graph.append([])
        for j in range(0, l+1):
            graph[i].append(None)

    graph[0][0] = Node(0, 0, [
        dict(
            i=1,
            j=idx,
            dist=int(inputs[0][idx-1])
        ) for idx in range(1, l+1)
    ], 0)

    for i in range(1, n):
        for j in range(1, l + 1):
            graph[i][j] = Node(i, j, [
                dict(
                    i=i + 1,
                    j=idx,
                    dist=int(inputs[i][idx-1])
                ) for idx in range(1, l+1) if idx != j
            ])

    for j in range(1, l + 1):
        graph[n][j] = Node(n, j, [
            dict(
                i=n+1,
                j=0,
                dist=0)
        ])

    graph[n+1][0] = Node(n+1, 0, [])
    return graph

def djikstra(graph, start):
    queue = []
    queue.append(start)

    while True:
        current = queue.pop(0)
        for edge in current.edges:
            far = graph[edge['i']][edge['j']].dist
            cur = edge['dist']
            if far == -1 or far > (cur + current.dist):
                graph[edge['i']][edge['j']].dist = cur + current.dist
            queue.append(graph[edge['i']][edge['j']])

        if len(queue) == 0:
            break
    return graph

board, n = read_input()
graph = ready(board, n)
result = djikstra(graph, graph[0][0])
print(result[n+1][0].dist)
