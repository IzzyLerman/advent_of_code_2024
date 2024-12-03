from collections import defaultdict

score = 0
with open('./inp.txt','r') as f:
    lists = f.read().split()
    a = []
    b = []
    occur = defaultdict(int)
    for i in range(0,len(lists),2):
        a.append(int(lists[i]))
        b.append(int(lists[i+1]))
    for n in b:
        occur[n] += 1
    for n in a:
        score += n * occur[n]
print(score)