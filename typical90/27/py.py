n=set()
for i in range(int(input())):
 m=input()
 if m not in n:
  print(i+1)
 n.add(m)
