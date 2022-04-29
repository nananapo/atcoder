from sys import stdin

N = int(input())
A = list(map(int,input().split()))
Q = int(input())
A = sorted(A)

results = []
for _ in range(Q):
    b = int(stdin.readline())
    
    left = 0
    length = N
    while length > 1:
        mid = left + length // 2
        if A[mid] == b:
            left = mid;
            break
        if length == 2:
            if abs(A[left] - b) > abs(A[left + 1] - b):
                left = left + 1
            break
        if A[mid] > b:
            length = length // 2 + 1
        else:
            left = mid
            if length % 2 == 0:
                length = length // 2
            else:
                length = length // 2 + 1
    results.append(abs(A[left] - b))
print("\n".join(map(str,results)))
