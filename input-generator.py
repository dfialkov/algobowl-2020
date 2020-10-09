from random import randInt

pointCount = int(input("Enter the point count: "))
setCount = int(nput("Enter the number of sets: "))

outFile = open("input.txt", 'rw+')

outFile.write(str(pointCount) + '\n')
outFile.write(str(setCount) + '\n')

for i in range(pointCount):
    outFile.write(randInt(-1000, 1000) + " " + randInt(-1000, 1000) + " " + randInt(-1000, 1000) + "\n")
print("Input generated.")