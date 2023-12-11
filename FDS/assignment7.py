arr=[]
brr=[]
crr=[]
drr=[]
import random
n=int(input("Enter number of elements:"))
print("Enter elements:")
for i in range(n):
    temp=random.randint(100,60000)
    arr.append(temp)
    brr.append(temp)
    crr.append(temp)
    drr.append(temp)


print('Original Array:')
print(arr)

print("0: Exit")
print("1: Selection Sort")
print("2: Bubble Sort")
print("3: Insertion Sort")
print("4: Shell Sort")

sorting=int(input("Sorting Method:"))

def selection(arr):
    
    comp=0
    swap=0
    # print(arr)
    for i in range(n):
        min=i
        f=0
        for j in range(i+1,n):
            comp=comp+1
            if(arr[j]<arr[min]):
                min=j
                f=1

        if(f==1):
            swap=swap+1
            temp=arr[min]
            arr[min]=arr[i]
            arr[i]=temp
            # print(arr)
    print(arr)
    print('Number of Comparisons:')
    print(comp)
    print('Number of swaping:')
    print(swap)


def bubble(brr):
    comp=0
    swap=0
    # print(brr)
    for i in range(n):
        for j in range(n-i-1):
            comp=comp+1
            if(brr[j]>brr[j+1]):
                swap=swap+1
                temp=brr[j]
                brr[j]=brr[j+1]
                brr[j+1]=temp
                # print(brr)
    print(brr)

    print('Number of Comparisons:')
    print(comp)
    print('Number of swaping:')
    print(swap)
   


def insertion(crr):

    # print(crr)
    comp=0
    for i in range(1,n):
        key=crr[i]
        j=i-1
        while(j>=0 and crr[j]>key):
            comp+=1
            crr[j+1]=crr[j]
            j-=1
        crr[j+1]=key
        # print(crr)      
    print(crr)
    print('Number of Comparisons:')
    print(comp)
    

def shell(drr):
    comp=0
    # print(drr)
    gap=int(n/2)

    while(gap>0):

        for i in range(gap,n):
            temp=drr[i]
            j=i
            while(j>=gap and drr[j-gap]>temp):
                comp+=1
                drr[j]=drr[j-gap]
                j-=gap

            drr[j]=temp

        gap=int(gap/2)

    print(drr)
    print('Number of Comparisons:')
    print(comp)
    


while(sorting!=0):
    if(sorting==1):
        print("----------Selection Sort----------:")
        selection(arr)
    elif(sorting==2):
        print("----------Bubble Sort----------:")
        bubble(brr)
    elif(sorting==3):
        print("----------Insertion Sort----------:")
        insertion(crr)
    elif(sorting==4):
        print("----------Shell Sort----------:")
        shell(drr)
        
    sorting=int(input("Sorting Method:"))
    
    
print("Exit")