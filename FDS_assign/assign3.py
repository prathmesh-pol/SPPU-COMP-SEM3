arr=[]
brr=[]
m=int(input("Enter the rows of matrix A:"))
n=int(input("Enter the cols of matrix:"))
for i in range(m):
    temp=[]
    for j in range(n):
        num=int(input())
        temp.append(num)
    arr.append(temp)
    
# print(arr)  
print("Enter the second matrix:")  
for i in range(m):
    temp=[]
    for j in range(n):
        num=int(input())
        temp.append(num)
    brr.append(temp)   
if(m==n) :
        flag=True 
        sump=0 
        sums=0  
        for i in range(m):
            for j in range (n):
                if(i>j):
                    if(arr[i][j]!=0):
                        flag=False
                        break
                if(i==j):
                    sump+=arr[i][j]
                if(i+j==n-1)    :
                    sums+=arr[i][j]
        if(flag==False):
            print(" A is not Upper Triangular Matrix")                
        else :
            print("A is Upper Triangular Matrix") 
        print("Sum of diagonal elements : ",sums+sump)    
else :
        print("Triangular matrix not applicable")
add=[]       
sub=[]
mul=[]
for i in range(m):
    temp1=[]
    temp2=[]
    for j in range (n):
        temp1.append(arr[i][j]+brr[i][j])
        temp2.append(arr[i][j]-brr[i][j])
    add.append(temp1)
    sub.append(temp2)

print("Multiplication of matrices:")    
for i in range(m):
    temp1=[]
    for j in range (n): 
         sum=0
         for k in range(n) :
            sum+=(arr[i][k]*brr[k][j])
         temp1.append(sum)
    mul.append(temp1)

for i in range (m):
    for j in range (n):
       print(mul[i][j],end=' ')
    print()
new=arr
for i in range (m):
    for j in range (n):
        if(i==j):
            continue
        else :
            stor=new[i][j]
            new[i][j]=new[j][i]
            new[j][i]=stor

print("Transpose of arr :")
for i in range (m):
    for j in range (n):
        print(new[i][j],end=' ')
    print()
sad=0
fnd=False
for i in range (m):
    for j in range (n):
        str=arr[i][j]
        col=j
        row=i
        min=100000
        max=0
        for k in range (n):
            if(arr[i][k]>max):
                max=arr[i][k]
        for l in range (m):
            if(arr[l][j]<min):
                min=arr[l][j]
        if(max==str and min==str):
            fnd=True
            sad=str
            break
if(fnd==True):
    print("saddle point found: ",sad)
else :
    print("Saddle point not found")    


                
