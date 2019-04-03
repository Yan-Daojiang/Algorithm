#_*_coding:utf-8_*_
#file: Quick_Select.py
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

def quick_select(a,s,t,k):
    i=partition(a,s,t)
    if s<t:
        if i==k:
            return a[i]
        elif k<i:
            return quick_select(a, s, i - 1, k)
        else:
            return  quick_select(a, i + 1, t, k)

    elif s==t and s==k:
            return a[s]

def main():
    a = [12, 12, 23, 45, 44, 98, 1, 4, 27, 88]
    print(quick_select(a,0,len(a)-1,9))

if __name__=="__main__":
    main()

