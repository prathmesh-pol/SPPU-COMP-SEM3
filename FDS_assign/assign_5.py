r1=int(input("Enter no. of rows of first matrix : "))
c1=int(input("Enter no. of columns of first matrix : "))

mat1=[]
cnt1=0
for i in range (0,r1):
    temp1=[]
    for j in range (0,c1):
        tt=int(input())
        if(tt!=0):
            temp=[]
            temp.append(i)
            temp.append(j)
            temp.append(tt)
            cnt1+=1
            mat1.append(temp)

r2=int(input("Enter no. of rows of second matrix : "))
c2=int(input("Enter no. of columns of second matrix : "))

mat2=[]
cnt2=0
for i in range (0,r2):
    temp=[]
    for j in range (0,c2):
        tt=int(input())
        if(tt>0):
            temp=[]
            temp.append(i)
            temp.append(j)
            temp.append(tt)
            cnt2+=1
            mat2.append(temp)

#----------------------------------------------------------------------------------------            
#sum of sparse matrix
i=int(0)
j=int(0)
count=0
sum=[]
while(i<cnt1 and j<cnt2):
    if(mat1[i][0]==mat2[j][0]):
        if(mat1[i][1]==mat2[j][1]):
            temp=[]
            temp.append(mat1[i][0])
            temp.append(mat1[i][1])
            temp.append(mat1[i][2]+mat2[j][2])
            sum.append(temp)
            i+=1
            j+=1
            count+=1
        else:
            if(mat1[i][1]<mat2[j][1]):
                temp=[]
                temp.append(mat1[i][0])
                temp.append(mat1[i][1])
                temp.append(mat1[i][2])
                sum.append(temp)
                i+=1
                count+=1
            else:
                temp=[]
                temp.append(mat2[j][0])
                temp.append(mat2[j][1])
                temp.append(mat2[j][2])
                sum.append(temp)
                j+=1
                count+=1
    else:
        if(mat1[i][0]<mat2[j][0]):
            temp=[]
            temp.append(mat1[i][0])
            temp.append(mat1[i][1])
            temp.append(mat1[i][2])
            sum.append(temp)
            i+=1
            count+=1
        else:
            temp=[]
            temp.append(mat2[j][0])
            temp.append(mat2[j][1])
            temp.append(mat2[j][2])
            sum.append(temp)
            j+=1
            count+=1


for k in range(i,cnt1):
    temp=[]
    temp.append(mat1[k][0])
    temp.append(mat1[k][1])
    temp.append(mat1[k][2])
    sum.append(temp)
    i+=1
    count+=1

for k in range(j,cnt2):
    temp=[]
    temp.append(mat2[k][0])
    temp.append(mat2[k][1])
    temp.append(mat2[k][2])
    sum.append(temp)
    j+=1
    count+=1
        
templist=[]
templist.append(r1)
templist.append(c1)
templist.append(count)
sum.append(templist)

print("Sum of given sparse matrices is : ")
print(sum[count][0],"\t",sum[count][1],"\t",sum[count][2])
for i in range (0,count):
    print(sum[i][0],"\t",sum[i][1],"\t",sum[i][2])

print()

#---------------------------------------------------------------------------------------
#Transpose of sparse matrix
trans=[]

for i in range (0,c1):
    for j in range (0,cnt1):
        if(mat1[j][1]==i):
            temp=[]
            temp.append(mat1[j][1])
            temp.append(mat1[j][0])
            temp.append(mat1[j][2])
            trans.append(temp)
            
temp=[]
temp.append(c1)
temp.append(r1)
temp.append(cnt1)
trans.append(temp)
print("Transpose of given matrix is : ")
print(trans[cnt1][0],"\t",trans[cnt1][1],"\t",trans[cnt1][2])
for i in range (0,cnt1):
    print(trans[i][0],"\t",trans[i][1],"\t",trans[i][2])
    
#--------------------------------------------------------------------------------------
#Implementation of fast transpose
tr1=[]
index=[]
total=[]
count=0

for i in range(0,c1):
    total.append(0)

for i in range (0,cnt1):
    total[mat1[i][1]]+=1

#print("total=\t",total)

index.append(1)

for i in range (1,c1+1):
   index.append(total[i-1]+index[i-1])
# print("index=\t" ,index)
    
temp=[]
temp.append(c1)
temp.append(r1)
temp.append(cnt1)
tr1.append(temp)


for i in range (1,cnt1+1):
    temp=[]
    temp.append(0)
    temp.append(0)
    temp.append(0)
    tr1.append(temp) 
    
for i in range (0,cnt1):
    tr1[index[mat1[i][1]]][0]=mat1[i][1]
    tr1[index[mat1[i][1]]][1]=mat1[i][0]
    tr1[index[mat1[i][1]]][2]=mat1[i][2]
    index[mat1[i][1]]+=1

print("Fast Transpose of given matrix is : ")
for i in range (0,cnt1+1):
    print(tr1[i][0],"\t",tr1[i][1],"\t",tr1[i][2])
