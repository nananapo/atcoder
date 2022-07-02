K = int(input())
if K < 60:
    if K < 10:
        print("21:0", K, sep="")
    else:
        print("21:", K, sep="")
else:
    K = K - 60
    if K == 0:
        print("22:00")
    elif K < 10:
        print("22:0", K, sep="")
    else:
        print("22:", K, sep="")
