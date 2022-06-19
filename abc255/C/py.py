X, A, D, N = map(int, input().split())

if X == A:
    print(0)
    exit()

if (D > 0 and X < A) or (D < 0 and X > A) or D == 0:
    print(abs(X - A))
    exit()

if D > 0 and A + D * N <= X:
    print(X - (A + D * N))
    exit()

if D < 0 and A + D * N >= X:
    print(A + D * N - X)
    exit()

X -= A

waru = X // D
result = 100000000000

for i in range(waru - 1000, waru + 1000):
    if i < 0 or i > N:
        continue
    result = min(result, abs(D * i - X))

print(result)
