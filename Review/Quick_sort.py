#_*_coding:utf-8_*_
#file: Quick_sort.py
def partition(a,s,t):
	i=s
	j=t
	temp=a[i]
	while i!=j:
		while j>i and a[j]>=temp:
			j-=1
		a[i]=a[j]
		while i<j and a[i]<=temp:
			i+=1
		a[j]=a[i]
	a[i]=temp
	return i

def quick_sort(a,s,t):
    if s<t:
        i=partition(a,s,t)
        quick_sort(a,s,i-1)
        quick_sort(a,i+1,t)

def main():
    a = [12, 12, 23, 45, 44, 98, 1, 4, 27, 88]
    quick_sort(a, 0, len(a) - 1)
    print(a)

if __name__=="__main__":
    main()

