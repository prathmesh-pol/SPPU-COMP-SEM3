def Linear_Search(n, roll, students):
    for i in range(0, n):
        if(students[i]==roll):
            return True 
    return False

def Fibbonaci_Search(n, roll, students):
    a = 0
    b = 1
    while(b<n):
        a = b
        b = a+b
        
    offset = -1
    while(b>1):
        i = min(offset+a, n-1)
        
        if (roll > students[i]):
            a = b-a
            b = a
            offset = i
        elif(roll < students[i]):
            a = b-a
            b = b-a
        else:
            return True

    if(b and students[offset+1] == roll):
        return (offset+1)

    return False


n = int(input("Enter the number of Students : "))
students=[]
for i in range(0, n):
    k = int(input())
    students.append(k)


roll = int(input("Enter the roll_no of Student to find : "))
print()

print("----------Menu----------")
print("0. Quit")
print("1. Linear_Search")
print("2. Fibbonaci_Search")
print()

while(True):
    choice = int(input("Enter a choice : "))
    if(choice==0):
        print("Quit")
        break
    elif(choice==1):
        check = Linear_Search(n, roll, students)
        if(check):
            print("The Student attended the Training Program.")
        else:
            print("The Student did not attend the Training Program.")
    else:
        check = Fibbonaci_Search(n, roll, students)
        if(check):
            print("The Student attended the Training Program.")
        else:
            print("The Student did not attend the Training Program.")
    print()