import math
l=int(input("Enter the degree of polynomial : "))
ft=[]        
sc=[]
sum=[]
eval=[]
mult=[]
for i in range (0,l+1):
    ft.append(0)
    sc.append(0)
    sum.append(0)
    eval.append(0)

for i in range(0,2*(l)+1):
    mult.append(0)

print("Enter first polynomial : ")

a=int(input("Enter the number of inputs of  first polynoomial : "))
for i in range(0,a):
    num=int(input("Enter value : "))
    ind=int(input("Enter index : "))
    ft[ind-1]=num

print("Enter the second polynomial : ")
b=int(input("Enter the number of inputs of  second polynoomial : "))
for i in range(0,b):
    num=int(input("Enter value : "))
    ind=int(input("Enter index : "))
    sc[ind-1]=num   

key=int(input("Enter key -> 1:Sum  2:Evaluate  3:Multiplication"))

if(key==1): 
    for i in range(0,l+1):
        sum[i]=ft[i]+sc[i]
    sum.reverse()
    for i in range (0,l+1):
        if(sum[i]==0):
            continue
        else:
            if(i!=l):
                print(sum[i],"x^",l-i,"+",end=(''))
            else :
                print(sum[i])     
elif key==2:
    x=int(input("Enter the value of x: "))
    temp=0
    for i in range (0,l+1):
        eval[i]=sum[i]*(math.pow(x,i))
        temp+=eval[i]
    print("Evaluation of this polynomial for given value of x is : ",temp)    

elif key==3:
    for i in range(0,l+1):
        for j  in range (0,l+1):
            mult[i+j]+=ft[i]*sc[j]

    mult.reverse()
    for i in range (0,2*l+1):
        if(mult[i]==0):
            continue
        else:
            if(i!=2*l):
                print(mult[i],"x^",2*l-i,"+",end=(''))
            else :
                print(mult[i])  

else:
    print("Invalid key ! ...")                 









