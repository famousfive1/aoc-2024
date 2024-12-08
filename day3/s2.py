import re

s = input()

exp = "mul\\([0-9]{1,3},[0-9]{1,3}\\)|don\\'t|do"

inss = re.findall(exp, s)

sum = 0
en = True
for ins in inss:
    if ins == "don't":
        en = False
        continue
    if ins == "do":
        en = True
        continue
    if en:
        ins = ins[4:]
        ins = ins[:-1]
        a, b = ins.split(',')
        sum += int(a) * int(b)

print(sum)
