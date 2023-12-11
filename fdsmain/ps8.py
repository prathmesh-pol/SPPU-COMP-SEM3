marks=[]
n=int(input("Enter the number of students to enter marks"))

print("Enter Marks : \n")
for i in range(n):
    temp=int(input())
    marks.append(temp)

def partition(arr,low,high):
    piviot=arr[low]
    i=low
    j=high
    while(i<j):
        while(i<high and arr[i]<=piviot):
            i=i+1
        while(j>low and arr[j]>=piviot):
            j+=1
        
        if(i<j):
            arr[i],arr[j]=arr[j],arr[i]
    arr[low],arr[j]=arr[j],arr[low]
    
    return j
    


def quickSort(arr, low,high):
    if(low<high):
        p=partition(arr,low,high)
        quickSort(arr,low,p-1)
        quickSort(arr,p+1,high)


quickSort(marks,0,len(marks)-1)
print(marks)