import random

times = 10
file = open("testCase.txt", "w+", encoding="utf8")

file.writelines(f"{str(times)}\n")

randomList = [
    [int(random.random() * times), int(random.random() * times)] for i in range(5)
]

inputList = []

for i in range(times):
    temp = int(random.random() * 100000)
    inputList.append(temp)
    file.write(f"{str(temp)} ")
file.writelines("\n")

output = open("testOutput", "w+", encoding="utf8")

for L in randomList:
    file.write(f"{str(inputList[L[0]]+inputList[L[1]])}\n")
    output.write(f"{str(inputList[min(L[0],L[1])])} {str(inputList[max(L[1],L[0])])}\n")
output.write("\n");

for L in randomList:
    output.write(f"{str(min(L[0],L[1]))} {str(max(L[1],L[0]))}\n")


file.close()
output.close()
