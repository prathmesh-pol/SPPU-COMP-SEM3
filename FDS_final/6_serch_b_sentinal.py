# 6 Searching 
# algorithms
# a) Write a Python program to store roll numbers of student in array who attended 
# training program in random order. Write function for searching whether particular 
# student attended training program or not using sentinel search.
# b) Write a Python program to store roll numbers of student array who attended 
# training program in sorted order. Write function for searching whether particular 
# student attended training program or not using binary search.


def binary(a,n,key):
     print("---binary-------")
     s=0
     e=n
     while(s<e):
         mid=(s+e)//2
         if a[mid]<key:
             s=mid+1
         elif a[mid]>key:
             e=mid-1
         else:
             return mid
     return -1


   
def sentinel(a,n,key):
    print("------sentinel--------")
    a.append(key)
    i=0
    while(a[i]!=key):
        i+=1
    if i==key:
        return -1
    else:
        return i



             
n=int(input("Enter the totoal number of student : "))
a=[]
for i in range(n):
    x=int(input("Enter roll no : "))
    a.append(x)
while(1):
     key=int(input("Enter roll number of student those you want to serch : "))
     print("Enter 1 for binary search : ")
     print("Enter 2 for sentinel search : ")
     choice=int(input("Enter your choice : "))
     
     if choice==1:
         print(binary(a,n,key))
     elif choice==2:
         print(sentinel(a,n,key))
         