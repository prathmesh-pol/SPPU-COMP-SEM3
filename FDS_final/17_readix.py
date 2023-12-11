# 17 Sorting 
# Algorithms:2
# Write a Python program to store marks of students in array. Write function for 
# sorting array of integer numbers in ascending order using radix sort


def counting_sort(a,exp):
     n=len(a)
     out=[0]*n
     cnt=[0]*10

     for i in range(n):
          cnt[(a[i]//exp)%10]+=1
     for i in range(1,10):
          cnt[i]=cnt[i]+cnt[i-1]

     for i in range(n-1,-1,-1):
          out[cnt[(a[i]//exp)%10]-1]=a[i]
          cnt[(a[i]//exp)%10]-=1

     print(out)
     return

def readix(a,n):
     x=max(a)
     exp=1
     while x//exp>0 :
          counting_sort(a,exp)
          exp*=10


n=int(input("Enter the totoal number of student : "))
a=[]
for i in range(n):
    x=int(input("Enter roll no : "))
    a.append(x)

print("without sort : ",a)

readix(a,n)
