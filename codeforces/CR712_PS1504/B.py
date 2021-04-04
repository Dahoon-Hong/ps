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

    if sa == sb:
        print("YES")
        continue

    a = [int(x) for x in sa]
    b = [int(x) for x in sb]

    if sum(a) != sum(b):
        print("NO")
        continue
    
    if N%2 == 1 and a[-1] != b[-1]:
        print("NO")
        continue
    #print(sa)
    i = 0
    while i < N:
        #print('---- {}'.format(i))
        if i < N - 1:
            if a[i] == b[i] and a[i+1] == b[i+1]:
                if i + 1 == N - 1 :
                    print("YES")
                    break
                i += 2
                continue

        if i == N - 1:
            if a[i] == b[i] :
                print("YES")
            else:
                print("NO")
            break

        j = i
        flag = 0
        while j < N-1:
            j += 2
            #sb_left = i-1 if i-1 >= 0
            #print(sa[i:j][::-1], sb[i:j], i, j)
            if sum(a[0:j])*2 == j:
                try:
                    aa = memory[sa[i:j]]
                except KeyError:
                    memory[sa[i:j]] = dict()
                
                try:
                    bb = memory[sa[i:j]][sb[i:j]]
                except KeyError:
                    memory[sa[i:j]][sb[i:j]] = check(j-i, sa[i:j], sb[i:j])
                    bb = memory[sa[i:j]][sb[i:j]]

                if bb is True:
                    flag=1
                    break
        
        i = j
        #print(i)
        if not flag:
            print("NO")
            break
        
        if i == N:
            print("YES")
            break
    print(memory)
    #print('?')