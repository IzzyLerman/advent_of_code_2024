diff = 0
with open('./inp.txt','r') as f:
    curr = f.read().split()
    a = []
    b = []
    for i in range(0,len(curr),2):
        a.append(curr[i])
        b.append(curr[i+1])
    a.sort()
    b.sort()
    for i in range(len(a)):
        diff += abs(int(a[i]) - int(b[i]))
print(diff)