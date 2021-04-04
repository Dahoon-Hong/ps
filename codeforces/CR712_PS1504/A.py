TC = int(input())

A = 'a'

for tc in range(TC):
    string = input()
    str_len = len(string)

    if str_len == 1 and string == A:
        print("NO")
        continue
    if str_len == 2 and string == A+A:
        print("NO")
        continue

    l = 0
    r = str_len - 1


    while True:
        
        if l == r:
            if string[l] == A:
                print("NO")
            else:
                print("YES")
                print(string+A)
            break
        if l > r:
            print("NO")
            break

        if string[l] == A and string[r] == A:
            l += 1
            r -= 1
            continue
        
        if string[l] == A:
            new_str = string[:l+1] + A + string[l+1:]
            print('YES')
            print(new_str)
            break
        
        if string[r] == A:
            new_str = string[:r+1] + A + string[r+1:]
            print('YES')
            print(new_str)
            break

        print('YES')
        print(string+A)
        break