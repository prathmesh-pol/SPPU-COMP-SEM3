m=int(input("Enter highest degree of 1st polynomial:"))
p1=[]

p=int(input("Enter number of terms present in polynomial p1:"))
for i in range(p):
    temp=[]
    index=int(input("Enter Index:"))
    coeff=int(input("Enter Coefficient:"))
    temp.append(index)
    temp.append(coeff)
    p1.append(temp)

n=int(input("Enter highest degree of 2nd polynomial:"))
p2=[]

q=int(input("Enter number of terms present in polynomial p2:"))

for i in range(q):
    temp=[]
    index=int(input("Enter Index:"))
    coeff=int(input("Enter Coefficient:"))
    temp.append(index)
    temp.append(coeff)
    p2.append(temp)


def addition(p1,p,p2,q):
    result=[]
    i=0
    j=0
    cnt=0
    while(i<p and j<q):
        cnt+=1
        temp=[]
        if(p1[i][0]==p2[j][0]):
            temp.append(p1[i][0])
            temp.append(p1[i][1]+p2[j][1])
            i+=1
            j+=1

        elif(p1[i][0]>p2[j][0]):
            temp.append(p1[i][0])
            temp.append(p1[i][1])
            i+=1

        else:
            temp.append(p2[j][0])
            temp.append(p2[j][1])
            j+=1

        result.append(temp)

    return output(result,cnt)


def multiplication(p1,m,p,p2,n,q):
    len=m+n+1
    res=[0]*len

    for i in range(p):
        for j in range(q):
            res[p1[i][0]+p2[j][0]]+=(p1[i][1]*p2[j][1])

    result=[]
    cnt=0
    for i in range(len-1,-1,-1):
        temp=[]
        if(res[i]!=0):
            cnt+=1
            temp.append(i)
            temp.append(res[i])
            result.append(temp)

    return output(result,cnt)


def value(poly,p,v):
    ans=0
    for i in range(p):
        ans+=(v**poly[i][0])*poly[i][1]

    return ans


def output(poly,k):
    for i in range(k):
        if(poly[i][0]!=0):
            print(str(poly[i][1])+"x^"+str(poly[i][0])+" + ",end="")
        else:
            print(str(poly[i][1])+"x^"+str(poly[i][0]))


print("p1(x): ",end="")
output(p1,p)
print("p2(x): ",end="")
output(p2,q)
print("Addition: ",end="")
addition(p1,p,p2,q)
print("Multiplication: ",end="")
multiplication(p1,m,p,p2,n,q)
v=int(input("Enter value of x:"))
print("Value of polynomial at x =",v,"is: ",end="")
print(value(p1,p,v))

    