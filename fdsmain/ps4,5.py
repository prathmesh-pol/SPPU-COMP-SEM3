print("Enter order of matrix_1:")
m=int(input("Enter value of m:"))
n=int(input("Enter value of n:"))
matrix1=[]
matrix2=[]


print("Enter value of matrix_1:")
for i in range(m):
    temp=[]
    for i in range(n):
        num=int(input())
        temp.append(num)

    matrix1.append(temp)

print("Enter order of matrix_2:")
a=int(input("Enter value of a:"))
b=int(input("Enter value of b:"))

print("Enter value of matrix_2:")
for i in range(a):
    temp=[]
    for i in range(b):
        num=int(input())
        temp.append(num)

    matrix2.append(temp)
###############
def uppertriangular(matrix):
    f=0
    for i in range(m):
        for j in range(n):
            if(i>j):
                if(matrix[i][j]!=0):
                    f=1
                    break
        
        if(f==1):
            print("Given matrix is Non-upper triangular matrix")
            break

    if(f==0):
        print("Given matrix is upper triangular matrix")




def diagonal_sum(matrix):
    sum=0
    for i in range(m):
        for j in range(n):
            if(i==j):
                sum=sum+matrix[i][j]

    return sum


def transpose(matrix):
    trans=[]
    for i in range(m):
        temp1=[]
        for j in range(n):
            temp1.append(matrix[j][i])

        trans.append(temp1)

    return trans



def addition(m1,m2):
    add=[]
    for i in range(len(m1)):
        for j in range(len(m2)):
            add.append(m1[i][j]+m2[i][j])

    return add




def substraction(m1,m2):
    sub=[]
    for i in range(len(m1)):
        for j in range(len(m2)):
            sub.append(m1[i][j]-m2[i][j])

    return sub




def multiplication(m1,m2):
    result=[]
    for i in range(len(m1)):
        r=[]
        for j in range(len(m2[0])):
            r.append(int(0))

        result.append(r)


    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m2)):
                result[i][j]+= (m1[i][k]*m2[k][j])
    return result


def saddle(matrix):

    for i in range(len(matrix)):
        min_row = matrix[i][0]
    
        ind_y=0
        for j in range(1, len(matrix)):
            if (min_row > matrix[i][j]):
                min_row = matrix[i][j]
                ind_y = j

       
        k = 0
        for k in range(len(matrix)):
            if (min_row >= matrix[k][ind_y]):
                k += 1
          
    if (k == len(matrix)):
        print("Value of Saddle Point ",min_row)
        
    elif(k!=len(matrix)):
        print("No saddle point found")

    
    

def magic(matrix):

    
    sumd1=0
    sumd2=0
    p=len(matrix)
    for i in range(p):
        sumd1+= matrix[i][i]
        sumd2+= matrix[p-i-1][i]


    f=0
    for i in range(p):
        sum_r=0
        sum_c=0
        for j in range(p):
            sum_r+= matrix[i][j]
            sum_c+= matrix[j][i]

        if(sum_c!=sum_r and sum_r!=sumd1):
            f=1
            break

    if(f==0):
        print("Given matrix is a Magic square matrix")

    else:
        print("Given matrix is not a Magic square matrix")

uppertriangular(matrix1)
print("Diagonal sum is:",diagonal_sum(matrix1))
print("Transpose of given matrix is:",transpose(matrix1))
print("Addition of two given matrix is",addition(matrix1,matrix2))
print("Substraction of two given matrix is:",substraction(matrix1,matrix2))
print("Multiplication of two given matrix is:",multiplication(matrix1,matrix2))
saddle(matrix1)
magic(matrix1)

