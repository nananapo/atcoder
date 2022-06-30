N = int(input())

def prime_factor(n):
    a = dict()
    i = 2

    if n % i == 0:
        a[i] = 0
        while n > 0 and n % i == 0:
            a[i] += 1
            n /= i
        i += 1

    while i <= n and n > 0:
        if n % i == 0:
            a[i] = 0
            while n > 0 and n % i == 0:
                a[i] += 1
                n /= i
        i += 2
    return a

for i in range(1, N + 1):
    if i * i > N * N:
        break
    print(i * i, prime_factor(i * i))
