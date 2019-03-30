n,k=input().split(" ")
n=int(n)
k=int(k);


a=input().split(" ")
a=[int(a[i])for i in range(len(a))]
mark=a[0]
count=1
a.sort()
j=1
for j in range(n):
	if a[j]>mark+k:
		mark=a[j]
		count+=1
print(count)