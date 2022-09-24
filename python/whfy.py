from sys import stdin

file_data = [48733, -1, 0, 2, -2, 5, 0, 3, 1, 0, 1, -1]

n = []
n.append(file_data[0])
i=1
while i<len(file_data):
    if i + 1 < len(file_data) and file_data[i] == 0:
        zero_count = file_data[i+1]
        for j in range(zero_count):
            n.append(n[-1])
        i += 1
    elif file_data[i] == 0 and i + 1 == len(file_data):
        n.append(n[-1])
    else:
        temp = n[-1] + file_data[i]
        n.append(temp)
    i += 1

for i in range(20):
    command = stdin.readline().split()
    
    if command[0] == 'T':
        order = int(command[1])
        if order >= 1 and order <= len(n):
            print(n[order-1])
        else:
            print(-1)
    
    elif command[0] == 'M':
        start_area = int(command[1])
        end_area = int(command[2])
        
        if end_area >= len(n):
            print(-1)
        else:
            temp = n[start_area-1:end_area]
            print(min(temp), max(temp))