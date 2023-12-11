# 3 Searching 
# algorithms
# a) Write a Python program to store roll numbers of student in array who attended 
# training program in random order. Write function for searching whether particular 
# student attended training program or not using linear search.
# b) Write a Python program to store roll numbers of student array who attended 
# training program in sorted order. Write function for searching whether particular 
# student attended training program or not using Fibonacci search

def linear(a,n,key):
    for i in range(n):
        if a[i]==key:
            return 1
    return -1

def fibonacci(a,n,key):
    fmin=0
    fb=1
    fmax=fmin+fb
    offset=-1
    while(fmax<n):
         fmin=fb
         fb=fmax
         fmax=fb+fmin

    while fmax>1:
         i=min(offset+fmin,n-1)
         if a[i]==key:
             return 1
         elif a[i]<key:
             fmax=fb
             fb=fmin
             fmin=fmax-fmin

             offset=i  

         elif a[i]>key:
             fmax=fmin
             fb=fb-fmin
             fmin=fmax-fb
         else:
             return -1
         
    if(fb and a[offset+1]==key):
          return 1
    else:
        return -1


             
n=int(input("Enter the totoal number of student : "))
a=[]
for i in range(n):
    x=int(input("Enter roll no : "))
    a.append(x)

key=int(input("Enter roll number of student those you want to serch : "))
print("Enter 1 for linear search : ")
print("Enter 2 for fibonacci search : ")
choice=int(input("Enter your choice : "))

if choice==1:
    print(linear(a,n,key))
elif choice==2:
    print(fibonacci(a,n,key))