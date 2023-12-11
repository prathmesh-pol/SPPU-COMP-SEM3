
def linear_search(arr,roll_number):
    for i in range(len(arr)):
        if arr[i]==roll_number:
            return i
    return -1

def sentinel_search(arr, roll_number):
    size = len(arr)
    arr.append(roll_number)
    i = 0
    while(arr[i] != roll_number):
        i += 1
    if(i == size):
        return -1
    else:
        return i
        
def fibonacci_search(arr, roll_number):
    size = len(arr)
     
    start = -1
     
    f0 = 0
    f1 = 1
    f2 = 1
    while(f2 < size):
        f0 = f1
        f1 = f2
        f2 = f1 + f0
     
     
    while(f2 > 1):
        index = min(start + f0, size - 1)
        if arr[index] < roll_number:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif arr[index] > roll_number:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
        else:
            return index
    if (f1) and (arr[size - 1] == roll_number):
        return size - 1
    return -1

def binary_search(arr, low, high, x):
 
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1
 
p=int(input("enter the number of student"))
roll=[]
for i in range (0,p):
    item=int(input("enter the roll number of student"))
    roll.append(item)

froll=int(input("search roll number"))
print("1=linear search")
print("2=sentinel search")
print("3=fibonacci search")
print("4=binary seach")
k=int(input("function"))
if(k==1):
    linear_result=linear_search(roll,froll)
    if linear_result!=-1:
        print("attend",linear_result)
    else:
        print("not attend")
elif(k==2):
    sentinel_result=sentinel_search(roll,froll)
    if sentinel_result!=-1:
        print("attend",sentinel_result)
    else:
        print("not attend")
elif(k==3):
    fibonacci_result=fibonacci_search(roll,froll)
    if fibonacci_result!=-1:
        print("attend",fibonacci_result)
    else:
        print("not attend")
elif(k==4):
    binary_result=binary_search(roll,0,p-1,froll)
    if binary_result!=-1:
        print("attend",binary_result)
    else:
        print("not attend")




    