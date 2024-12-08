import re

s = input()

exp = "mul\\([0-9]{1,3},[0-9]{1,3}\\)"

inss = re.findall(exp, s)

sum = 0

for ins in inss:
    ins = ins[4:]
    ins = ins[:-1]
    a, b = ins.split(',')
    sum += int(a) * int(b)

print(sum)
