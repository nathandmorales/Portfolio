
#Function to check if a number is a float
def isFloat(num):
    try:
        float(num)
        return True
    except:
        return False


def findNums(list, freqList, output, counter):
    if counter > 0:
        print(str(list[freqList.index(max(freqList))]) + "    " + str(max(freqList)))
        output.write(str(list[freqList.index(max(freqList))]) + "    " + str(max(freqList)) + '\n')
        list.pop(freqList.index(max(freqList)))
        freqList.remove(max(freqList))
        return findNums(list, freqList, output, counter - 1)
    else:
        print()



#Function that handles finding the most frequent k numbers takes k as input and a file for input
def TopFreqNums (k, file, outputName):
    output = open(outputName, 'a')
    #Create a list for integers and the second for its corresponding frequency
    intList = []
    intFreqList = []

    #Create a 3rd and 4th list for reals and their corresponding frequencies
    realList = []
    realFreqList = []

    #I use a double for loop to take input and assign it to the lists. one loop for every line and a second loop for every word in that line
    for line in file:
        linesList = line.split()
        for l in linesList:
            if l.isdigit() and int(l) in intList or l.lstrip('-').isdigit() and int(l) in intList:
                intFreqList[intList.index(int(l))] += 1
            elif l.isdigit() and not int(l) in intList or l.lstrip('-').isdigit() and not int(l.lstrip('-') in intList):
                intList.append(int(l))
                intFreqList.append(1)
            elif isFloat(l) and float(l) in realList or isFloat(l.lstrip('-')) and float(l) in realList:
                realFreqList[realList.index(float(l))] += 1
            elif isFloat(l) and not float(l) in realList or isFloat(l.lstrip('-')) and not float(l) in realList:
                realList.append(float(l))
                realFreqList.append(1)

    print(intList)
    print(intFreqList)

    output.write("integers:" + '\n')
    findNums(intList, intFreqList, output, k)

    print(intList)
    print(intFreqList)

    print(realList)
    print(realFreqList)

    output.write("reals: " + '\n')
    findNums(realList, realFreqList, output, k)

    print("Float List after mutating...")
    print(realList)
    print(realFreqList)

















if __name__ == '__main__':
    k = input("Enter k value: ")
    while not k.isdigit():
        print("Invalid input for k please type an integer...")
        k = input("Enter k value: ")
    fileName = input("Enter Input File Name: ")
    outputName = input("Enter Output File Name: ")
    file = open(fileName, 'r')
    k = int(k)
    TopFreqNums(k, file, outputName)







