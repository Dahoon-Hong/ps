TC = int(input())


for tc in range(TC):
    N = int(input())
    s = input()

    count_of_1 = 0
    for i in range(N):
        if s[i] == '1':
            count_of_1 += 1

    if not (s[0] == '1' and s[N-1] == '1'):
        print("NO")
        continue

    if count_of_1 % 2 != 0:
        print("NO")
        continue

    half = count_of_1/2
    count_1 = 1
    last_0 = 0
    a = ""
    b = ""
    
    for i in range(N):
        if s[i] == "1":
            if count_1 <= half:
                a += "("
                b += "("
                count_1 += 1
            else:
                a += ")"
                b += ")"
        else:
            if last_0 == 0:
                a += "("
                b += ")"
                last_0 = 1
            else:
                a += ")"
                b += "("
                last_0 = 0

    print("YES")
    print(a)
    print(b)