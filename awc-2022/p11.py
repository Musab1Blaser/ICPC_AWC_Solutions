n, d = map(int, input().split())

vals = [0]
i = d
while len(vals) < 6:
    i += 1
    for v in vals:
        if (i^v) % d:
            break
    else:
        vals.append(i)
        
for i in range(n):
    print(*vals)