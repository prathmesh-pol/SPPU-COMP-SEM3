# Do not touch my code
cricket=[]
badminton=[]
football=[]
total_students=int(input("Total nuber of students:"))
cr=int(input("No. of students who play cricket:"))
bd=int(input("No. of students who play badminton:"))
fb=int(input("No. of students who play football:"))

print("Enter roll number who play cricket:")
for i in range(0,cr):
    temp=int(input())
    cricket.append(temp)

print("Enter roll number who play badminton:")
for i in range(0,bd):
    temp=int(input())
    badminton.append(temp)

print("Enter roll number who play football:")
for i in range(0,fb):
    temp=int(input())
    football.append(temp)

def intersection_2(a,b):
    common2=[]
    for i in range(len(a)):
        for j in range(len(b)):
            if(a[i]==b[j]):
                common2.append(a[i])

    return common2

def intersection_3(a,b,c):
    common3=[]
    for i in range(len(a)):
        for j in range(len(b)):
            for k in range(len(c)):
                if(a[i]==b[j] and b[j]==c[k]):
                    common3.append(a[i])

    return common3

def remove_2(a,b):
    remove2=[]

    f=0
    for i in range(len(a)):
        for j in range(len(b)):
            if(b[j]==a[i]):
                f=1
                break

        if(f==0):
            remove2.append(a[i])

        else:
            f=0


    f1=0
    for i in range(len(b)):
        for j in range(len(a)):
            if(b[i]==a[j]):
                f1=1
                break

        if(f1==0):
            remove2.append(b[i])

        else:
            f1=0

    return remove2


def three_func(a,b,c):

    temp=intersection_2(a,b)

    temp1=remove_2(c,temp)
    x=(len(temp)+len(c)-len(temp1))//2

    return x


def all_game(a,b,c):
    all=[]

    for i in range(len(a)):
        all.append(a[i])


    for i in range(len(b)):
        all.append(b[i])


    for i in range(len(c)):
        all.append(c[i])


    return all

print("List of students who play both cricket and badminton:",intersection_2(cricket,badminton))
print("List of students who play either cricket or badminton but not both:",remove_2(cricket,badminton))
print("Number of students who play neither cricket nor badminton:",total_students-cr-bd)
print("Number of students who play cricket and football but not badminton:",three_func(cricket,football,badminton))
print("Number of students who do not play any game:",total_students-cr-bd-fb)
print("List of students who play atleast one game:",all_game(cricket,badminton,football))
print("List of students who play all three games:",intersection_3(cricket,football,badminton))