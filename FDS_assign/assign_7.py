n=int(input("Enter the number of elements in array : "))
arr=[]
for i in range(0,n):
    tt=int(input("Enter entries : "))
    arr.append(tt)
def bubble(arr,n):
    swap=0
    print("Sorted using bubble sort : ")
    for i in range (0,n-1):
       flag=False
       for j in range(0,n-i-1):
           if(arr[j]>arr[j+1]):
               flag=True
               temp=arr[j]
               arr[j]=arr[j+1]
               arr[j+1]=temp
               swap+=1
       print(arr)
       if(flag==False):
           break
    print("Number of swaps : ",swap)

def selection(arr,n):
    swap=0
    cp=0
    print("Sorted using selection sort : ")
    for i in range(0,n):
        # print(arr)
        ind=-1
        min=arr[i]
        for j in range(i,n):
            if(arr[j]<min):
                min=arr[j]
                ind=j
                cp+=1
        if(ind==-1):
            continue
        else:
            arr[ind]=arr[i]
            arr[i]=min
            swap+=1
        print(arr)
    print("Number of swaps : ",swap)
    print("Number of comparisions : ",cp)
        
def inst(arr,n):
    swap=0
    shift=0
    print("Sorted using Insertion Sort : ")
    for i in range(1,n):
        temp=arr[i]
        j=i-1
        while(j>=0 and arr[j]>temp):
            arr[j+1]=arr[j]
            shift+=1
            j-=1
        arr[j+1]=temp            
        print(arr)
    print("Number of shifts : ",shift)                

def shell(arr,n):
    dist=n//2
    pss=0
    shift=0
    print("Sorted using Shell Sort : ")
    print(arr)
    while(dist>0):
      pss+=1
      for i in range(dist,n):
        temp=arr[i]
        j=i-dist
        while(j>=0 and arr[j]>temp):
            arr[j+dist]=arr[j]
            shift+=1
            j-=dist
        arr[j+dist]=temp            
      print(arr)
      dist=dist//2
    print("Number of passes : ",pss)
    print("Number of shifts : ",shift)


ip=int(input("Enter choice : 1.Bubble  2.Selection 3.Insertion  4.Shell:"))
if(ip==1):
    bubble(arr,n)
elif(ip==2)    :
    selection(arr,n)
elif(ip==3)    :
    inst(arr,n)
elif(ip==4)    :
    shell(arr,n)
else:
    print("Invalid Key !!! ")    