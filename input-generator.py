from random import randint

pointCount = int(input("Enter the point count: "))
setCount = int(input("Enter the number of sets: "))

outFile = open("input.txt", 'w+')

outFile.write(str(pointCount) + '\n')
outFile.write(str(setCount) + '\n')

for i in range(pointCount):
    outFile.write(str(randint(-1000, 1000)) + " " + str(randint(-1000, 1000)) + " " + str(randint(-1000, 1000)) + "\n")
print("Input generated.")