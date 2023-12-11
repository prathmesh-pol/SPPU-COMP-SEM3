# 2 Set 
# Operations
# In second year computer engineering class, group A student’s play cricket, group B 
# students play badminton and group C students play football. Write a Python 
# program using functions to compute following: - 
# a) List of students who play both cricket and badminton 
# b) List of students who play either cricket or badminton but not both 
# c) Number of students who play neither cricket nor badminton 
# d) Number of students who play cricket and football but not badminton. 
# e) Number of students who do not play any game 
# f) List of students who play at least one game 
# g) List of students who play all three games. 
# (Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions)


def  cb(cricket,badminton,c):
    cb=[]
    for i in range(n+1):
        if i in cricket and i in badminton:
             cb.append(i)
    return cb

def corb(Cricket,badminton,n):
     corb=[]
     for i in range(n+1):
         if (i in cricket and i not in badminton) or(i in badminton and i not in cricket):
              corb.append(i)
     return corb

def cfnb(cricket,footboll,badminton,n):
     cfnb=[]
     for i in range(n+1):
         if (i in cricket)and (i in footboll) and (i not in badminton):
                cfnb.append(i)
     return cfnb

def nogame(cricket,badminton,footboll,n):
      nogame=[]
      for i in range(n+1):
           if i not in cricket and i not in badminton and i not in footboll:
                nogame.append(i)
      return nogame

def ncnb(cricket,badminton,n):
     ncnb=[]
     cb=[]
     for i in range(n+1):
        if i in cricket and i in badminton:
             cb.append(i)
     return n-(len(cricket)+len(badminton)-len(cb))

def atleast(cricket,badminton,footboll,n):
       atleast=[]
       for i in range(n+1):
            if i in cricket or i in badminton or i in footboll:
                  atleast.append(i)
       return(atleast)

def all(cricket,badminton,footboll,n):
       all=[]
       for i in range(n+1):
            if i in cricket and i in badminton and i in footboll:
                  all.append(i)
       return(all)
            


n=int(input("Enter total number of student : "))
c=int(input("Enter number of student who play cricker : "))
cricket=[]
badminton=[]
footboll=[]

for i in range(c):
    x=int(input("Enter the roll number : "))
    cricket.append(x)

print(" ")
b=int(input("Enter the number of student who play bad : "))
for i in range(b):
    x=int(input("Enter the roll number : "))
    badminton.append(x)

print(" ")

f=int(input("Enter the number of student who play footboll : "))
for i in range(f):
    x=int(input("Enter the roll number : "))
    footboll.append(x)
    
print(" ")

print("List of students who play both cricket and badminton: ", cb(cricket,badminton,n))
print("List of students who play either cricket or badminton but not both",corb(cricket,badminton,n))

print(" Number of students who play neither cricket nor badminton: ",ncnb(cricket,badminton,n))

print(" Number of students who play cricket and football but not badminton. ",cfnb(cricket,footboll,badminton,n))
print("Number of students who do not play any game ",nogame(cricket,badminton,footboll,n))
print(" List of students who play at least one game ",atleast(cricket,badminton,footboll,n))
print("List of students who play all three games. ",all(cricket,badminton,footboll,n))

