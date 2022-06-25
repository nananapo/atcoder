from math import ceil

N, X = map(int, input().split())
a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
print(a[ceil(X / N) - 1])
