# 16 Sorting 
# Algorithms:1
# Write a Python program to store first year percentage of students in array. Write 
# function for sorting array of floating-point numbers in ascending order using
# a) Bubble sort 
# b) Shell Sort 
# Display the array after each pass.

def Bubble(a,n):
  for j in range(n):
    for i in range(n-1):
        if a[i]>a[i+1]:
             a[i],a[i+1]=a[i+1],a[i]
  print("Bubble : ",a)
       

def shell(a,n):
    gap=n//2
    j=gap
    while(gap>0):
        for i in range(gap,n):
              j=i
              temp=a[j]
              while j>=gap and a[j-gap]>temp:
                     a[j]=a[j-gap]
                     j=j-gap
              a[j]=temp
        gap=gap//2
    print("shell : ",a)


n=int(input("Enter the totoal number of student : "))
a=[]
for i in range(n):
    x=int(input("Enter roll no : "))
    a.append(x)

print("without sort : ",a)

Bubble(a,n)
shell(a,n)