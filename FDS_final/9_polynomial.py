# 9 Polynomial 
# operations
# Write a C++ program to represent polynomials using 1-D array and perform 
# operations. Write function
# a) To input and output polynomials represented as bmxem+ bm-1xem-1 +….. 
# +b0xe0.
# b) Evaluates a polynomial at given value of x
# c) Add two polynomials
# d) Multiplies two polynomials


def print1(a):
    n=len(a)
    for i in range(n-1,-1,-1):
        if a[i]!=0:
           print(a[i],"x^",i,end=" ")
           if(i>0):
                print("+",end=" ")
    print()

def addition(a,b,n,m):
    ad=[]
    index=0
    for i in range(min(n+1,m+1)):
        ad.append(a[i]+b[i])
        index=i

    for j in range(index,n+1):
        ad.append(a[index])

    for j in range(index,m+1):
        ad.append(b[index])
    return ad

def multiple(a,b,n,m):
    mul=[0]*((n+1)*(m+1))
    for i in range(n+1):
          for j in range(m+1):
              mul[i+j]+=a[i]*a[j]
    return mul
              
        
    



n=int(input("Enter the highest power of polynomial: "))
a=[]
for i in range(n+1):
    x=int(input("enter the cofficent : "))
    a.append(x)

m=int(input("Enter the highest power of polynomial: "))
b=[]
for i in range(m+1):
    x=int(input("enter the cofficent : "))
    b.append(x)

print1(a)
print1(b)
print()
print("addition : ")
print1(addition(a,b,n,m))
print()
print("multiplication ")
print1(multiple(a,b,n,m))



