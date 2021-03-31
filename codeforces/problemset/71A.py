
N = int(input())

for i in range(N):
    string = input()
    strlen = len(string)
    if strlen > 10:
        result = "{:s}{:d}{:s}".format(
            string[0],
            strlen-2,
            string[strlen-1]
        )
    else:
        result = string
    print(result)