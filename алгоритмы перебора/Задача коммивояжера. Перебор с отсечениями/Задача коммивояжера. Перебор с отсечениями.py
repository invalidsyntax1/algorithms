def count(p):
    global a
    sum = 0
    for i in range(0, len(p)):
        if (i)== 0:
            sum+=a[0][p[i]]
            #print ("из первого города во второй - " + str(a[0][p[i]]))
        elif (i) == len(p):
            sum+=a[p[i]][0]
            #print ("из предпоследнего города в последний - " + str(a[p[i]][0]))
        else:
            sum+=a[p[i-1]][p[i]]
            #print ("из промежуточного города в промежуточный - " + str(a[p[i-1]][p[i]]))
    #print ("из предпоследнего города в последний - " + str(a[p[len(p)-1]][0]))
    sum += a[p[len(p)-1]][0]
    return sum

#print(count([2,1,3])) - для проверки )

#Функция сравнения ans и вновь вычисленного пути из того или иного перебора
def minForAns(count, p):
    global ans
    global res
    if count < ans:
        ans = count
        res = []
        res.append(p)
    elif count == ans:
        res.append(p)
    return ans

def rec(idx):
    global p
    if idx == n-1:
#        print("Путь торговца по городам: " + "0->" + '->'.join(map(str,p)) + "->0")
#        print("     Рассчитанная дальность: " + str(count(p)) + " (минимальная дальность: " + str(minForAns(count(p))) + ")")
        minForAns(count(p), p)
        return
    for i in range(1, n):
        if used[i]:
            continue
        p[idx]=i
        used[i]=True
        rec(idx+1)
        used[i]=False

a = list()
n = int(input())
for i in range(n):
    a.append(list(map(int, input().split())))
    
#Матрица для хранения текущей перестановки
p = [0 for i in range(n-1)]
#Матрица False
used = [False for i in range(n+1)]

res = [] # список для хранения результатов

#Получим длину пути, а чтобы она была максимально большой из возможных - просто просуммируем всё содержимое
ans = 0
for i in range(0, n):
    for j in range(0, n):
        ans += a[i][j]
rec(0)

print(f"Минимальная длина = {ans}, достигнута на", end = ' ')
if len(res) == 1:
    print(f"пути {'->'.join(map(str,res[0]))}")
else:
    print(f"путях:")
    for i in range(len(res)):
        print("0->" + '->'.join(map(str, res[i])) + "->0")