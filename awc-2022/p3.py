def gen_grid(n, flip):
    grid = [['R']*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if (i+j)%2 == flip:
                grid[i][j] = 'B'
    return grid
               
def get_ftt(freq, k):
    cur = 0
    fours = 0
    threes = 0
    twos = 0
    while cur <= k-4 and fours < freq[4]:
        cur += 4
        fours += 1
    while cur <= k-3 and threes < freq[3]:
        cur += 3
        threes += 1
    while cur <= k-2 and twos < freq[2]:
        cur += 2
        twos += 1
        
    if cur == k:
        return fours, threes, twos
    
    if k - cur == 2:
        if fours >= 1 and freq[3] - threes >= 2:
            fours -= 1
            threes += 2
    elif k - cur == 1:
        if fours and freq[3] - threes and freq[2] - twos:
            fours -= 1
            threes += 1
            twos += 1
        elif fours >= 2 and freq[3] - threes >= 3:
            fours -= 2
            threes += 3
        elif threes >= 1 and freq[2] - twos >= 2:
            threes -= 1
            twos += 2
    return fours, threes, twos
            
 
def solve(grid, x):
    c = [-1, 0, 1, 0]
    r = [0, -1, 0, 1]
    freq = {2:0, 3:0, 4:0}
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 'R':
                off = 0
                for k in range(4):
                    nr = i + r[k]            
                    nc = j + c[k]
                    if nr >= 0 and nr < n and nc >= 0 and nc < n:
                        off += 1
                freq[off] += 1    
    fours, threes, twos = get_ftt(freq, x)
    if 4*fours + 3*threes + 2*twos != x:
        return 0
    print("Possible")
    freq = {4:fours, 3:threes, 2:twos}
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 'R':
                off = 0
                for k in range(4):
                    nr = i + r[k]            
                    nc = j + c[k]
                    if nr >= 0 and nr < n and nc >= 0 and nc < n:
                        off += 1
                if freq[off] > 0:
                    freq[off] -= 1   
                else:
                    grid[i][j] = 'B' 
        print("".join(grid[i]))
    return 1
    
    
    

for _ in range(int(input())):
    n, k = map(int, input().split())
    if n == 1:
        if k == 0:
            print("Possible")
            print('R')
        else:
            print("Impossible")
        continue
    elif n == 3 and k in (5, 7):
        if k == 5:
            print("Possible")
            print("RRR\nBBB\nRBB")
        elif k == 7:
            print("Possible")
            print("RRR\nBBB\nRBR")
        continue
    grid = gen_grid(n, 0)
    if solve(grid, k):
        continue
             
    # print(grid)
    grid = gen_grid(n, 1)
    if solve(grid, k):
        continue
    print("Impossible")
    # print(grid)