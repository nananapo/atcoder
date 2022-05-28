N, A, B = map(int, input().split())

def sum(a):
    d = N // a * a
    return (a + d) * (N // a) // 2

def gcd(a, b):
    t = a
    a = min(a, b)
    b = max(t, b)
    while b % a != 0:
        t = b
        b = a
        a = t % a
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

print(sum(1) - sum(A) - sum(B) + sum(lcm(A, B)))
