import random

times = 1000000
file = open("testCase.txt",'w+',encoding="utf8")

file.writelines(f'{str(times)}\n')

randomList=[[int(random.random()*100000),int(random.random()*100000)] for i in range(5)]

inputList=[]

for i in range(times):
    temp=int(random.random()*10000000)
    inputList.append(temp)
    file.write(f'{str(temp)} ')
file.writelines("\n")

output=open("testOutput","w+",encoding='utf8')

for L in randomList:
    file.write(f'{str(inputList[L[0]]+inputList[L[1]])}\n')
    output.write(f'{str(inputList[L[0]])} {str(inputList[L[1]])}\n')

file.close()
output.close()