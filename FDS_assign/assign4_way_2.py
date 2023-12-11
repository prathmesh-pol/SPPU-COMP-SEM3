import math
n1=int(input("Enter number of inputs of first polynomial: "))
fp=[]
fd=[]
sp=[]
sd=[]
m1=0
m2=0

for i in range (0,n1):
   num=int(input("Enter coefficient : "))
   temp=int(input("Enter exp: "))
   if temp-1>m1 :
       m1=temp-1
   fp.append(num)
   fd.append(temp-1)

n2=int(input("Enter number of inputs of second polynomial: ")) 
for i in range (0,n2):
   num=int(input("Enter coefficient : "))
   temp=int(input("Enter exp: "))
   if temp-1>m2 :
       m2=temp-1
   sp.append(num)
   sd.append(temp-1)

unique=[]
for i in range (0,n1):
   if fd[i] not in unique:
      unique.append(fd[i])
for i in range (0,n2):
   if sd[i] not in unique:
      unique.append(sd[i])

unique.sort()
unique.reverse()
add_coeff=[]      
for i in range(0,len(unique)):
    add_coeff.append(0)

for i in range (0,n1):
    for j in range(0,len(unique)):
        if(fd[i]==unique[j]):
           add_coeff[j]+=fp[i]

print(fp)
print(sp)
print(unique)

for i in range (0,n2):
    for j in range(0,len(unique)):
        if(sd[i]==unique[j]):
           add_coeff[j]+=sp[i]   
# add_coeff.reverse()

for i in range (0,len(add_coeff)):
    if(i==0):
        print(add_coeff[i],"x^",unique[i],end=(''))
    else :
        if(unique[i]==0):
            print("+",add_coeff[i],end=(''))
        else :
            print("+",add_coeff[i],"x^",unique[i],end=(''))
print()        
# print(add_coeff)                  

x=int(input("Enter the value of x : "))
store=0
for i in range(0,len(unique)):
    store+=add_coeff[i]*pow(x,unique[i])

print("Value of polynomial for x=",x,"is : ",store)    
print()
uniq_mult=[]


# for i in range (0,m1+m2+1):
#     uniq_mult.append(0)
for i in range(0,n1):
   for j in range(0,n2):
      if (fd[i]+sd[j]) not in uniq_mult:
         uniq_mult.append(fd[i]+sd[j])
# print(len(uniq_mult))
uniq_mult.sort()
uniq_mult.reverse()
# print(uniq_mult)
mult_cont=[]
for i in range (0,len(uniq_mult)):
    mult_cont.append(0)

for i in range(0,n1):
   for j in range(0,n2):
      mult_cont[fd[i]+sd[j]]+=fp[i]*sp[j]
mult_cont.reverse()

for i in range (0,len(mult_cont)):
    if(i==0):
        print(mult_cont[i],"x^",uniq_mult[i],end=(''))
    elif(uniq_mult[i]==0):
        print("+",mult_cont[i],end=(''))
    else:     
        print("+",mult_cont[i],"x^",uniq_mult[i],end=(''))
# print(mult_cont)       


     




