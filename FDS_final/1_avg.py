# Problem Statement: Write a Python program to store marks scored in the subject 
# “Fundamental of Data Structure” by N students in the class. Write functions to 
# compute the following: 
# a) The average score of the class 
# b) Highest score and lowest score of class 
# c) Count of students who were absent for the test 
# d) Display  mark with highest frequency 
# e) Percentages of passed and failed students 
# f) Find the top three highest scores.
# Instructions:
# • Take marks of at least 10 students' marks as input.
# • Use lists for storing marks
# • Don’t use python built-in function

def avg(a,n):
       sum=0
       pre=0
       for i in range(n):
             if a[i]!=-1 and a[i]>-1:
                   sum+=a[i]
                   pre+=1
       return sum/pre

def hig_low(a,n):
       max=0
       min=100
       for i in range(n):
             if a[i]>max:
                   max=a[i]
             if a[i]<min and a[i]!=-1:
                   min=a[i]
       return print("Highest score and lowest score of class",max,min)

def absent(a,n):
      abs=0
      for i in range(n):
            if a[i]==-1:
                  abs+=1
      return abs            

def highfeq(a,n):
      cnt=[0]*100
      for i in range(n):
            if(a[i]!=-1):
                cnt[a[i]]+=1
      max=0
      mar=0
      for i in range(99):
            if cnt[i]>max:
                max=cnt[i]
                mar=i
      return print("marks : ",mar, "freq", max)

def pass_fail(n,a):
      pas=0
      fail=0
      for i in range(n):
            if a[i]>=33:
                  pas+=1
            else:
                  fail+=1
      return print("% of pass & fail student :","pass %: ",(pas*100)/n,"  Fail % : ",(fail*100)/n)
      

def top(a,n):
      max1=0
      max2=0
      max3=0
      for i in range(0,n):
            if a[i]>max1:
                  max1=a[i]
      for i in range(0,n):
            if a[i]>max2  and a[i]!=max1:
                  max2=a[i]
      for i in range(0,n):
            if a[i]>max3  and a[i]!=max1 and a[i]!=max2:
                  max3=a[i]
      return print("top three higest score marks : ","Max1: ",max1,"Max2: ",max2,"Max3: ",max3)
    
      
            

n=int(input("Enter number of student : "))
a=[]
print(" ")
print("Now enter the marks of , if student is absent enter -1 ")
for i in range(n):
    x=int(input("Enter the marks of student : "))
    a.append(x)

print("Average marks of student : ",avg(a,n))
print(hig_low(a,n))
print("Number of absent ", absent(a,n))
print(highfeq(a,n))
print(pass_fail(n,a))
print(top(a,n) )


