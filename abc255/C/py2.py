X,A,D,N=map(int,input().split())
LD=A+D*(N-1)
if D==0:
 print(abs(X-A))
elif D>0:
 if X<=A:
  print(A-X)
 elif X>=LD:
  print(X-LD)
 else:
  a=A+(X-A)//D*D
  b=min(LD,a+D)
  c=max(A,a-D)
  print(min(abs(a-X),abs(b-X)))
else:
 if X<=LD:
  print(LD-X)
 elif X>=A:
  print(X-A)
 else:
  a=A+(A-X)//-D*D
  b=max(LD,a+D)
  c=min(A,a-D)
  print(min(abs(a-X),abs(b-X),abs(c-X)))
