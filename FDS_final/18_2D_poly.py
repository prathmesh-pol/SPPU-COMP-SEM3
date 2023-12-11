# 18 Polynomial 
# operations
# Write a C++ program to represent polynomials using 2-D array and perform 
# operations. Write function
# a) To input and output polynomials represented as bmxem+ bm-1xem-1 +….. 
# +b0xe0.
# b) Evaluates a polynomial at given value of x
# c) Add two polynomials
# d) Multiplies two polynomials


def printPoly(poly,co):
      for i in range(co):
           print(poly[i][0],"x^",poly[i][1],end=" ")
           if i!=co-1:
                print("+",end=" ")
      print(" ")

def addition(poly1,poly2,co1,co2,hp1,hp2):
        poly=[]
        i=0
        j=0
        while(i<co1 and j<co2):
             if(poly1[i][1]==poly2[j][1]):
                   temp=[]
                   temp.append(poly1[i][0]+poly2[j][0])
                   temp.append(poly2[i][1])
                   poly.append(temp)
                   i+=1
                   j+=1
             elif  poly1[i][1]<poly2[j][1]:
                   temp=[]
                   temp.append(poly2[j][1])
                   poly.append(temp)
                   j+=1
             elif  poly1[i][1]>poly2[j][1]:
                   temp=[]
                   temp.append(poly1[i][1])
                   poly.append(temp)
                   i+=1
        for t in range(i,co1):
              temp=[]
              temp.append(poly1[i][0])
              temp.append(poly1[i][1])
              poly.append(temp)
        for t in range(j,co2):
              temp=[]
              temp.append(poly2[j][0])
              temp.append(poly2[j][1])
              poly.append(temp)
        for i in range(len(poly)):
                   print(str(poly[i][0])+"x^"+str(poly[i][1])+" + ",end=" ")  
        return poly

# def multiple(poly1,poly2,co1,co2,hp1,hp2):
def mult(p,p1,m,y,n,x):
    reslt = []
    temp = [0] * (m*y)
    for i in range(m):
        for j in range(y):
            t = p[i][1] + p1[j][1]
            temp[t]+=(p[i][0] * p1[j][0])

    for i in range(0,n+x+1):
        c = []
        if(temp[i]!=0):
            c.append(temp[i])
            c.append(i)
        reslt.append(c)

    for i in range(len(reslt)):
        print(str(reslt[i][0])+"x^"+str(reslt[i][1])+" + ",end=" ")        



               
hp1=int(input("Enter the highest power: "))
co1=int(input("Enter the mumber of terms: "))
poly1=[]
for i in range(co1):
    temp=[]
    x=int(input("cofficient : "))
    y=int(input("Enter power: "))
    temp.append(x)
    temp.append(y)
    poly1.append(temp)

printPoly(poly1,co1)

hp2=int(input("Enter the highest power: "))
co2=int(input("Enter the mumber of terms: "))
poly2=[]
for i in range(co2):
    temp=[]
    x=int(input("cofficient : "))
    y=int(input("Enter power: "))
    temp.append(x)
    temp.append(y)
    poly2.append(temp)

printPoly(poly2,co2)

addition(poly1,poly2,co1,co2,hp1,hp2)
# multiple(poly1,poly2,co1,co2,hp1,hp2)
mult(poly1,poly2,co1,co2,hp1,hp2)


