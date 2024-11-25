def bin_add():
    
    for ch in x:
        print(ch)

def check_binary(x):
    l1= []
    for ch in x:
        if (ch!='0' and ch!='1'):
            print('not a binary number')
            break
        else:
            l1.append(ch)
    print(l1[::-1])   
x= input("Enter a binary no - ")
check_binary(x)
