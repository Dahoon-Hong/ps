#1504 B
TC = int(input())

def check(n, x, y):
    xi = int(x, base=2)
    yi = int(y, base=2)

    #print(bin(xi), bin(yi))
    
    return xi ^ yi == 2**n-1

memory = dict()

for tc in range(TC):
    N = int(input())

    sa = input()
    sb = input()

    # if sa == sb:
    #     print("YES")
    #     continue

    a = [1 if x == '1' else -1 for x in sa]
    b = [1 if x == '1' else -1 for x in sb]

    # if sum(a) != sum(b):
    #     print("NO")
    #     continue

    a.append(1)
    b.append(1)

    t = 0
    flag = 0
    for i in range(0, N, 1):
        t += (a[i])
        # print(i, t, (a[i] == b[i]), (a[i+1] == b[i+1]))
        if ((a[i] == b[i]) != (a[i+1] == b[i+1])) and t != 0:
            print("NO")
            flag = 1
            break
    
    if not flag:
        print("YES")