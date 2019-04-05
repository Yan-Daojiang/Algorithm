#_*_coding:utf-8_*_
#file: ex2.py
import sys
import numpy as np

#Input
n,k=input().split(" ")
n=int(n)
k=int(k)
number="$"+input()  #将number[0]用$占用便于切片取数

dp=np.full(shape=(10,10),fill_value=-1)     #初始化dp数组用-1进行填充
for i in range(1,len(number)):
    dp[(i,1)]=int(number[1:i+1])    #切片取数的第1为到第i位置

for i in range(1,len(number)):
    for j in range(2,k+1):
        temp=[]
        for d in range(1,i):
            temp.append(dp[(d,j-1)]*int(number[d+1:i+1]))
            dp[(i,j)]=np.max(temp)

#Output，采用重定向的方式输出到文件
console = sys.stdout #得到当前输出方向， 也就是控制台
out_file = open("Output.txt", 'w')
sys.stdout = out_file #重定向到文件
print(dp[n][k])