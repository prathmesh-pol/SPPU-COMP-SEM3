# 8 Sorting 
# Algorithms:2
# a) Write a Python program to store marks of students in array. Write function for 
# sorting array of integers numbers in ascending order using `quick sort and display top 
# five scores.
# Display the array after each pass


def solve(a,low,high):
     pivot=a[low]
     i=low
     j=high
     while i<j:
           while i<high and a[i]<=pivot:
               i+=1
           while j>low and a[j]>=pivot:
               j-=1
           if i<j:
               a[i],a[j]=a[j],a[i]
     a[j],a[low]=a[low],a[j]
     return j



def quick(a,low,high):
    if low<high:
        p=solve(a,low,high)

        quick(a,low,p-1)
        quick(a,p+1,high)

n=int(input("Enter the totoal number of student : "))
a=[]
for i in range(n):
    x=int(input("Enter roll no : "))
    a.append(x)

print("without sort : ",a)

quick(a,0,n-1)
print(a)
