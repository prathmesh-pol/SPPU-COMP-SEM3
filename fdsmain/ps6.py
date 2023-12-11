list=[]
n=int(input("Enter the total no of students who attended the session : \n"))

print("Enter the roll no of students who attended the session")
for i in range(n):
    temp=int(input())
    list.append(temp)

flag=int(input("Enter the element that is to be searched"))
# (A)-------------------------------------

def sentinel(list,c):

    list.append(c)
    i = 0
    while(list[i] != c):
        i += 1
    if(i!=len(list)-1):
        print("the number was present")
    else:
        print("the number was not present")
    list.pop()

sentinel(list,flag)

# (B)-------------------------------------
def binary(list,flag):
    c=0
    list.sort()
    l = 0
    h = len(list) - 1
    while((h-l)>=0):
        mid = int((l+h)/2)
        if(flag == list[mid]):
            c = 1
            print("the number was found")
            break
        elif(flag<list[mid]):
            h = mid - 1
        else:
            l = mid + 1
    if(c==0):
            print("the number was not found")
        
binary(list,flag)