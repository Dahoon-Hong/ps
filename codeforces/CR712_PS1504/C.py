TC = int(input())


def bfs(s, idx, a, a_sum, b_sum):
    if idx == len(s):
        return a

    if a_sum >= 0:
        a1 = []
        a1.extend(a)
        a1.append(1)

        if b_sum + s[idx] >= 0:
            return bfs(s, idx+1, a1, a_sum + 1, )
    
    if a_sum > 0:
        a2 = []
        a2.extend(a)
        a2.append(-1)
        a2 = bfs(s, idx+1, a2)


IDX = 0
A_ARR = 1
A_SUM = 2
B_SUM = 3

for tc in range(TC):
    N = int(input())
    s = input()
    si = [1 if x == "1" else -1 for x in s]

    if not (si[0] and si[N-1]):
        print("NO")
        continue

    if sum(si) % 2 != 0:
        print("NO")
        continue

    bfs_queue = []
    bfs_queue.append([0, [], 0, 0])
    flag = 0
    while len(bfs_queue) > 0:
        info = bfs_queue.pop(0)

        if info[IDX] == N:
            if not(info[A_SUM] == 0 and info[B_SUM] == 0):
                continue

            a = ""
            b = ""
            for idx, i in enumerate(info[A_ARR]):
                if i == 1:
                    a += "("
                else:
                    a += ")"
                if si[idx] * i == 1:
                    b += "("
                else:
                    b += ")"
            
            print("YES")
            print(a)
            print(b)
            flag = 1
            break
        
        if info[A_SUM] < N/2:
            a1 = []
            a1.extend(info[A_ARR])
            a1.append(1)
            b_sum = info[B_SUM] + si[info[IDX]]
            a_sum = info[A_SUM] + 1
            if b_sum >= 0:
                bfs_queue.append([info[IDX]+1, a1, a_sum, b_sum])

        if info[A_SUM] > 0:
            a2 = []
            a2.extend(info[A_ARR])
            a2.append(-1)
            b_sum = info[B_SUM] - si[info[IDX]]
            a_sum = info[A_SUM] - 1
            if b_sum >= 0:
                bfs_queue.append([info[IDX]+1, a2, a_sum, b_sum])

    if not flag:
        print("NO")