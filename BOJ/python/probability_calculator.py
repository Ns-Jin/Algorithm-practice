from sys import stdin
import math

def facto(a):
    return math.factorial(a)

def perm(a,b):
    return math.perm(a,b)

def comb(a,b):
    return math.comb(a,b)


a = 0.01
for i in range(5,31):
    a += 1.0/(i+10)*1/30

result = 0;
for i in range(3,7):
    for j in range(3,7):
        if i != j:
            result = result + comb(i-1,2)*comb(j-1,2)
            
print(comb(14,5))