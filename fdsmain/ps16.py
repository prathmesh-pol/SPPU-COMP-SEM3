def bubbleSort(arr,n):
	for i in range(n-1):
		for j in range(n-i-1):
			if(arr[j]>arr[j+1]):
				temp=arr[j]
				arr[j]=arr[j+1]
				arr[j+1]=temp

		

def shellSort(arr,n):
	gap = int(n/2)
	while gap > 0:

		for i in range(gap,n):
			temp = arr[i]
			j = i
			while j >= gap and arr[j-gap] >temp:
				arr[j] = arr[j-gap]
				j -= gap
			arr[j] = temp
		gap =int(gap/2)

		
def arrayInput(arr):
    n=int(input("Enter no. of elements: "))
    print("Enter the elements")
    for i in range(n):
        x=int(input())
        arr.append(x)


print("1 for bubble sort")
print("2 for shell sort")
ch=int(input())
arr=[]
if(ch==1):
	arrayInput(arr)
	bubbleSort(arr,len(arr))	
elif(ch==2):
	arrayInput(arr)
	shellSort(arr,len(arr))			
print("Sorted array is:",arr)

