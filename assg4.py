def genStrings(set, k): 
  
    n = len(set)  
    createString(set, "", n, k)


def isValid(string):
    i = count = size = 0
    size = len(string)
    stringArr = list(string)

    while i < size-2:
        if stringArr[i]=='a' and stringArr[i+1]=='b' and stringArr[i+2]=='c':
            count+=1
        i+= 1

    if count==1:
        print(count)
        global counter
        counter+=1


def createString(set, prefix, n, k): 
      
    if (k == 0) : 
        print(prefix) 
        isValid(prefix)
        return
  
    for i in range(n): 
  
        newPrefix = prefix + set[i] 
          
        createString(set, newPrefix, n, k - 1)
 
counter = 0

if __name__ == "__main__": 
    set2 = ['a', 'b', 'c', 'd'] 
    k = 4
    genStrings(set2, k) 
    print(counter)
