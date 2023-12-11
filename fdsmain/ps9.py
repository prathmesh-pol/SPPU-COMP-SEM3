m=int(input("Enter highest degree of 1st polynomial:"))
p1=[]
for i in range(m+1):
    p1.append(0)

p=int(input("Enter number of terms present in polynomial p1:"))

for i in range(p):
    index=int(input("Enter Index:"))
    coeff=int(input("Enter Coefficient:"))
    p1[index]=coeff

n=int(input("Enter highest degree of 2nd polynomial:"))
p2=[]

for i in range(n+1):
    p2.append(0)

q=int(input("Enter number of terms present in polynomial p2:"))

for i in range(q):
    index=int(input("Enter Index:"))
    coeff=int(input("Enter Coefficient:"))
    p2[index]=coeff

def output(poly,k):
    a=len(poly)
    for i in range(a):
        if(poly[i]!=0 and k!=1):
            print(str(poly[i])+"x^"+str(i)+" + ",end="")
            k-=1

        elif(poly[i]!=0 and k==1):
            print(str(poly[i])+"x^"+str(i))

print("1st Polynomail:")
print("f1(x):",end=" ")
output(p1,p)

print("2nd Polynomail:")
print("f2(x):",end=" ")
output(p2,q)

def evaluate(poly,x):
    temp=0
    for i in range(len(poly)):
        temp+=poly[i]* (x**i)

    return temp

def sum(poly1,poly2):
    temp=[]
    a=len(poly1)
    b=len(poly2)
    cnt=0
    if(a<=b):
        for i in range(a):
            temp.append(poly1[i]+poly2[i])
          
        for i in range(a,b):
            temp.append(poly2[i])
        
        
    elif(a>b):
        for i in range(b):
            temp.append(poly1[i]+poly2[i])
    
        for i in range(b,a):
            temp.append(poly1[i])
    

    for i in range(len(temp)):
        if(temp[i]!=0):
            cnt+=1

    output(temp,cnt)

def multiplication(poly1,poly2):
    a=len(poly1)
    b=len(poly2)
    temp=[]
    cnt=0

    for i in range(a+b-1):
        temp.append(int(0))

    for i in range(a):
        for j in range(b):
            temp[i+j]+=poly1[i]*poly2[j]

    for i in range(len(temp)):
        if(temp[i]!=0):
            cnt+=1

    output(temp,cnt)

v=int(input("Enter value:"))
print("Value of polynomial at",v,"is:",evaluate(p1,v))
print("Addition of two polynomial is:",end="")
sum(p1,p2)
print("Multiplication of two polynomial is:",end="")
multiplication(p1,p2)

