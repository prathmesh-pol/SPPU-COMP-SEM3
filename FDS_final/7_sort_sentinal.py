# 7 Sorting 
# Algorithms:1
# Write a Python program to store marks of students in array. Write function for 
# sorting array of integer numbers in ascending order using
# a) Selection Sort 
# c) Insertion sort


def selection(a,n):

    for i in range(n-1):
        min=a[i]
        index=i
        for j in range(i+1,n):
            if a[j]<min:
                min=a[j]
                index=j
        a[i],a[j]=a[j],a[i]
    return print("selection ",a)

def insertion(a,n):
    
    for i in range(1,n):
        j=i-1
        temp=a[i]
      
        while j>=0 and a[j]>temp:
            a[j+1]=a[j]
            j-=1
        a[j+1]=temp
    return print("insertion: ",a)




n=int(input("Enter the totoal number of student : "))
a=[]
for i in range(n):
    x=int(input("Enter roll no : "))
    a.append(x)

print("without sort : ",a)

selection(a,n)
insertion(a,n)
