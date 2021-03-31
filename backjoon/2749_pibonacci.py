# pibo(n) = pibo((n-1)/2)^2 +  pibo((n+1)/2)^2
# pibo(n-1) = pibo(n) - pibo(n-2)
# b = n+1
# pibo(b) = pibo((b-1)/2)^2 +  pibo((b+1)/2)^2

# pibo(2i) = pibo((2i-1)/2)^2 +  pibo((2i+1)/2)^2

cache = []
cache.append(0)
cache.append(1)
cache.append(1)
cache.append(2)
cache.append(3)

def power(n):
    return n*n

def pibo(n):
    for x in range(len(cache), n+1):
        if x % 2 == 1:
            result = (power(cache[int((x-1)/2)]) + power(cache[int((x+1)/2)])) % 1000000
        else:
            a = x+1
            b = x-1
            pa = (power(cache[int((a-1)/2)]) + power(cache[int((a+1)/2)]))
            pb = (power(cache[int((b-1)/2)]) + power(cache[int((b+1)/2)]))
            result = (pa-pb) % 1000000
        cache.append(result)
    return cache[n] 

def solution(n):
    x = pibo(n) 
    return x  
# 1,000,000
#10,000,000
x = input()
print(solution(int(x) % 1500000))
