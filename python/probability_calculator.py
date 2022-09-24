from sys import stdin
import math

def facto(a):
    return math.factorial(a)

def perm(a,b):
    return math.perm(a,b)

def comb(a,b):
    return math.comb(a,b)


a = 0.0
for i in range(5,31):
    a += 1.0/(i+10)*1/30

print((1/30*1/30)/a)