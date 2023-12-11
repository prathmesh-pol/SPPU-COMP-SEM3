# 10 Sparse matrix 
# operations
# Write Python program for sparse matrix representation and operations on it- Simple 
# Transpose, Fast Transpose 

def transpose(sprase):
      tr=[]
      tem=[]
      tem.append(sprase[0][0])
      tem.append(sprase[0][1])
      tem.append(sprase[0][1])
      tr.append(tem)

      for i in range(0,sprase[0][0]):
           for j in range(0,sprase[0][2]):
                if sprase[j][1]==i:
                      temp=[]
                      temp.append(i)
                      temp.append(sprase[j][0])
                      temp.append(sprase[j][2])
                      tr.append(temp)
      return tr


def Fast_transpse(matrix,row,cal,val):
     transA=[]
     index=[]
     total=[]

     for i in range(cal):
          total.append(0)

     for i in range(cal):
          total[matrix[i][1]]+=1
     print("total ",total)


     index.append(1)
     for i in range(1,cal+1):
          index.append(total[i-1]+index[i-1])
     print("index ",index)

     temp=[]
     temp.append(c)
     temp.append(r)
     temp.append(val)
     transA.append(temp)

     for i in range(1,val+1):
           temp=[]
           temp.append(0)
           temp.append(0)
           temp.append(0)
           transA.append(temp)

     for i in range(0,val):
          transA[index[matrix[i][1]]][0]=matrix[i][1]
          transA[index[matrix[i][1]]][1]=matrix[i][0]
          transA[index[matrix[i][1]]][2]=matrix[i][2]

     print(transA)

          


     
r=int(input("Enter row : "))
c=int(input("Enter column: "))
val=0
matrix=[]
for i in range(r):
    temp=[]
    for j in range(c):
         x=int(input("Enter element of matrix : "))
         if x!=0:
              val+=1
         temp.append(x)
    matrix.append(temp)

sprase=[]
# tem=[]
# tem.append(r)
# tem.append(c)
# tem.append(val)
# sprase.append(tem)

for i in range(r):
     for j in range(c):
          
          if matrix[i][j]!=0:
               temp=[]
               temp.append(i)
               temp.append(j)
               temp.append(matrix[i][j])
               sprase.append(temp)
               
print("sparse matrix is : " ,sprase)
# print("trans: ")
# print(transpose(sprase))

print("Fast transpose : ")
print(Fast_transpse(sprase,r,c,val))

               