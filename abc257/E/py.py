from functools import lru_cache

N = int(input())
C = list(map(int, input()))

CP = dict()
for i in range(1, 10)):
    CP.append((C[i - 1], i))

@lru_cache(maxsize = None)
def dig(n, x):
    if n == 0:
        return x
    
