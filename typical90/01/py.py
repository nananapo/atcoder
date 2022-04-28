import math

N,L = map(int,input().split())
K = int(input()) + 1
A = [0] + list(map(int,input().split()))
A.append(L)

def can_cut(n):
    count = 0
    accu = 0
    for i in range(1, N + 2):
        accu += A[i] - A[i - 1]
        if accu >= n:
            accu = 0
            count += 1
            if count == K:
                return True
    return False

left = 0
length = L
while length > 1:
    mid = left + length // 2
    if can_cut(mid):
        length = length // 2 if length%2==0 else length // 2 + 1
        left = mid
    else:
        length = length // 2

print(left)
