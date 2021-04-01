N = int(input())

for tc in range(N):
    al = int(input())
    arr = [int(x) for x in input().split(" ")]
    if al == 1:
        print("YES")
        continue

    arr.sort()

    last = arr[0]
    result = 'YES'
    for i in arr[1:]:
        #print(last, i)
        if i - last > 1:
            result = 'NO'
            break
        last = i
    
    print(result)