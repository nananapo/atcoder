N=int(input())
SIZE=1010
M={i:[0]*SIZE for i in range(SIZE)}

for _ in range(N):
 e,f,g,h=map(int,input().split())

 a=min(e,g)
 b=max(f,h)
 c=max(e,g)
 d=min(f,h)

 M[d][a]+=1
 M[b][a]+=-1
 M[d][c]+=-1
 M[b][c]+=1

for i in range(0,SIZE):
 for j in range(1,SIZE):
  M[i][j]+=M[i][j-1]

for j in range(0,SIZE):
 for i in range(1,SIZE):
  M[i][j]+=M[i-1][j]

C=[0 for i in range(0,N+1)]
for i in range(0,SIZE):
 for j in range(0,SIZE):
  C[M[i][j]]+=1

for i in range(1,N+1):
 print(C[i])
