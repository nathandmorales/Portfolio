
#Function to check if a number is a float
def isFloat(num):
    try:
        float(num)
        return True
    except:
        return False

#Function that handles finding the most frequent k numbers takes k as input and a file for input
def TopFreqNums (k, file):
    output = open("freqnumber.txt", 'a')
    #Create 1 dictionary for integers key will be the integer and the value for the key will be the frequency
    Nums = {

    }

    #Create a second dictionary that acts the same as the first but handles non real numbers
    Nums2 = {

    }

    for line in file:
        linesList = line.split()
        for l in linesList:
            if l.isdigit() and int(l) in Nums or l.lstrip('-').isdigit() and int(l) in Nums:
                Nums[int(l)] += 1
            elif l.isdigit() and not int(l) in Nums or l.lstrip('-').isdigit() and not int(l.lstrip('-') in Nums):
                Nums[int(l)] = 1
            elif isFloat(l) and float(l) in Nums2 or isFloat(l.lstrip('-')) and float(l) in Nums2:
                Nums2[float(l)] += 1
            elif isFloat(l) and not float(l) in Nums2 or isFloat(l.lstrip('-')) and not float(l) in Nums2:
                Nums2[float(l)] = 1

    print("Integer Dict before mutating...")
    print(Nums)
    output.write("Integers:" + '\n')
    for num in range(k):
        print(str(max(Nums, key=Nums.get)) + "    " + str(Nums.get(max(Nums, key=Nums.get))))
        output.write(str(max(Nums, key=Nums.get)) + "    " + str(Nums.get(max(Nums, key=Nums.get))) + '\n')
        del Nums[max(Nums, key=Nums.get)]

    print("Integer Dict after mutating...")
    print(Nums)


    print("Float Dict before mutating...")
    print(Nums2)
    output.write("Reals: " + '\n')
    for num in range(k):
        print(str(max(Nums2, key=Nums2.get)) + "    " + str(Nums2.get(max(Nums2, key=Nums2.get))))
        output.write(str(max(Nums2, key=Nums2.get)) + "    " + str(Nums2.get(max(Nums2, key=Nums2.get))) + '\n')
        del Nums2[max(Nums2, key=Nums2.get)]

    print("Float Dict after mutating...")
    print(Nums2)

















if __name__ == '__main__':
    file = open("file.txt", 'r')
    TopFreqNums(2, file)







