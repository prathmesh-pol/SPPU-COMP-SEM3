a=int(input("Enter the number of students in the class:"))
arr=[]
i=0
sum=0
high=0
low=100
clear=0
draw=0

for i in range(0,a):
    num=int(input("Enter the marks of ",i," student:"))
    arr.append(num)
    sum+=num
    if(num>high):
        high=num
    if(num<low):
        low=num
    if(num>=33):
        clear+=1
    else :
        draw+=1    
avg=float(sum/a)
frq=[]
i=0
for i in range (0,a):
    store=arr[i]
    current=0
    j=0
    for j in range (0,a):
        temp=arr[j]
        if(temp==store):
            current+=1
    frq.append(current)        

i=0
ini=0
for i in range (0,a):
    if(frq[i]>ini):
        ini=frq[i]

