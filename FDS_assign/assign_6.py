n=int(input("Enter the number of students in class : "))
arr=[]
for i in range(0,n):
    tt=int(input("Enter roll no. of student : "))
    arr.append(tt)
key=int(input("Enter the key to be searched : "))    

#----------------------------------LINEAR SEARCH--------------------------------------------
def linear(n,arr,key):
    flag=False
    temp=0
    for i in range(0,n):
        if(arr[i]==key):
            flag=True
            temp=i
            break
    if(flag==False):
        print("Key not found!!!")
    else :
        print("Key found at : ",temp)

#---------------------------------SENTINEL SEARCH------------------------------------------
def sentinel(n,arr,key):
    arr.append(key)
    # last=arr[n-1]
    # arr[n-1]=key
    cnt=0
    while(arr[cnt]!=key):
        cnt+=1
    if(cnt<=n-1):
        print("Key found at : ",cnt)
    else:
        print("Key not found !!!")

#-----------------------------------BINARY SEARCH-------------------------------------------
def binary(n,arr,key):
    arr.sort()
    ini=0
    lst=n-1
    index=-1
    while(ini<lst):
        mid=(ini+lst)//2
        print("Mid index : ",mid)
        if(arr[mid]>key):
            lst=mid-1
        elif(arr[mid]<key):
            ini=mid+1
        else:
            index=mid
            break
        print("Mid index : ",mid)
        print("Starting index : ",ini)
        print("Last index : ",lst)
        print("....................")
    if(index!=-1):
       print("Key found at : ",index)
    else:
       print("Key not found !!!")

#------------------------------------FIBONACCI SEARCH----------------------------------------
def fibonacci(n,arr,key):
    arr.sort()
    offset=-1
    index=-1
    ind=0
    fib2=0
    fib1=1
    fib0=1
    flag=False
    while(fib0<n):
        fib2=fib1
        fib1=fib0
        fib0=fib1+fib2
    
    # print("ind : ",ind)
    # print(fib2," ",fib1," ",fib0)
    while(fib0>1):
        ind=min((fib2+offset),n-1)
        if(key<arr[ind]):
            fib0=fib2
            fib1-=fib2
            fib2=fib0-fib1
            print("chk1",fib2,fib1,fib0)
        elif(key>arr[ind]):
            fib0=fib1
            fib1=fib2
            fib2=fib0-fib1
            print("chk2",fib2,fib1,fib0)
            offset=ind
        else:
            index=ind
            flag=True
            break

    if(fib1 and arr[offset+1]==key):
        print("Key found  : ",offset+1)
    else:
        print("Key not found!!!")

ip=int(input("Enter the query 1.linear 2.Sentinel  3.Binary  4.Fibonacci "))
if(ip==1):
    linear(n,arr,key)
elif(ip==2):
    sentinel(n,arr,key)
elif(ip==3):
    binary(n,arr,key)
elif(ip==4):
    fibonacci(n,arr,key)
else:
    print("Enter a valid key !!!")    
  