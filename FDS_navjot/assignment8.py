arr=[]

n=int(input("Enter number of elements:"))
print("Enter elements:")
for i in range(n):
    temp=int(input())
    arr.append(temp)


def partition(arr,low,high):

    pivot=arr[low]
    i=low
    j=high
    while(i<j):

        while(i<high and arr[i]<=pivot):
            i+=1

        while(j>low and arr[j]>=pivot):
            j-=1

        if(i<j):
            tp=arr[i]
            arr[i]=arr[j]
            arr[j]=tp
           
    
    tp=arr[low]
    arr[low]=arr[j]
    arr[j]=tp
    
    
    return j

def quickSort(arr,low,high):
    
  
    if(low<high):
        p=partition(arr,low,high)
        quickSort(arr,low,p-1)
        quickSort(arr,p+1,high)


    return arr


print(quickSort(arr,0,n-1))
