def fibonacci(num):
    tf = int(input("enter the number to be searched"))
    nu = len(num)
    num.sort()
    m2 = 0
    m1 = 1
    m = 1
    while(m<nu):
        m2 = m1
        m1 = m
        m = m1 + m2
    
    offset = 0
    call = 0
    while(m>1):
        i = min(offset+m2, nu-1)
        if (tf == num[i]):
            call = 1
            break
        elif(tf > num[i]):
            m = m1
            m1 = m2
            m2 = m-m1
            offset = i
        elif(tf < num[i]):
            m = m2
            m1 = m1- m2
            m2 = m -m1    
    if(call == 0):
        print("number was not present")
    else:
        print("number was present")