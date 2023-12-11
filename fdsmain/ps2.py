cric=[]
badm=[]
foot=[]
total=(int(input("Enter total no of students")))
cr=int(input("Enter the no of students who play cricket"))
bd=int(input("Enter the no of students who play badminton"))
ft=int(input("Enter the no of students who play football"))

print("Enter the roll no of students who play cric :")
for i in range(cr):
    temp=int(input())
    cric.append(temp)

print("Enter the roll no of students who play badminton :")
for i in range(bd):
    temp=int(input())
    badm.append(temp)

print("Enter the roll no of students who play football :")
for i in range(ft):
    temp=int(input())
    foot.append(temp)

#required sets ------------------
 
CB=[]
CORB=[]
NCNB=[]
CFNB=[]
N=[]
ALONE=[]
CFB=[]

#--------------------------------

for i in range(total):
    if (i in cric and i in badm):
        CB.append(i)
    if (i in cric or i in badm):
        CORB.append(i)
    if (i not in cric and i not in badm):
        NCNB.append(i)
    if (i in cric and i in foot and i not in badm):
        CFNB.append(i)
    if (i not in cric and i not in foot and i not in badm):
        N.append(i)
    if (i  in cric or i in foot or i in badm):
        ALONE.append(i)
    if (i  in cric and i  in foot and i in badm):
        CFB.append(i)

print(CB)
print(CORB)
print(NCNB)
print(CFNB)
print(N)
print(ALONE)
print(CFB)

    