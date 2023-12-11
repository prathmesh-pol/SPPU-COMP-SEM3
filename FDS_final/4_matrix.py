# 4 Matrix 
# operations
# Write python program to compute following operations on matrix
# a) Add and multiply two matrices
# b) Check whether given matrix is upper triangular or not
# c)Check if its magic square (A magic square is an n * n matrix of the integers 1 to 
# n2 such that the sum of each row, column, and diagonal is the same


def addition(mat1,mat2,n,m):
      for i in range(n):
          for j in range(m):
              print(mat1[i][j]+mat2[i][j],end=" ")
          print(" ")
      return 0

def upper_trangular(mat1,n,m):
      for i in range(n):
          for j in range(m):
                 if i>j and mat1[i][j]!=0:
                      return -1
      return print("It is a upper trangular")


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
upper_trangular(mat1,n,m)