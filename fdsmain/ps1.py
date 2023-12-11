# Assumeing the passing persentage as 40% and total marks as 100 

n=int(input("Enter the total no of students"))
total=n
print("Enter the marks of students, \n Enter -1 if the student is absent \n")
list=[]
freq=[]
for i in range (100):
    s=int(0)
    freq.append(s)
sum=0
max=0
index=0
fail=0
h_freq=0
min=100
absent=0
max2=0
max3=0
for i in range(n):
    a=int(input())
    freq[a]=freq[a]+1
    list.append(a)
    
    if(a>0):
        sum=sum+a
        if(a<40):
            fail+=1
    if(a>0): 
        if(a>max3):
            max3=max2
            
            if(a>max):
                max2=max
                max=a
        if(a<=min):
            min=a
            
    if(a<0): 
        absent+=1
        total-=1
avg=sum/total
for i in range(100):
    if(freq[i]>=h_freq):
        h_freq=freq[i]
        index=i
per_failed=((absent+fail)/n)*100


print("Average Marks =", avg)
print("Total Marks =", sum)
print("Heighest Marks : ", max)
print("Lowest marks = ",min)
print("Absent Students = ",absent)
print("Failed students = ",fail)
print("Persent failed =", per_failed)
print("Persent passed =", 100-per_failed)

print("Marks with heightes freq = ",index)
print("Top 3 marks : \n",max ,"\n",max2 ,"\n",max3)

        
    