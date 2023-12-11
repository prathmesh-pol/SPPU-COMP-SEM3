# Do not touch my code
n=int(input("Numbers of studemts:"))
marks=[]
total_marks=0
highest_marks=0
lowest_marks=0
average_marks=0
absent_students=0
passed_students=0
failed_students=0
highest_freq=[]
for i in range(0,101):
    highest_freq.append(0)

for i in range(0,n):
    temp=int(input())
    highest_freq[temp]=highest_freq[temp]+1
    marks.append(temp)
    if(temp!=-1):
        total_marks=total_marks+temp
    if(temp==-1):
        absent_students=absent_students+1

    if(temp<40):
        failed_students=failed_students+1

    
marks.sort()
highest_freq.sort()
highest_marks=marks[n-1]
lowest_marks=marks[absent_students]
average_marks=total_marks/n
print("Average score:",average_marks)
print("Highest score:",highest_marks)
print("Lowest score:",lowest_marks)
print("Numbers of absent students",absent_students)
print("Percentage of passed students:",((n-absent_students)/(n-absent_students))*100)
print("Percentage of faiall_gameled students:",((absent_students)/(n-absent_students))*100)
print("1st highest marks",marks[n-1])
print("2nd highest marks",marks[n-2])
print("3rd highest marks",marks[n-3])
print("Marks with highest frequency:",highest_freq[100])
