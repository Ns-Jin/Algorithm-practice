a = [-1,-2,-3,-4,-5,-6,1,2,3,4,5,6]
b = [-1,-2,-3,-4,-5,-6,1,2,3,4,5,6]
c = []

for i in a:
    for j in b:
        if i*j not in c:
            c.append(i*j)

print(len(c))
print(c)