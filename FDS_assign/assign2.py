n=int(input("Enter number of students in class:"))
a=int(input("Enter number of students playing cricket:"))
print("Enter the roll no of students who play criket:")
arr=[]
i=0
for i in range(0,a):
    num=int(input())
    arr.append(num)
b=int(input("Enter number of students playing badminton:"))
print("Enter the roll no of students who play badminton:")
brr=[]
i=0
for i in range(0,b):
    num=int(input())
    brr.append(num)
c=int(input("Enter number of students playing football:"))
print("Enter the roll no of students who play football:")
crr=[]
i=0
for i in range(0,c):
    num=int(input())
    crr.append(num)    
botha_b=[]    
bothb_c=[]
botha_c=[]

for i in range(0,a):
    for j in range(0,b):
        if(arr[i]==brr[j]):
            botha_b.append(arr[i])
for i in range(0,b):
    for j in range(0,c):
        if(brr[i]==crr[j]):
            bothb_c.append(brr[i])
for i in range(0,a):
    for j in range(0,c):
        if(arr[i]==crr[j]):
            botha_c.append(arr[i]) 
a_b_c=[]            
for i in range(0,a):       
    for j in range(0,b):
        for k in range(0,c):
            if(arr[i]==brr[j]==crr[k]):
                a_b_c.append(arr[i])

corb=[]
for i in range(0,a):
    flag=True
    for j in range (0,len(botha_b)):
        if(arr[i]==botha_b[j]):
            flag=False
    if(flag==False):
        continue
    else :
        corb.append(arr[i])
for i in range(0,b):
    flag=True
    for j in range (0,len(botha_b)):
        if(brr[i]==botha_b[j]):
            flag=False
    if(flag==False):
        continue
    else :
        corb.append(brr[i]) 

     
onlya=a-len(botha_b)-len(botha_c)+len(a_b_c)
onlyb=b-len(botha_b)-len(bothb_c)+len(a_b_c)
onlyc=c-len(botha_c)-len(bothb_c)+len(a_b_c)

print("Students who play both cricket and badminton are:")
print(botha_b)
print("Students who play both badminton and football are:")
print(bothb_c) 
print("Students who play both cricket and football are:")    
print(botha_c)

print("Students who play either cricket or badminton but not both:",a+b-len(botha_b))
print(corb)
print("Students who play neither cricket nor badminton:",n-a-b+len(botha_b))
print("Students who play cricket and football but not badminton:",len(botha_c)-len(a_b_c))
print("Number of students who do not play any game:",n-a-b-c+len(botha_b)+len(botha_c)+len(bothb_c)-len(a_b_c))
print("Number of students who play atleast one game:",a+b+c+len(a_b_c)-len(botha_b)-len(botha_c)-len(bothb_c))
print("Students who play all three games:")
print(a_b_c)
