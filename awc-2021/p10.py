def solve(grid):
    lim = max(1, (len(grid)*len(grid))//7 - 35) 
    if n <= 8:
        for i in range(n):
            for j in range(i):
                for l in range(n-1):
                    for k in range(1, n-l):
                        if grid[i][l] == grid[j][l] == grid[i][l+k] == grid[j][l+k]:
                            print(i+1, l+1, j+1, l+1, i+1, l+k+1, j+1, l+k+1)
    else:
        ans = []
        mapper = {0:(0, 1), 1: (1, 2), 2: (0, 2), 3:(0, 1), 4:(0, 1), 5:(0, 2), 6:(1, 2), 7:(0, 1), 8:(0, 1)}
        for i in range(0, n-3, 3):
            prev = {}
            for j in range(n):
                cur = grid[i][j] + grid[i+1][j]*2 + grid[i+2][j]*4
                if cur in prev:
                    ans.append((prev[cur], j))
                    del prev[cur]
                else:
                    prev[cur] = (j, [i + x for x in mapper[cur]])
        for a in ans[:lim]:
            p1 = (a[0][1][0]+1, a[0][0]+1)
            p2 = (a[0][1][1]+1, a[0][0]+1)
            p3 = (a[0][1][0]+1, a[1]+1)
            p4 = (a[0][1][1]+1, a[1]+1)
            print(*p1, *p2, *p3, *p4)
    


for _ in range(int(input())):
    n = int(input())
    grid = []
    for i in range(n):
        grid.append(list(map(lambda x : x=='W', input())))
    solve(grid)
    # print(grid)