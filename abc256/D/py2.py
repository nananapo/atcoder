S=set()
for i in range(int(input())):
 L,R=map(int, input().split())
 S.add((i,L,1))
 S.add((i,R,-1))
S=sorted(S,key=lambda x:x[1])
i,n,s=0,0,0
while i<len(S):
 m,j=n,i
 while i<len(S) and S[j][1]==S[i][1]:
  n+=S[i][2]
  i+=1
 if m==0 and n>0:
  s=S[j][1]
 if m>0 and n==0:
  print(s,S[j][1])
 
