# 11 Sparse matrix 
# operations
# Write Python program for sparse matrix representation and operations on it- Simple 
# Transpose, and addition of two matrices

row1=int(input("Enter number of rows of first matrix : "))
col1=int(input("Enter number of column of first matrix : "))

matrix1=[]
count1=0
for i in range (0,row1):
    temp=[]
    for j in range (0,col1):
        ele=int(input())
        if(ele>0):
            temp=[]
            temp.append(i)
            temp.append(j)
            temp.append(ele)
            count1+=1
            matrix1.append(temp)

row2=int(input("Enter number of rows of second matrix : "))
col2=int(input("Enter number of column of second matrix : "))


matrix2=[]
count2=0
for i in range (0,row2):
    temp=[]
    for j in range (0,col2):
        ele=int(input())
        if(ele>0):
            temp=[]
            temp.append(i)
            temp.append(j)
            temp.append(ele)
            count2+=1
            matrix2.append(temp)

print(" ")            
print("SUM :")
print(" ")   
print("R        c       v")

i=int(0)
j=int(0)
count=0

sum=[]
while(i<count1 and j<count2):
    if(matrix1[i][0]==matrix2[j][0]):
        if(matrix1[i][1]==matrix2[j][1]):
            temp=[]
            temp.append(matrix1[i][0])
            temp.append(matrix1[i][1])
            temp.append(matrix1[i][2]+matrix2[j][2])
            sum.append(temp)
            i+=1
            j+=1
            count+=1
        else:
            if(matrix1[i][1]<matrix2[j][1]):
                temp=[]
                temp.append(matrix1[i][0])
                temp.append(matrix1[i][1])
                temp.append(matrix1[i][2])
                sum.append(temp)
                i+=1
                count+=1
            else:
                temp=[]
                temp.append(matrix2[j][0])
                temp.append(matrix2[j][1])
                temp.append(matrix2[j][2])
                sum.append(temp)
                j+=1
                count+=1
    else:
        if(matrix1[i][0]<matrix2[j][0]):
            temp=[]
            temp.append(matrix1[i][0])
            temp.append(matrix1[i][1])
            temp.append(matrix1[i][2])
            sum.append(temp)
            i+=1
            count+=1
        else:
            temp=[]
            temp.append(matrix2[j][0])
            temp.append(matrix2[j][1])
            temp.append(matrix2[j][2])
            sum.append(temp)
            j+=1
            count+=1


for k in range(i,count1):
    temp=[]
    temp.append(matrix1[k][0])
    temp.append(matrix1[k][1])
    temp.append(matrix1[k][2])
    sum.append(temp)
    i+=1
    count+=1

for k in range (j,count2):
    temp=[]
    temp.append(matrix2[k][0])
    temp.append(matrix2[k][1])
    temp.append(matrix2[k][2])
    sum.append(temp)
    j+=1
    count+=1

templist=[]
templist.append(row1)
templist.append(col1)
templist.append(count)
sum.append(templist)




print(sum[count][0],"\t",sum[count][1],"\t",sum[count][2])
for i in range (0,count):
    print(sum[i][0],"\t",sum[i][1],"\t",sum[i][2])

print()

print(" ")

#TRANSPOSE

print("TRANSPOSE:")
print(" ")   
print("R        c       v")

trans=[]

for i in range (0,col1):
    for j in range (0,count1):
        if (matrix1[j][1]==i):
            temp=[]
            temp.append(matrix1[j][1])
            temp.append(matrix1[j][0])
            temp.append(matrix1[j][2])
            trans.append(temp)

temp=[]
temp.append(col1)
temp.append(row1)
temp.append(count1)
trans.append(temp)


print(trans[count1][0],"\t",trans[count1][1],"\t",trans[count1][2])
for i in range (0,count1):
    print(trans[i][0],"\t",trans[i][1],"\t",trans[i][2])

print(" ")


#FAST TRANSPOSE

print("FAST TRANSPOSE :")
print(" ")   

transA=[]
index=[]
total=[]
count=0

for i in range(0,col1):
    total.append(0)

for i in range (count1):
    total[matrix1[i][1]]+=1

print("Total=\t",total)

index.append(1)

for i in range (1,col1+1):
    index.append(total[i-1]+ index[i-1])
print("Index=\t" ,index)
print(" ")   

print("R        c       v")

temp=[]
temp.append(col1)
temp.append(row1)
temp.append(count1)
transA.append(temp)

for i in range (1,count1+1):
    temp=[]
    temp.append(0)
    temp.append(0)
    temp.append(0)
    transA.append(temp)

for i in range (0,count1):
    transA[index[matrix1[i][1]]][0]=matrix1[i][1]
    transA[index[matrix1[i][1]]][1]=matrix1[i][0]
    transA[index[matrix1[i][1]]][2]=matrix1[i][2]
  

for i in range (0,count1+1):
    print(transA[i][0],"\t",transA[i][1],"\t",transA[i][2])





