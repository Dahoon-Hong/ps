from rgb import n, inputs
from time import time
l = 3


def solution(inputs, n):
    dp = []
    for i in range(0, n):
        dp.append([0, 0, 0])
    
    for c in range(0, l):
        dp[0][c] = inputs[0][c]

    for i in range(1, n):
        for c in range(0, l):
            dp[i][c] = min([dp[i-1][x] for x in range(0, l) if x != c]) + inputs[i][c]
    
    return min([dp[n-1][x] for x in range(0, l)])

if __name__ == "__main__":
    s = time()
    print(solution(inputs, n))
    e = time()
    print("%.6f" % (e-s))