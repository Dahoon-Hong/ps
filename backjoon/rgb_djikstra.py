from time import time
l = 3
inputs = [
    [1,4,4],
    [2,1,2],
    [4,1,3],
    [2,1,2],
    [4,1,3],
    [2,1,2],
    [4,1,3],
    [2,1,2],
    [4,1,3],
    [2,1,2],
    [4,1,3],
    [4,1,3],
    [2,1,2],
    [4,1,3],
]
n = len(inputs)
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
            dist=inputs[0][idx-1]
        ) for idx in range(1, l+1)
    ], 0)

    for i in range(1, n):
        for j in range(1, l + 1):
            graph[i][j] = Node(i, j, [
                dict(
                    i=i + 1,
                    j=idx,
                    dist=inputs[i][idx-1],
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

def djikstra(graph, start, end):
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

if __name__ == "__main__":
    s = time()
    graph = ready(inputs, n)
    graph = djikstra(graph, graph[0][0], graph[n+1][0])
    print(graph[n+1][0].dist)
    e = time()
    print("%.6f" % (e-s))