m1=[]
r1=int(input("Row1:"))
c1=int(input("Column1:"))

for i in range(r1):
    temp=[]
    for j in range(c1):
        x=int(input())
        temp.append(x)
    m1.append(temp)

m2=[]

r2=int(input("Row2:"))
c2=int(input("Column2:"))

for i in range(r2):
    temp=[]
    for j in range(c2):
        x=int(input())
        temp.append(x)
        
    m2.append(temp)


def input(m,r,c):

    t=[]
    sp=[]
    t.append(r)
    t.append(c)
    t.append(0) 
    sp.append(t)
    cnt=0
    for i in range(r):
        for j in range(c):
            t=[]
            if(m[i][j]!=0):
                t.append(i)
                t.append(j)
                t.append(m[i][j])
                sp.append(t)
                cnt+=1

    sp[0][2]=cnt
    return sp


sp1=[]
sp2=[]

sp1=input(m1,r1,c1)
sp2=input(m2,r2,c2)

def output(sp):
    print("Row","Col","Value")
    for i in range(len(sp)):
        for j in range(3):
            print(sp[i][j],end="    ")
        print()

print("1st Sparse Matrix:")
output(sp1)
print("2nd Sparse Matrix:")
output(sp2)

def sum(sp1,r1,c1,sp2,r2,c2):

    if(r1!=r2 or c1!=c2):
        print("Addition is not possible")
    else:
        s=[]
        temp=[]
        temp.append(r1)
        temp.append(c1)
        temp.append(0)
        s.append(temp)
        cnt=0
        i=1
        j=1
        while(i<len(sp1) and j<len(sp2)):
            temp=[]

            if(sp1[i][0]==sp2[j][0]):
                if(sp1[i][1]==sp2[j][1]):
                    temp.append(sp1[i][0])
                    temp.append(sp1[i][1])
                    temp.append(sp1[i][2]+sp2[j][2])
                    i+=1
                    j+=1
                    cnt+=1

                elif(sp1[i][1]<sp2[j][1]):
                    temp.append(sp1[i][0])
                    temp.append(sp1[i][1])
                    temp.append(sp1[i][2])
                    i+=1
                    cnt+=1

                else:
                    temp.append(sp2[j][0])
                    temp.append(sp2[j][1])
                    temp.append(sp2[j][2])
                    j+=1
                    cnt+=1

            elif(sp1[i][0]<sp2[j][0]):
                temp.append(sp1[i][0])
                temp.append(sp1[i][1])
                temp.append(sp1[i][2])
                i+=1
                cnt+=1

            else:
                temp.append(sp2[j][0])
                temp.append(sp2[j][1])
                temp.append(sp2[j][2])
                j+=1
                cnt+=1

            s.append(temp)

        while(i<len(sp1)):
            temp=[]
            temp.append(sp1[i][0])
            temp.append(sp1[i][1])
            temp.append(sp1[i][2])
            i+=1
            cnt+=1
            s.append(temp)
        
        while(j<len(sp2)):
            temp=[]
            temp.append(sp2[j][0])
            temp.append(sp2[j][1])
            temp.append(sp2[j][2])
            j+=1
            cnt+=1
            s.append(temp)

        s[0][2]=cnt
        return output(s)


def transpose(sp):
    temp=[]
    tp=[]
    temp.append(sp[0][1])
    temp.append(sp[0][0])
    temp.append(sp[0][2])
    tp.append(temp)
    for i in range(sp[0][1]):
        for j in range(sp[0][2]):
            temp=[]
            if(i==sp[j+1][1]):
                temp.append(sp[j+1][1])
                temp.append(sp[j+1][0])
                temp.append(sp[j+1][2])
                tp.append(temp)

    return output(tp)

print("Transpose of Sparse Matrix:")
transpose(sp1)

def fast_transpose(sp):

    x=[0]*sp[0][1]

    for i in range(sp[0][2]):
        x[sp[i+1][1]]+=1

    rank=[]
    rank.append(1)
    for i in range(len(x)-1):
        rank.append(rank[i]+x[i])


    temp=[]
    tr=[]
    temp.append(sp[0][1])
    temp.append(sp[0][0])
    temp.append(sp[0][2])
    tr.append(temp)


    for i in range(sp[0][2]):
        temp=[]
        temp.append(0)
        temp.append(0)
        temp.append(0)
        tr.append(temp)

    for i in range(sp[0][2]):
        tr[rank[sp[i+1][1]]][0]=sp[i+1][1]
        tr[rank[sp[i+1][1]]][1]=sp[i+1][0]
        tr[rank[sp[i+1][1]]][2]=sp[i+1][2]
        rank[sp[i+1][1]]+=1

    return output(tr)

print("Fast transpose of Sparse Matrix:")
fast_transpose(sp1)