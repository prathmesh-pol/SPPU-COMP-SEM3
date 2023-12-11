marks=[]
n=int(input("Enter the number of students to enter marks"))

print("Enter Marks : \n")
for i in range(n):
    temp=int(input())
    marks.append(temp)
 
 
# selection sort -------------------------------
   
def selection(marks):
    for i in range (len(marks)):
        min=i
        for j in range (i,len(marks)):
            if(marks[j]<marks[min]):
                min=j
            
        marks[i],marks[min]=marks[min],marks[i]
    print(marks)
    
# selection(marks)

#  insertion sort -------------------------------

def insertion(marks):
    for i in range (len(marks)):
        j=i
        while(j>0 and marks[j-1]>marks[j]):
            marks[j-1],marks[j]=marks[j],marks[j-1]
            j=j-1
    
    print(marks)
    
    
insertion(marks)