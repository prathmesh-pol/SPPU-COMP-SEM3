# 5 Matrix 
# operations
# Write python program to compute following operations on matrix
# a) Compute transpose of matrix
# b) Add and multiply two matrices
# c)determines the location of a saddle point if one exists.(An m x n matrix is said to 
# have a saddle point if some entry a[i][j] is the smallest value in
# row i and the largest value in j. )





def addition(mat1,mat2,n,m):
      print("---------------addition--------------------------")
      for i in range(n):
          for j in range(m):
              print(mat1[i][j]+mat2[i][j],end=" ")
          print(" ")
      return 0

def transpose(mat1,n,m):
    print("-------------transpose----------------")
    for i in range(m):
          for j in range(n):
              print(mat1[j][i],end=" ")
          print(" ")
    return 0

def multiply(mat1,mat2,n,m):
     print("------------multiply-------------")
     for i in range(n):
          for j in range(m):
               sum=0
               for k in range(m):
                    sum+=mat1[i][k]+mat2[k][j]
               print(sum,end=" ")
          print(" ")
     return 0

def saddle(mat1,n,m):
     print(" ------------saddle --------------")
 
     for i in range(n):
         larg=-1
         row=-1
         for j in range(m):
               if mat1[i][j]>larg:
                    larg=mat1[i][j]
                    row=j
         for k in range(n):
              if  mat1[k][row]<=larg:
                   return print(k,row)
         return print("no saddle point ")



n=int(input("Enter the row : "))
m=int(input("Row: "))
mat1=[]
for i in range(n):
    temp=[]
    for j in range(m):
        x=int(input("Enter number : "))
        temp.append(x)
    mat1.append(temp)

print("Enter the element of matrix 2 : ")
mat2=[]
for i in range(n):
    temp=[]
    for j in range(m):
        x=int(input("Enter number : "))
        temp.append(x)
    mat2.append(temp)

addition(mat1,mat2,n,m)
transpose(mat1,n,m)
multiply(mat1,mat2,n,m)
saddle(mat1,n,m)
